#ifndef ODF_TRANSFORMATION_PROCESS_HPP
#define ODF_TRANSFORMATION_PROCESS_HPP
#include <boost/lambda/lambda.hpp>
#include "basic_process.hpp"
#include "basic_voxel.hpp"

class ReadDWIData : public BaseProcess{
public:
    virtual void init(Voxel&) {}
    virtual void run(Voxel& voxel, VoxelData& voxel_data)
    {
        for (unsigned int index = 0; index < voxel.q_count; ++index)
            voxel_data.space[index] = voxel.image_model->dwi_data[index][voxel_data.voxel_index];
    }
    virtual void end(Voxel&,MatFile& mat_writer) {}
};
struct Accumulator
{
    float operator()(const std::vector<float>& odf)
    {
        float sum = std::accumulate(odf.begin(),odf.end(),0.0);
        sum /= ((float)odf.size());
        return sum;
    }
};


struct GeneralizedFA
{
    float operator()(const std::vector<float>& odf)
    {
        float m1 = 0.0;
        float m2 = 0.0;
        std::vector<float>::const_iterator iter = odf.begin();
        std::vector<float>::const_iterator end = odf.end();
        for (;iter != end; ++iter)
        {
            float t = *iter;
            m1 += t;
            m2 += t*t;
        }
        m1 *= m1;
        m1 /= ((float)odf.size());
        if (m2 == 0.0)
            return 0.0;
        return std::sqrt(((float)odf.size())/((float)odf.size()-1.0)*(m2-m1)/m2);
    }
};

struct RemoveIsotropicPart
{
    float operator()(std::vector<float>& odf)
    {
        float min_odf = *std::min_element(odf.begin(),odf.end());
        std::for_each(odf.begin(),odf.end(),boost::lambda::_1 -= min_odf);
        return min_odf;
    }
};

const unsigned int odf_block_size = 20000;
struct OutputODF : public BaseProcess
{
protected:
    std::vector<std::vector<float> > odf_data;
    std::vector<unsigned int> odf_index_map;
public:
    virtual void init(Voxel& voxel)
    {
        odf_data.clear();
        if (voxel.need_odf)
        {
            unsigned int total_count = 0;
            odf_index_map.resize(voxel.image_model->mask.size());
            for (unsigned int index = 0;index < voxel.image_model->mask.size();++index)
                if (voxel.image_model->mask[index])
                {
                    odf_index_map[index] = total_count;
                    ++total_count;
                }
            try
            {
                std::vector<unsigned int> size_list;
                while (1)
                {

                    if (total_count > odf_block_size)
                    {
                        size_list.push_back(odf_block_size);
                        total_count -= odf_block_size;
                    }
                    else
                    {
                        size_list.push_back(total_count);
                        break;
                    }
                }
                odf_data.resize(size_list.size());
                for (unsigned int index = 0;index < odf_data.size();++index)
                    odf_data[index].resize(size_list[index]*(voxel.ti.half_vertices_count));
            }
            catch (...)
            {
                odf_data.clear();
                voxel.need_odf = false;
            }
        }

    }
    virtual void run(Voxel& voxel,VoxelData& data)
    {

        if (voxel.need_odf && data.fa[0] + 1.0 != 1.0)
        {
            unsigned int odf_index = odf_index_map[data.voxel_index];
            std::copy(data.odf.begin(),data.odf.end(),
                      odf_data[odf_index/odf_block_size].begin() + (odf_index%odf_block_size)*(voxel.ti.half_vertices_count));
        }

    }
    virtual void end(Voxel& voxel,MatFile& mat_writer)
    {

        if (!voxel.need_odf)
            return;
        {
            set_title("output odfs");
            for (unsigned int index = 0;index < odf_data.size();++index)
            {
                if (!voxel.odf_deconvolusion)
                    std::for_each(odf_data[index].begin(),odf_data[index].end(),boost::lambda::_1 /= voxel.qa_scaling);
                std::ostringstream out;
                out << "odf" << index;
                mat_writer.add_matrix(out.str().c_str(),&*odf_data[index].begin(),
                                      voxel.ti.half_vertices_count,
                                      odf_data[index].size()/(voxel.ti.half_vertices_count));
            }
            odf_data.clear();
        }

    }
};



struct AccumulateODF : public BaseProcess
{
    std::vector<unsigned int> odf_index_map;
public:
    virtual void init(Voxel& voxel)
    {
        std::vector<std::vector<float> >& odf_data = voxel.template_odfs;

        unsigned int total_count = 0;
        odf_index_map.resize(voxel.image_model->mask.size());
        for (unsigned int index = 0;index < voxel.image_model->mask.size();++index)
            if (voxel.image_model->mask[index])
            {
                odf_index_map[index] = total_count;
                ++total_count;
            }
        if(odf_data.empty())
        {
            std::vector<unsigned int> size_list;
            while (1)
            {
                if (total_count > odf_block_size)
                {
                    size_list.push_back(odf_block_size);
                    total_count -= odf_block_size;
                }
                else
                {
                    size_list.push_back(total_count);
                    break;
                }
            }
            odf_data.resize(size_list.size());
            for (unsigned int index = 0;index < odf_data.size();++index)
                odf_data[index].resize(size_list[index]*(voxel.ti.half_vertices_count));
        }

    }
    virtual void run(Voxel& voxel,VoxelData& data)
    {
        std::for_each(data.odf.begin(),data.odf.end(),boost::lambda::_1 /= voxel.qa_scaling);
        unsigned int odf_index = odf_index_map[data.voxel_index];
        image::add(voxel.template_odfs[odf_index/odf_block_size].begin() + (odf_index%odf_block_size)*(voxel.ti.half_vertices_count),
                   voxel.template_odfs[odf_index/odf_block_size].begin() + (odf_index%odf_block_size+1)*(voxel.ti.half_vertices_count),
                   data.odf.begin());
    }
    virtual void end(Voxel& voxel,MatFile& mat_writer)
    {
    }
};

struct ODFLoader : public BaseProcess
{
    std::vector<unsigned char> index_mapping1;
    std::vector<unsigned int> index_mapping2;
public:
    virtual void init(Voxel& voxel)
    {
        //voxel.qa_scaling must be 1
        voxel.qa_scaling = 1.0;
        index_mapping1.resize(voxel.image_model->mask.size());
        index_mapping2.resize(voxel.image_model->mask.size());
        int voxel_index = 0;
        for(unsigned char i = 0;i < voxel.template_odfs.size();++i)
        {
            for(unsigned int j = 0;j < voxel.template_odfs[i].size();j += voxel.ti.half_vertices_count)
            {
                int k_end = j + voxel.ti.half_vertices_count;
                bool is_odf_zero = true;
                for(int k = j;k < k_end;++k)
                    if(voxel.template_odfs[i][k] != 0.0)
                    {
                        is_odf_zero = false;
                        break;
                    }
                if(!is_odf_zero)
                    for(;voxel_index < index_mapping1.size();++voxel_index)
                        if(voxel.image_model->mask[voxel_index] != 0)
                            break;
                if(voxel_index >= index_mapping1.size())
                    break;
                index_mapping1[voxel_index] = i;
                index_mapping2[voxel_index] = j;
                ++voxel_index;
            }
        }
    }
    virtual void run(Voxel& voxel, VoxelData& data)
    {
        int cur_index = data.voxel_index;
        std::copy(voxel.template_odfs[index_mapping1[cur_index]].begin() +
                  index_mapping2[cur_index],
                  voxel.template_odfs[index_mapping1[cur_index]].begin() +
                  index_mapping2[cur_index]+data.odf.size(),data.odf.begin());

    }
    virtual void end(Voxel& voxel,MatFile& mat_writer)
    {
        if (voxel.need_odf)
        {
            set_title("output odfs");
            for (unsigned int index = 0;index < voxel.template_odfs.size();++index)
            {
                std::ostringstream out;
                out << "odf" << index;
                mat_writer.add_matrix(out.str().c_str(),&*voxel.template_odfs[index].begin(),
                                      voxel.ti.half_vertices_count,
                                      voxel.template_odfs[index].size()/(voxel.ti.half_vertices_count));
            }
        }
    }
};

// for normalization
class RecordQA  : public BaseProcess
{
public:
    virtual void init(Voxel& voxel)
    {
        voxel.qa_map.resize(voxel.dim);
        std::fill(voxel.qa_map.begin(),voxel.qa_map.end(),0.0);
    }
    virtual void run(Voxel& voxel, VoxelData& data)
    {
        voxel.qa_map[data.voxel_index] = data.fa[0];
    }
    virtual void end(Voxel& voxel,MatFile& mat_writer)
    {

    }
};
class RecordFA  : public BaseProcess
{
public:
    virtual void init(Voxel& voxel)
    {
        voxel.fa_map.resize(voxel.dim);
        std::fill(voxel.fa_map.begin(),voxel.fa_map.end(),0.0);
    }
    virtual void run(Voxel& voxel, VoxelData& data)
    {
        voxel.fa_map[data.voxel_index] = data.fa[0];
    }
    virtual void end(Voxel& voxel,MatFile& mat_writer)
    {

    }
};


struct SaveFA : public BaseProcess
{
protected:
    std::vector<float> gfa,iso;
    std::vector<std::vector<float> > fa;
public:
    virtual void init(Voxel& voxel)
    {

        fa.resize(voxel.max_fiber_number);
        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
            fa[index].resize(voxel.dim.size());
        gfa.clear();
        gfa.resize(voxel.dim.size());
        iso.clear();
        iso.resize(voxel.dim.size());
    }
    virtual void run(Voxel& voxel, VoxelData& data)
    {
        iso[data.voxel_index] = data.min_odf;
        gfa[data.voxel_index] = GeneralizedFA()(data.odf);
        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
            fa[index][data.voxel_index] = data.fa[index];
    }
    virtual void end(Voxel& voxel,MatFile& mat_writer)
    {
        set_title("output gfa");
        mat_writer.add_matrix("gfa",&*gfa.begin(),1,gfa.size());

        if(!voxel.odf_deconvolusion)
        {
            voxel.qa_scaling = *std::max_element(iso.begin(),iso.end());
            // scaled to 1mm cubic
            if(voxel.vs[0] != 0.0 &&
               voxel.vs[1] != 0.0 &&
               voxel.vs[2] != 0.0)
            {
                voxel.qa_scaling /= voxel.vs[0];
                voxel.qa_scaling /= voxel.vs[1];
                voxel.qa_scaling /= voxel.vs[2];
            }
            mat_writer.add_matrix("qa_scaling",&voxel.qa_scaling,1,1);
            std::for_each(iso.begin(),iso.end(),boost::lambda::_1 /= voxel.qa_scaling);
            mat_writer.add_matrix("iso",&*iso.begin(),1,iso.size());

            if (voxel.qa_scaling != 0.0)
                for (unsigned int i = 0;i < voxel.max_fiber_number;++i)
                    std::for_each(fa[i].begin(),fa[i].end(),boost::lambda::_1 /= voxel.qa_scaling);

            // cellularity
            int max_fa_index = std::max_element(fa[0].begin(),fa[0].end())-fa[0].begin();
            float ratio = iso[max_fa_index]/fa[0][max_fa_index];
            for(unsigned int index = 0;index < iso.size();++index)
                iso[index] -= fa[0][index]*ratio;
            mat_writer.add_matrix("cell",&*iso.begin(),1,iso.size());
        }

        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
        {
            std::ostringstream out;
            out << index;
            std::string num = out.str();
            std::string fa_str = "fa";
            fa_str += num;
            set_title(fa_str.c_str());
            mat_writer.add_matrix(fa_str.c_str(),&*fa[index].begin(),1,fa[index].size());
        }

        // output normalized qa
        {
            float max_qa = 0.0;
            for (unsigned int i = 0;i < voxel.max_fiber_number;++i)
                max_qa = std::max<float>(*std::max_element(fa[i].begin(),fa[i].end()),max_qa);

            if(max_qa != 0.0)
            for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
            {
                std::for_each(fa[index].begin(),fa[index].end(),boost::lambda::_1 /= max_qa);
                std::ostringstream out;
                out << index;
                std::string num = out.str();
                std::string fa_str = "nqa";
                fa_str += num;
                set_title(fa_str.c_str());
                mat_writer.add_matrix(fa_str.c_str(),&*fa[index].begin(),1,fa[index].size());
            }
        }

    }
};



struct SaveDirIndex : public BaseProcess
{
protected:
    std::vector<std::vector<short> > findex;
public:
    virtual void init(Voxel& voxel)
    {

        findex.resize(voxel.max_fiber_number);
        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
            findex[index].resize(voxel.dim.size());
    }
    virtual void run(Voxel& voxel, VoxelData& data)
    {

        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
            findex[index][data.voxel_index] = data.dir_index[index];
    }
    virtual void end(Voxel& voxel,MatFile& mat_writer)
    {
        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
        {
            std::ostringstream out;
            out << index;
            std::string num = out.str();
            std::string index_str = "index";
            index_str += num;
            set_title(index_str.c_str());
            mat_writer.add_matrix(index_str.c_str(),&*findex[index].begin(),1,findex[index].size());
        }
    }
};


struct SaveDir : public BaseProcess
{
protected:
    std::vector<std::vector<float> > dir;
public:
    virtual void init(Voxel& voxel)
    {

        dir.resize(voxel.max_fiber_number);
        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
            dir[index].resize(voxel.dim.size()*3);
    }
    virtual void run(Voxel& voxel, VoxelData& data)
    {

        unsigned int dir_index = data.voxel_index;
        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
            std::copy(data.dir[index].begin(),data.dir[index].end(),dir[index].begin() + dir_index + dir_index + dir_index);
    }
    virtual void end(Voxel& voxel,MatFile& mat_writer)
    {
        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
        {
            std::ostringstream out;
            out << index;
            std::string num = out.str();
            std::string index_str = "dir";
            index_str += num;
            set_title(index_str.c_str());
            mat_writer.add_matrix(index_str.c_str(),&*dir[index].begin(),1,dir[index].size());
        }
    }
};




struct SearchLocalMaximum
{
    std::vector<std::vector<unsigned short> > neighbor;
    std::map<float,unsigned short,std::greater<float> > max_table;
    void init(Voxel& voxel)
    {

        unsigned int half_odf_size = voxel.ti.half_vertices_count;
        unsigned int faces_count = voxel.ti.faces.size();
        neighbor.resize(voxel.ti.half_vertices_count);
        for (unsigned int index = 0;index < faces_count;++index)
        {
            short i1 = voxel.ti.faces[index][0];
            short i2 = voxel.ti.faces[index][1];
            short i3 = voxel.ti.faces[index][2];
            if (i1 >= half_odf_size)
                i1 -= half_odf_size;
            if (i2 >= half_odf_size)
                i2 -= half_odf_size;
            if (i3 >= half_odf_size)
                i3 -= half_odf_size;
            neighbor[i1].push_back(i2);
            neighbor[i1].push_back(i3);
            neighbor[i2].push_back(i1);
            neighbor[i2].push_back(i3);
            neighbor[i3].push_back(i1);
            neighbor[i3].push_back(i2);
        }
    }
    void search(const std::vector<float>& old_odf)
    {
        max_table.clear();
        for (unsigned int index = 0;index < neighbor.size();++index)
        {
            float value = old_odf[index];
            bool is_max = true;
            std::vector<unsigned short>& nei = neighbor[index];
            for (unsigned int j = 0;j < nei.size();++j)
            {
                if (value < old_odf[nei[j]])
                {
                    is_max = false;
                    break;
                }
            }
            if (is_max)
                max_table[value] = (unsigned short)index;
        }
    }
};


struct DetermineFiberDirections : public BaseProcess
{
    SearchLocalMaximum lm;
    boost::mutex mutex;
public:
    virtual void init(Voxel& voxel)
    {
        lm.init(voxel);
    }

    virtual void run(Voxel& voxel,VoxelData& data)
    {
        data.min_odf = *std::min_element(data.odf.begin(),data.odf.end());
        boost::mutex::scoped_lock lock(mutex);
        lm.search(data.odf);
        std::map<float,unsigned short,std::greater<float> >::const_iterator iter = lm.max_table.begin();
        std::map<float,unsigned short,std::greater<float> >::const_iterator end = lm.max_table.end();
        for (unsigned int index = 0;iter != end && index < voxel.max_fiber_number;++index,++iter)
        {
            data.dir_index[index] = iter->second;
            data.fa[index] = iter->first - data.min_odf;
        }
    }
};


class AnaQSpace2Odf : public QSpace2Odf
{
public:
    float max_distribution;
public:
    std::vector<image::vector<3,float> > b_vec;
    struct gradient_fun
    {
        const std::vector<image::vector<3,float> >& b_vec;
        const std::vector<float>& signal;
        gradient_fun(const std::vector<image::vector<3,float> >& b_vec_,
                     const std::vector<float>& signal_):b_vec(b_vec_),signal(signal_) {}

        image::vector<3,float> operator()(const image::vector<3,float>& x0) const
        {
            image::vector<3,float> nx(x0);
            nx.normalize();
            image::vector<3,float> sum;
            for (unsigned int j = 0;j < b_vec.size();++j)
            {
                float prod = b_vec[j]*nx;
                float temp = std::cos(prod)-boost::math::sinc_pi(prod);
                if (std::abs(prod) < 0.0000001)
                    prod = prod > 0.0 ? 0.0000001:-0.0000001;
                prod = temp/prod;
                prod *= signal[j];

                image::vector<3,float> b_vec_ortho(b_vec[j]);
                image::vector<3,float> b_proj(nx);
                b_proj *= (b_vec_ortho*nx);
                b_vec_ortho -= b_proj;
                b_vec_ortho *= prod;
                sum += b_vec_ortho;
            }
            sum /= b_vec.size();
            return sum;
        }
    };

    struct fun
    {
        const std::vector<image::vector<3,float> >& b_vec;
        const std::vector<float>& signal;
        fun(const std::vector<image::vector<3,float> >& b_vec_,
            const std::vector<float>& signal_):b_vec(b_vec_),signal(signal_) {}

        float operator()(const image::vector<3,float>& x0) const
        {
            float sum = 0.0;
            image::vector<3,float> nx(x0);
            nx.normalize();
            for (unsigned int j = 0;j < b_vec.size();++j)
                sum += signal[j] * boost::math::sinc_pi(b_vec[j]*nx);
            return -sum;// to maximize the sum
        }
    };

public:
    virtual void init(Voxel& voxel)
    {
        QSpace2Odf::init(voxel);


        b_vec.resize(voxel.bvalues.size());
        float sigma = voxel.param[0]; //optimal 1.24
        for (unsigned int index = 0; index < voxel.bvalues.size(); ++index)
        {
            b_vec[index] = voxel.bvectors[index];
            b_vec[index] *= std::sqrt(voxel.bvalues[index]*0.01506)*sigma; // �^G�_
        }
    }
    virtual void run(Voxel& voxel, VoxelData& data)
    {


        gradient_fun g(b_vec,data.space);
        fun f(b_vec,data.space);
        std::map<float,image::vector<3,float>,std::greater<float> > result;
        for (unsigned int index = 0;index < voxel.max_fiber_number;++index)
        {
            if (data.fa[index] <= 0.0)
                break;

            image::vector<3,float> initial_dir(voxel.ti.vertices[data.dir_index[index]]);
            image::optimization::gradient_descent(initial_dir,f,g,(double)0.01);
            double fa = -data.min_odf-f(initial_dir);
            initial_dir.normalize();
            if (std::abs(image::vector<3,float>(voxel.ti.vertices[data.dir_index[index]]) * initial_dir) < 0.939692623) // the angle greater than 20 degrees
                result[data.fa[index]] = image::vector<3,float>(voxel.ti.vertices[data.dir_index[index]]);
            else
                result[fa] = initial_dir;
        }

        std::map<float,image::vector<3,float>,std::greater<float> >::const_iterator iter = result.begin();
        std::map<float,image::vector<3,float>,std::greater<float> >::const_iterator end = result.end();
        for (unsigned int index = 0;iter != end;++index,++iter)
        {
            data.fa[index] = iter->first;
            data.dir[index] = iter->second;
        }

    }
};



#endif//ODF_TRANSFORMATION_PROCESS_HPP
