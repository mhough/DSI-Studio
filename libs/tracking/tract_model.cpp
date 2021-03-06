//---------------------------------------------------------------------------
#include <fstream>
#include <sstream>
#include <iterator>
#include <set>
#include <map>
#include "tract_model.hpp"
#include "tracking_static_link.h"
#include "prog_interface_static_link.h"
#include "mat_file.hpp"
#include "libs/tracking/tracking_model.hpp"
typedef class ReadMatFile MatReader;
typedef class WriteMatFile MatWriter;


struct TrackVis
{
    char id_string[6];//ID string for track file. The first 5 characters must be "TRACK".
    short int dim[3];//Dimension of the image volume.
    float voxel_size[3];//Voxel size of the image volume.
    float origin[3];//Origin of the image volume. This field is not yet being used by TrackVis. That means the origin is always (0, 0, 0).
    short int n_scalars;//Number of scalars saved at each track point (besides x, y and z coordinates).
    char scalar_name[10][20];//Name of each scalar. Can not be longer than 20 characters each. Can only store up to 10 names.
    short int n_properties	;//Number of properties saved at each track.
    char property_name[10][20];//Name of each property. Can not be longer than 20 characters each. Can only store up to 10 names.
    char reserved[508];//Reserved space for future version.
    char voxel_order[4];//Storing order of the original image data. Explained here.
    char pad2[4];//Paddings.
    float image_orientation_patient[6];//Image orientation of the original image. As defined in the DICOM header.
    char pad1[2];//Paddings.
    unsigned char invert[6];//Inversion/rotation flags used to generate this track file. For internal use only.
    int n_count;//Number of tract stored in this track file. 0 means the number was NOT stored.
    int version;//Version number. Current version is 1.
    int hdr_size;//Size of the header. Used to determine byte swap. Should be 1000.
    void init(image::geometry<3> geometry_,const image::vector<3>& voxel_size_)
    {
        id_string[0] = 'T';
        id_string[1] = 'R';
        id_string[2] = 'A';
        id_string[3] = 'C';
        id_string[4] = 'K';
        id_string[5] = 0;
        std::copy(geometry_.begin(),geometry_.end(),dim);
        std::copy(voxel_size_.begin(),voxel_size_.end(),voxel_size);
        //voxel_size
        origin[0] = origin[1] = origin[2] = 0;
        n_scalars = 0;
        std::fill((char*)scalar_name,(char*)scalar_name+200,0);
        n_properties = 0;
        std::fill((char*)property_name,(char*)property_name+200,0);
        std::fill(reserved,reserved+sizeof(reserved),0);
        voxel_order[0] = 'L';
        voxel_order[1] = 'P';
        voxel_order[2] = 'S';
        voxel_order[3] = 0;
        std::copy(voxel_order,voxel_order+4,pad2);
        image_orientation_patient[0] = 1.0;
        image_orientation_patient[1] = 0.0;
        image_orientation_patient[2] = 0.0;
        image_orientation_patient[3] = 0.0;
        image_orientation_patient[4] = 1.0;
        image_orientation_patient[5] = 0.0;
        std::fill(pad1,pad1+2,0);
        std::fill(invert,invert+6,0);
        n_count = 0;
        version = 1;
        hdr_size = 1000;
    }
};

//---------------------------------------------------------------------------
void TractModel::add(const TractModel& rhs)
{
    for(unsigned int index = 0;index < rhs.redo_size.size();++index)
        redo_size.push_back(std::make_pair(rhs.redo_size[index].first + tract_data.size(),
                                           rhs.redo_size[index].second));
    tract_data.insert(tract_data.end(),rhs.tract_data.begin(),rhs.tract_data.end());
    tract_color.insert(tract_color.end(),rhs.tract_color.begin(),rhs.tract_color.end());
    deleted_tract_data.insert(deleted_tract_data.end(),
                              rhs.deleted_tract_data.begin(),
                              rhs.deleted_tract_data.end());
    deleted_tract_color.insert(deleted_tract_color.end(),
                               rhs.deleted_tract_color.begin(),
                               rhs.deleted_tract_color.end());
    deleted_count.insert(deleted_count.begin(),
                         rhs.deleted_count.begin(),
                         rhs.deleted_count.end());
}
//---------------------------------------------------------------------------
bool TractModel::load_from_file(const char* file_name_,bool append)
{
    std::string file_name(file_name_);
    std::vector<std::vector<float> > loaded_tract_data;
    std::vector<unsigned int> loaded_tract_cluster;
    if (file_name.find(".txt") != std::string::npos)
    {
        std::ifstream in(file_name_);
        if (!in)
            return false;
        std::string line;
        in.seekg(0,std::ios::end);
        unsigned int total = in.tellg();
        in.seekg(0,std::ios::beg);
        begin_prog("loading");
        while (std::getline(in,line))
        {
            check_prog(in.tellg(),total);
            loaded_tract_data.push_back(std::vector<float>());
            std::istringstream in(line);
            std::copy(std::istream_iterator<float>(in),
                      std::istream_iterator<float>(),std::back_inserter(loaded_tract_data.back()));
            if (loaded_tract_data.back().size() < 6)
            {
                if(loaded_tract_data.back().size() == 1)// cluster info
                    loaded_tract_cluster.push_back(loaded_tract_data.back()[0]);
                loaded_tract_data.pop_back();
                continue;
            }
        }

    }
    else
        //trackvis
        if (file_name.find(".trk") != std::string::npos)
        {
            TrackVis trk;
            std::ifstream in(file_name_,std::ios::binary);
            if (!in)
                return false;
            in.read((char*)&trk,1000);
            //if (geo != geometry)
            //    ShowMessage("Incompatible image dimension. The tracts may not be properly presented");
            //std::copy(trk.voxel_size,trk.voxel_size+3,vs.begin());
            unsigned int track_number = trk.n_count;
            begin_prog("loading");
            for (unsigned int index = 0;check_prog(index,track_number);++index)
            {
                int n_point;
                in.read((char*)&n_point,sizeof(int));
                unsigned int index_shift = 3 + trk.n_scalars;
                std::vector<float> tract(index_shift*n_point + trk.n_properties);
                in.read((char*)&*tract.begin(),sizeof(float)*tract.size());

                loaded_tract_data.push_back(std::vector<float>());
                loaded_tract_data.back().resize(n_point*3);
                const float *from = &*tract.begin();
                float *to = &*loaded_tract_data.back().begin();
                for (unsigned int i = 0;i < n_point;++i,from += index_shift,to += 3)
                {
                    float x = from[0]/vs[0];
                    float y = from[1]/vs[1];
                    float z = from[2]/vs[2];
                    to[0] = x;
                    to[1] = y;
                    to[2] = z;
                }
                if(trk.n_properties == 1)
                    loaded_tract_cluster.push_back(from[0]);
            }
        }
        else
            return false;

    if (loaded_tract_data.empty())
        return false;
    if (append)
    {
        add_tracts(loaded_tract_data);
        return true;
    }
    if(loaded_tract_cluster.size() == loaded_tract_data.size())
        loaded_tract_cluster.swap(tract_cluster);
    else
        tract_cluster.clear();
    loaded_tract_data.swap(tract_data);
    tract_color.resize(tract_data.size());
    std::fill(tract_color.begin(),tract_color.end(),0);
    deleted_tract_data.clear();
    deleted_tract_color.clear();
    redo_size.clear();
    return true;
}
//---------------------------------------------------------------------------
bool TractModel::save_fa_to_file(const char* file_name,float threshold,float cull_angle_cos)
{
    std::vector<std::vector<float> > data;
    handle->get_tracts_fa(tract_data,threshold,cull_angle_cos,data);
    if(data.empty())
        return false;
    std::ofstream out(file_name,std::ios::binary);
    if (!out)
        return false;
    begin_prog("saving");
    for (unsigned int i = 0;check_prog(i,data.size());++i)
    {
        std::copy(data[i].begin(),data[i].end(),std::ostream_iterator<float>(out," "));
        out << std::endl;
    }
    return true;
}

//---------------------------------------------------------------------------
bool TractModel::save_data_to_file(const char* file_name,const std::string& index_name)
{
    std::vector<std::vector<float> > data;
    handle->get_tracts_data(tract_data,index_name,data);
    if(data.empty())
        return false;
    std::ofstream out(file_name,std::ios::binary);
    if (!out)
        return false;
    begin_prog("saving");
    for (unsigned int i = 0;check_prog(i,data.size());++i)
    {
        std::copy(data[i].begin(),data[i].end(),std::ostream_iterator<float>(out," "));
        out << std::endl;
    }
    return true;
}
//---------------------------------------------------------------------------
bool TractModel::save_tracts_to_file(const char* file_name_)
{
    std::string file_name(file_name_);
    if (file_name.find(".txt") != std::string::npos)
    {
        std::ofstream out(file_name_,std::ios::binary);
        if (!out)
            return false;
        begin_prog("saving");
        for (unsigned int i = 0;check_prog(i,tract_data.size());++i)
        {
            std::copy(tract_data[i].begin(),
                      tract_data[i].end(),
                      std::ostream_iterator<float>(out," "));
            out << std::endl;
        }
        return true;
    }
    else
        if (file_name.find(".trk") != std::string::npos)
        {
            std::ofstream out(file_name_,std::ios::binary);
            if (!out)
                return false;
            {
                TrackVis trk;
                trk.init(geometry,vs);
                trk.n_count = tract_data.size();
                out.write((const char*)&trk,1000);
            }
            begin_prog("saving");
            for (unsigned int i = 0;check_prog(i,tract_data.size());++i)
            {
                int n_point = tract_data[i].size()/3;
                std::vector<float> buffer(tract_data[i].size());
                const float *from = &*tract_data[i].begin();
                const float *end = from + tract_data[i].size();
                float* to = &*buffer.begin();
                for (unsigned int flag = 0;from != end;++from,++to)
                {
                    *to = (*from)*vs[flag];
                    ++flag;
                    if (flag == 3)
                        flag = 0;
                }
                out.write((const char*)&n_point,sizeof(int));
                out.write((const char*)&*buffer.begin(),sizeof(float)*buffer.size());
            }
            return true;
        }
    return false;
}

//---------------------------------------------------------------------------
bool TractModel::save_all(const char* file_name_,const std::vector<TractModel*>& all)
{
    if(all.empty())
        return false;
    std::string file_name(file_name_);
    if (file_name.find(".txt") != std::string::npos)
    {
        std::ofstream out(file_name_,std::ios::binary);
        if (!out)
            return false;
        begin_prog("saving");
        for(unsigned int index = 0;index < all.size();++index)
        for (unsigned int i = 0;check_prog(i,all[index]->tract_data.size());++i)
        {
            std::copy(all[index]->tract_data[i].begin(),
                      all[index]->tract_data[i].end(),
                      std::ostream_iterator<float>(out," "));
            out << std::endl;
            out << index << std::endl;
        }
        return true;
    }
    else
        if (file_name.find(".trk") != std::string::npos)
        {
            std::ofstream out(file_name_,std::ios::binary);
            if (!out)
                return false;
            {
                TrackVis trk;
                trk.init(all[0]->geometry,all[0]->vs);
                trk.n_count = 0;
                trk.n_properties = 1;
                for(unsigned int index = 0;index < all.size();++index)
                    trk.n_count += all[index]->tract_data.size();
                out.write((const char*)&trk,1000);

            }
            begin_prog("saving");
            for(unsigned int index = 0;index < all.size();++index)
            for (unsigned int i = 0;check_prog(i,all[index]->tract_data.size());++i)
            {
                int n_point = all[index]->tract_data[i].size()/3;
                std::vector<float> buffer(all[index]->tract_data[i].size()+1);
                const float *from = &*all[index]->tract_data[i].begin();
                const float *end = from + all[index]->tract_data[i].size();
                float* to = &*buffer.begin();
                for (unsigned int flag = 0;from != end;++from,++to)
                {
                    *to = (*from)*all[index]->vs[flag];
                    ++flag;
                    if (flag == 3)
                        flag = 0;
                }
                buffer.back() = index;
                out.write((const char*)&n_point,sizeof(int));
                out.write((const char*)&*buffer.begin(),sizeof(float)*buffer.size());
            }
            return true;
        }
    return false;
}
//---------------------------------------------------------------------------
bool TractModel::save_transformed_tracts_to_file(const char* file_name,const float* transform,bool end_point)
{
    std::vector<std::vector<float> > new_tract_data(tract_data);
    for(unsigned int i = 0;i < tract_data.size();++i)
        for(unsigned int j = 0;j < tract_data[i].size();j += 3)
        image::vector_transformation(&(new_tract_data[i][j]),
                                    &(tract_data[i][j]),transform,image::vdim<3>());
    bool result = true;
    if(end_point)
        save_end_points(file_name);
    else
        result = save_tracts_to_file(file_name);
    new_tract_data.swap(tract_data);
    return result;
}
//---------------------------------------------------------------------------
bool TractModel::load_tracts_color_from_file(const char* file_name)
{
    std::ifstream in(file_name);
    if (!in)
        return false;
    std::vector<int> colors;
    std::copy(std::istream_iterator<int>(in),
              std::istream_iterator<int>(),
              std::back_inserter(colors));
    std::copy(colors.begin(),
              colors.begin()+std::min(colors.size(),tract_color.size()),
              tract_color.begin());
    return true;
}
//---------------------------------------------------------------------------
bool TractModel::save_tracts_color_to_file(const char* file_name)
{
    std::ofstream out(file_name);
    if (!out)
        return false;
    std::copy(tract_color.begin(),
              tract_color.end(),
              std::ostream_iterator<int>(out," "));
    return out;
}

//---------------------------------------------------------------------------
/*
bool TractModel::save_data_to_mat(const char* file_name,int index,const char* data_name)
{
    MatWriter mat_writer(file_name);
    if(!mat_writer.opened())
        return false;
    begin_prog("saving");
        for (unsigned int i = 0;check_prog(i,tract_data.size());++i)
    {
        unsigned int count;
        const float* ptr = get_data(tract_data[i],index,count);
        if (!ptr)
            continue;
		std::ostringstream out;
		out << data_name << i;
        mat_writer.add_matrix(out.str().c_str(),ptr,
                              (index != -2 ) ? 1 : 3,
                              (index != -2 ) ? count : count /3);
    }
        return true;
}
*/
//---------------------------------------------------------------------------
void TractModel::save_end_points(const char* file_name_) const
{

    std::vector<float> buffer;
    buffer.reserve(tract_data.size() * 6);
    for (unsigned int index = 0;index < tract_data.size();++index)
    {
        unsigned int length = tract_data[index].size();
        buffer.push_back(tract_data[index][0]);
        buffer.push_back(tract_data[index][1]);
        buffer.push_back(tract_data[index][2]);
        buffer.push_back(tract_data[index][length-3]);
        buffer.push_back(tract_data[index][length-2]);
        buffer.push_back(tract_data[index][length-1]);
    }

    std::string file_name(file_name_);
    if (file_name.find(".txt") != std::string::npos)
    {
        std::ofstream out(file_name_,std::ios::out);
        if (!out)
            return;
        std::copy(buffer.begin(),buffer.end(),std::ostream_iterator<float>(out," "));
    }
    if (file_name.find(".mat") != std::string::npos)
    {
        MatFile write(file_name_);
        write.add_matrix("end_points",(const short*)&*buffer.begin(),3,buffer.size()/3);
    }

}
//---------------------------------------------------------------------------
void TractModel::get_end_points(std::vector<image::vector<3,short> >& points)
{
    for (unsigned int index = 0;index < tract_data.size();++index)
    {
        if (tract_data[index].size() < 3)
            return;
        image::vector<3,float> p1(&tract_data[index][0]);
        image::vector<3,float> p2(&tract_data[index][tract_data[index].size()-3]);
        p1 += 0.5;
        p2 += 0.5;
        points.push_back(image::vector<3,short>(std::floor(p1[0]),std::floor(p1[1]),std::floor(p1[2])));
        points.push_back(image::vector<3,short>(std::floor(p2[0]),std::floor(p2[1]),std::floor(p2[2])));
    }
}
//---------------------------------------------------------------------------
void TractModel::get_tract_points(std::vector<image::vector<3,short> >& points)
{
    for (unsigned int index = 0;index < tract_data.size();++index)
        for (unsigned int j = 0;j < tract_data[index].size();j += 3)
        {
            image::vector<3,short> point;
            point[0] = std::floor(tract_data[index][j]+0.5);
            point[1] = std::floor(tract_data[index][j+1]+0.5);
            point[2] = std::floor(tract_data[index][j+2]+0.5);
            points.push_back(point);
        }
}
//---------------------------------------------------------------------------
void TractModel::select(const image::vector<3,float>& from_dir,const image::vector<3,float>& to_dir,
                        const image::vector<3,float>& from_pos,const image::vector<3,float>& to_pos,
                        std::vector<unsigned int>& selected)
{
    image::vector<3,float> z_axis = from_dir.cross_product(to_dir);
    float view_angle = from_dir*to_dir;
    unsigned int cur_delete_count = 0;
    std::vector<std::vector<float> > new_tract;
    selected.resize(tract_data.size());
    std::fill(selected.begin(),selected.end(),0);


    unsigned int total_track_number = tract_data.size();
    for (unsigned int index = 0;index < total_track_number;++index)
    {
        float angle = 0.0;
        const float* ptr = &*tract_data[index].begin();
        const float* end = ptr + tract_data[index].size();
        for (;ptr < end;ptr += 3)
        {
            image::vector<3,float> p(ptr);
            p -= from_pos;
            float next_angle = z_axis*p;
            if ((angle < 0.0 && next_angle >= 0.0) ||
                    (angle > 0.0 && next_angle <= 0.0))
            {
                p.normalize();
                if (p*from_dir > view_angle &&
                        p*to_dir > view_angle)
                {
                    selected[index] = ptr - &*tract_data[index].begin();
                    break;
                }

            }
            angle = next_angle;
        }
    }
}
//---------------------------------------------------------------------------
void TractModel::release_tracts(std::vector<std::vector<float> >& released_tracks)
{
    released_tracks.clear();
    released_tracks.swap(tract_data);
    tract_color.clear();
    redo_size.clear();
}
//---------------------------------------------------------------------------
void TractModel::delete_tracts(const std::vector<unsigned int>& tracts_to_delete)
{
    if (tracts_to_delete.empty())
        return;
    for (unsigned int index = 0;index < tracts_to_delete.size();++index)
    {
        deleted_tract_data.push_back(std::vector<float>());
        deleted_tract_data.back().swap(tract_data[tracts_to_delete[index]]);
        deleted_tract_color.push_back(tract_color[tracts_to_delete[index]]);
    }
    deleted_count.push_back(tracts_to_delete.size());
    // delete all blank tract
    std::vector<unsigned int> index_list(tract_data.size()+1);
    unsigned int new_ptr = 0;
    for (unsigned int index = 0;index < tract_data.size();++index)
    {
        index_list[index] = new_ptr;
        if (!tract_data[index].empty())
        {
            if(new_ptr != index)
            {
                tract_data[new_ptr].swap(tract_data[index]);
                std::swap(tract_color[new_ptr],tract_color[index]);
            }
            ++new_ptr;
        }
    }
    index_list.back() = new_ptr;
    tract_data.resize(new_ptr);
    // update redo_size

    for (unsigned int index = 0;index < redo_size.size();)
    {
        unsigned int from = index_list[redo_size[index].first];
        unsigned int size = index_list[redo_size[index].first+redo_size[index].second]-from;
        if(size)
        {
            redo_size[index].first = from;
            redo_size[index].second = size;
            ++index;
        }
        else
            redo_size.erase(redo_size.begin()+index);
    }
}
//---------------------------------------------------------------------------
void TractModel::select_tracts(const std::vector<unsigned int>& tracts_to_select)
{
    std::vector<unsigned> selected(tract_data.size());
    for (unsigned int index = 0;index < tracts_to_select.size();++index)
        selected[tracts_to_select[index]] = 1;

    std::vector<unsigned int> not_selected;
    not_selected.reserve(tract_data.size());

    for (unsigned int index = 0;index < selected.size();++index)
        if (!selected[index])
            not_selected.push_back(index);
    delete_tracts(not_selected);

}
//---------------------------------------------------------------------------
void TractModel::cut(const image::vector<3,float>& from_dir,const image::vector<3,float>& to_dir,
                     const image::vector<3,float>& from_pos,const image::vector<3,float>& to_pos)
{
    std::vector<unsigned int> selected;
    select(from_dir,to_dir,from_pos,to_pos,selected);
    std::vector<std::vector<float> > new_tract;
    std::vector<unsigned int> new_tract_color;

    for (unsigned int index = 0;index < selected.size();++index)
        if (selected[index] && tract_data[index].size() > 6)
        {
            new_tract.push_back(std::vector<float>(tract_data[index].begin() + selected[index],tract_data[index].end()));
            new_tract_color.push_back(tract_color[index]);
            tract_data[index].resize(selected[index]);
        }
    for (unsigned int index = 0;index < new_tract.size();++index)
    {
        tract_data.push_back(std::vector<float>());
        tract_data.back().swap(new_tract[index]);
        tract_color.push_back(new_tract_color[index]);
    }
    redo_size.clear();
}
//---------------------------------------------------------------------------
void TractModel::cull(const image::vector<3,float>& from_dir,const image::vector<3,float>& to_dir,
                      const image::vector<3,float>& from_pos,const image::vector<3,float>& to_pos,
                      bool delete_track)
{
    std::vector<unsigned int> selected;
    select(from_dir,to_dir,from_pos,to_pos,selected);
    std::vector<unsigned int> tracts_to_delete;
    tracts_to_delete.reserve(100 + (selected.size() >> 4));
    for (unsigned int index = 0;index < selected.size();++index)
        if (!((selected[index] > 0) ^ delete_track))
            tracts_to_delete.push_back(index);
    delete_tracts(tracts_to_delete);
}
//---------------------------------------------------------------------------
void TractModel::paint(const image::vector<3,float>& from_dir,const image::vector<3,float>& to_dir,
                       const image::vector<3,float>& from_pos,const image::vector<3,float>& to_pos,
                       unsigned int color)
{
    std::vector<unsigned int> selected;
    select(from_dir,to_dir,from_pos,to_pos,selected);
    for (unsigned int index = 0;index < selected.size();++index)
        if (selected[index] > 0)
            tract_color[index] = color;
}

//---------------------------------------------------------------------------
void TractModel::cut_by_mask(const char* file_name)
{
    /*
    std::ifstream in(file_name,std::ios::in);
    if(!in)
        return;
    std::set<image::vector<3,short> > mask(
                  (std::istream_iterator<image::vector<3,short> > (in)),
                  (std::istream_iterator<image::vector<3,short> > ()));
    std::vector<std::vector<float> > new_data;
    for (unsigned int index = 0;check_prog(index,tract_data.size());++index)
    {
        bool on = false;
        std::vector<float>::const_iterator iter = tract_data[index].begin();
        std::vector<float>::const_iterator end = tract_data[index].end();
        for (;iter < end;iter += 3)
        {
            image::vector<3,short> p(std::floor(iter[0]+0.5),
                                  std::floor(iter[1]+0.5),std::floor(iter[2]+0.5));

            if (mask.find(p) == mask.end())
            {
                if (on)
                {
                    on = false;
                    if (new_data.back().size() == 3)
                        new_data.pop_back();
                }
                continue;
            }
            else
            {
                if (!on)
                    new_data.push_back(std::vector<float>());
                new_data.back().push_back(iter[0]);
                new_data.back().push_back(iter[1]);
                new_data.back().push_back(iter[2]);
                on = true;
            }
        }
    }
    tract_data.swap(new_data);*/
}
//---------------------------------------------------------------------------
void TractModel::trim(void)
{
    image::basic_image<unsigned int,3> label(geometry);


    unsigned int total_track_number = tract_data.size();
    unsigned int no_fiber_label = total_track_number;
    unsigned int have_multiple_fiber_label = total_track_number+1;

    unsigned int width = label.width();
    unsigned int height = label.height();
    unsigned int depth = label.depth();
    unsigned int wh = width*height;
    std::fill(label.begin(),label.end(),no_fiber_label);
    for (unsigned int index = 0;index < total_track_number;++index)
    {
        const float* ptr = &*tract_data[index].begin();
        const float* end = ptr + tract_data[index].size();
        for (;ptr < end;ptr += 3)
        {
            int x = std::floor(*ptr+0.5);
            if (x < 0 || x >= width)
                continue;
            int y = std::floor(*(ptr+1)+0.5);
            if (y < 0 || y >= height)
                continue;
            int z = std::floor(*(ptr+2)+0.5);
            if (z < 0 || z >= depth)
                continue;
            unsigned int pixel_index = z*wh+y*width+x;
            if (pixel_index >= label.size())
                continue;
            unsigned int cur_label = label[pixel_index];
            if (cur_label == have_multiple_fiber_label || cur_label == index)
                continue;
            if (cur_label == no_fiber_label)
                label[pixel_index] = index;
            else
                label[pixel_index] = have_multiple_fiber_label;
        }
    }

    std::set<unsigned int> tracts_to_delete;
    for (unsigned int index = 0;index < label.size();++index)
        if (label[index] < total_track_number)
            tracts_to_delete.insert(label[index]);
    delete_tracts((std::vector<unsigned int>(tracts_to_delete.begin(),tracts_to_delete.end())));
}
//---------------------------------------------------------------------------
void TractModel::undo(void)
{
    if (deleted_count.empty())
        return;
    redo_size.push_back(std::make_pair((unsigned int)tract_data.size(),deleted_count.back()));
    for (unsigned int index = 0;index < deleted_count.back();++index)
    {
        tract_data.push_back(std::vector<float>());
        tract_data.back().swap(deleted_tract_data.back());
        tract_color.push_back(deleted_tract_color.back());
        deleted_tract_data.pop_back();
        deleted_tract_color.pop_back();
    }
    deleted_count.pop_back();
}
//---------------------------------------------------------------------------
void TractModel::redo(void)
{
    if(redo_size.empty())
        return;
    std::vector<unsigned int> redo_tracts(redo_size.back().second);
    for (unsigned int index = 0;index < redo_tracts.size();++index)
        redo_tracts[index] = redo_size.back().first + index;
    redo_size.pop_back();
    delete_tracts(redo_tracts);
}
//---------------------------------------------------------------------------
void TractModel::add_tracts(std::vector<std::vector<float> >& new_tract)
{
    tract_data.reserve(tract_data.size()+new_tract.size());
    image::rgb_color def_color(200,100,30);
    for (unsigned int index = 0;index < new_tract.size();++index)
    {
        if (new_tract[index].empty())
            continue;
        tract_data.push_back(std::vector<float>());
        tract_data.back().swap(new_tract[index]);
        tract_color.push_back(def_color);
    }
}
//---------------------------------------------------------------------------
void TractModel::get_density_map(image::basic_image<unsigned int,3>& mapping,
                                 const std::vector<float>& transformation,bool endpoint)
{
    image::geometry<3> geometry = mapping.geometry();
    std::fill(mapping.begin(),mapping.end(),0);
    std::vector<char> buf(geometry.size());
    begin_prog("calculating");
    for (unsigned int i = 0;check_prog(i,tract_data.size());++i)
    {
        std::fill(buf.begin(),buf.end(),0);
        for (unsigned int j = 0;j < tract_data[i].size();j+=3)
        {
            if(j && endpoint)
                j = tract_data[i].size()-3;
            image::vector<3,float> tmp;
            image::vector_transformation(tract_data[i].begin()+j, tmp.begin(),
                transformation, image::vdim<3>());

            int x = std::floor(tmp[0]+0.5);
            int y = std::floor(tmp[1]+0.5);
            int z = std::floor(tmp[2]+0.5);
            if (!geometry.is_valid(x,y,z))
                continue;
            buf[(z*mapping.height()+y)*mapping.width()+x] = 1;
        }
        image::add(mapping.begin(),mapping.end(),buf.begin());
    }
}
//---------------------------------------------------------------------------
void TractModel::get_density_map(
        image::basic_image<image::rgb_color,3>& mapping,
        const std::vector<float>& transformation,bool endpoint)
{
    image::geometry<3> geometry = mapping.geometry();
    image::basic_image<float,3> map_r(geometry),
                            map_g(geometry),map_b(geometry);
    for (unsigned int i = 0;i < tract_data.size();++i)
    {
        const float* buf = &*tract_data[i].begin();
        for (unsigned int j = 3;j < tract_data[i].size();j+=3)
        {
            if(j > 3 && endpoint)
                j = tract_data[i].size()-3;
            image::vector<3,float>  tmp,dir;
            image::vector_transformation(buf+j-3, dir.begin(),
                transformation, image::vdim<3>());
            image::vector_transformation(buf+j, tmp.begin(),
                transformation, image::vdim<3>());
            dir -= tmp;
            dir.normalize();
            int x = std::floor(tmp[0]+0.5);
            int y = std::floor(tmp[1]+0.5);
            int z = std::floor(tmp[2]+0.5);
            if (!geometry.is_valid(x,y,z))
                continue;
            unsigned int ptr = (z*mapping.height()+y)*mapping.width()+x;
            map_r[ptr] += std::fabs(dir[0]);
            map_g[ptr] += std::fabs(dir[1]);
            map_b[ptr] += std::fabs(dir[2]);
        }
    }
    float max_value = 0;
    for(unsigned int index = 0;index < mapping.size();++index)
    {
        float sum = map_r[index]+map_g[index]+map_b[index];
        if(sum > max_value)
            max_value = sum;
    }
    for(unsigned int index = 0;index < mapping.size();++index)
    {
        float sum = map_r[index]+map_g[index]+map_b[index];
        image::vector<3,float> cmap(map_r[index],map_g[index],map_b[index]);
        cmap.normalize();
        cmap *= 255.0*sum/max_value;
        mapping[index] = image::rgb_color(cmap[0],cmap[1],cmap[2]);
    }
}


