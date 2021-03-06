#ifndef MNI_RECONSTRUCTION_HPP
#define MNI_RECONSTRUCTION_HPP
#include "gqi_process.hpp"
#include "mapping/fa_template.hpp"
#include "mapping/normalization.hpp"
#include "basic_voxel.hpp"
#include "basic_process.hpp"
#include "odf_decomposition.hpp"
#include "odf_deconvolusion.hpp"
#include "gqi_process.hpp"

extern fa_template fa_template_imp;
class GQI_MNI  : public BaseProcess
{
public:
    ODFDecomposition decomposition;
    ODFDeconvolusion deconvolution;
    float angle_variance;
    QSpace2Odf gqi;
protected:
    normalization<image::basic_image<float,3> > mni;
    image::geometry<3> src_geo;
    image::geometry<3> des_geo;
    double max_accumulated_qa;
    double voxel_volume_scale;
    std::vector<float> max_odf;
    std::vector<float> jdet;
    int b0_index;
protected:
    image::transformation_matrix<3,double> affine;
protected:
    image::basic_image<float,3> VG,VF;
    double VGvs[3];
    double R2;
protected:
    image::vector<3,int> bounding_box_lower;
    image::vector<3,int> bounding_box_upper;
    image::vector<3,int> des_offset;// = {6,7,11};	// the offset due to bounding box
    image::vector<3,double> scale;

protected:
    double r2_base_function(double theta)
    {
            if(std::abs(theta) < 0.000001)
                    return 1.0/3.0;
            return (2*std::cos(theta)+(theta-2.0/theta)*std::sin(theta))/theta/theta;
    }
protected:
    typedef image::basic_image<unsigned short,3,image::const_pointer_memory<unsigned short> > point_image_type;
    std::vector<point_image_type> ptr_images;
    std::vector<image::vector<3,double> > q_vectors_time;

protected:
    template<typename I_type>
    image::vector<3,double> center_of_mass(const I_type& Im)
    {
        image::basic_image<unsigned char,I_type::dimension> mask;
        image::segmentation::otsu(Im,mask);
        image::morphology::smoothing(mask);
        image::morphology::smoothing(mask);
        image::morphology::defragment(mask);
        image::vector<I_type::dimension,double> sum_mass;
        double total_w = 0.0;
        for(image::pixel_index<I_type::dimension> index;
            mask.geometry().is_valid(index);
            index.next(mask.geometry()))
            if(mask[index.index()])
            {
                total_w += 1.0;
                image::vector<3,double> pos(index);
                sum_mass += pos;
            }
        sum_mass /= total_w;
        for(unsigned char dim = 0;dim < I_type::dimension;++dim)
            sum_mass[dim] -= (double)Im.geometry()[dim]/2.0;
        return sum_mass;
    }
public:
    virtual void init(Voxel& voxel)
    {
        if(voxel.vs[0] == 0.0 ||
           voxel.vs[1] == 0.0 ||
           voxel.vs[2] == 0.0)
            throw std::runtime_error("No spatial information found in src file. Recreate src file or contact developer for assistance");

        begin_prog("normalization");

        VG = fa_template_imp.I;
        VF = voxel.fa_map;

        image::filter::gaussian(voxel.fa_map);
        image::filter::gaussian(voxel.fa_map);
        image::filter::gaussian(voxel.qa_map);
        image::filter::gaussian(voxel.qa_map);
        image::normalize(voxel.fa_map,1.0);
        image::normalize(voxel.qa_map,1.0);
        for(unsigned int index = 0;index < voxel.qa_map.size();++index)
            if(voxel.qa_map[index] == 0.0 || voxel.fa_map[index]/voxel.qa_map[index] > 2.5)
                VF[index] = 0.0;
        image::filter::gaussian(VF);

        src_geo = VF.geometry();

        image::normalize(VF,1.0);
        //VF.save_to_file<image::io::nifti<> >("VF.nii");

        image::normalize(VG,1.0);

        // get rid of the gray matters
        image::minus_constant(VF.begin(),VF.end(),0.3);
        image::lower_threshold(VF.begin(),VF.end(),0.00);
        image::normalize(VF,1.0);

        image::minus_constant(VG.begin(),VG.end(),0.3);
        image::lower_threshold(VG.begin(),VG.end(),0.00);
        image::normalize(VG,1.0);

        VGvs[0] = std::fabs(fa_template_imp.tran[0]);
        VGvs[1] = std::fabs(fa_template_imp.tran[5]);
        VGvs[2] = std::fabs(fa_template_imp.tran[10]);

        image::affine_transform<3,double> arg_min;
        // VG: FA TEMPLATE
        // VF: SUBJECT QA
        arg_min.scaling[0] = voxel.vs[0] / VGvs[0];
        arg_min.scaling[1] = voxel.vs[1] / VGvs[1];
        arg_min.scaling[2] = voxel.vs[2] / VGvs[2];
        voxel_volume_scale = arg_min.scaling[0]*arg_min.scaling[1]*arg_min.scaling[2];
        // calculate center of mass
        image::vector<3,double> mF = center_of_mass(VF);
        image::vector<3,double> mG = center_of_mass(VG);

        arg_min.translocation[0] = mG[0]-mF[0]*arg_min.scaling[0];
        arg_min.translocation[1] = mG[1]-mF[1]*arg_min.scaling[1];
        arg_min.translocation[2] = mG[2]-mF[2]*arg_min.scaling[2];


        bool terminated = false;
        set_title("linear registration");
        begin_prog("conducting registration");
        check_prog(0,2);
        image::reg::linear(VF,VG,arg_min,image::reg::affine,image::reg::square_error(),terminated,0.25);
        check_prog(1,2);

        // create VFF the affine transformed VF
        image::basic_image<float,3> VFF(VG.geometry());
        {

            affine = arg_min;
            image::reg::linear_get_trans(VF.geometry(),VG.geometry(),affine);
            {
                std::vector<double> T(16);
                affine.save_to_transform(T.begin());
                T[15] = 1.0;
                math::matrix_inverse(T.begin(),math::dim<4,4>());
                affine.load_from_transform(T.begin());
            }

            image::resample(VF,VFF,affine);

            //VFF.save_to_file<image::io::nifti<> >("VFF.nii");
            //VG.save_to_file<image::io::nifti<> >("VG.nii");

        }
        {
            switch(voxel.reg_method)
            {
                case 0:
                    mni.normalize(VG,VFF);
                break;
                case 1:
                    mni.normalize(VG,VFF,12,14,12,4,8);
                break;
            }

            //calculate the goodness of fit
            std::vector<float> x,y;
            x.reserve(VG.size());
            y.reserve(VG.size());
            image::interpolation<image::linear_weighting,3> trilinear_interpolation;
            for(image::pixel_index<3> index;VG.geometry().is_valid(index);
                    index.next(VG.geometry()))
                if(VG[index.index()] != 0)
                {
                    image::vector<3,double> pos;
                    mni.warp_coordinate(index,pos);
                    double value = 0.0;
                    if(!trilinear_interpolation.estimate(VFF,pos,value))
                        continue;
                    x.push_back(VG[index.index()]);
                    y.push_back(value);
                }
            R2 = x.empty() ? 0.0 : image::correlation(x.begin(),x.end(),y.begin());
            R2 *= R2;
            std::cout << "R2 = " << R2 << std::endl;
        }

        check_prog(2,2);


        // setup output bounding box
        {
            //setBoundingBox(-78,-112,-50,78,76,85,1.0);
            float voxel_size = voxel.param[1];
            bounding_box_lower[0] = std::floor(-78.0/voxel_size+0.5)*voxel_size;
            bounding_box_lower[1] = std::floor(-112.0/voxel_size+0.5)*voxel_size;
            bounding_box_lower[2] = std::floor(-50.0/voxel_size+0.5)*voxel_size;
            bounding_box_upper[0] = std::floor(78.0/voxel_size+0.5)*voxel_size;
            bounding_box_upper[1] = std::floor(76.0/voxel_size+0.5)*voxel_size;
            bounding_box_upper[2] = std::floor(85.0/voxel_size+0.5)*voxel_size;
            des_geo[0] = (bounding_box_upper[0]-bounding_box_lower[0])/voxel_size+1;//79
            des_geo[1] = (bounding_box_upper[1]-bounding_box_lower[1])/voxel_size+1;//95
            des_geo[2] = (bounding_box_upper[2]-bounding_box_lower[2])/voxel_size+1;//69
            des_offset[0] = bounding_box_lower[0]/VGvs[0]-fa_template_imp.tran[3]/fa_template_imp.tran[0];
            des_offset[1] = bounding_box_lower[1]/VGvs[1]-fa_template_imp.tran[7]/fa_template_imp.tran[5];
            des_offset[2] = bounding_box_lower[2]/VGvs[2]-fa_template_imp.tran[11]/fa_template_imp.tran[10];
            scale[0] = voxel_size/VGvs[0];
            scale[1] = voxel_size/VGvs[1];
            scale[2] = voxel_size/VGvs[2];
        }

        begin_prog("q-space diffeomorphic reconstruction");


        float sigma = voxel.param[0]; //diffusion sampling length ratio, optimal 1.24
        // setup mask
        {
            // set the current mask to template space
            voxel.image_model->set_dimension(des_geo[0],des_geo[1],des_geo[2]);
            for(image::pixel_index<3> index;des_geo.is_valid(index);index.next(des_geo))
            {
                image::vector<3,int> mni_pos(index);
                mni_pos *= voxel.param[1];
                mni_pos[0] /= VGvs[0];
                mni_pos[1] /= VGvs[1];
                mni_pos[2] /= VGvs[2];
                mni_pos += des_offset;
                voxel.image_model->mask[index.index()] =
                        fa_template_imp.I.at(mni_pos[0],mni_pos[1],mni_pos[2]) > 0.0? 1: 0;
            }
        }


        q_vectors_time.resize(voxel.bvalues.size());
        for (unsigned int index = 0; index < voxel.bvalues.size(); ++index)
        {
            q_vectors_time[index] = voxel.bvectors[index];
            q_vectors_time[index] *= std::sqrt(voxel.bvalues[index]*0.01506);// get q in (mm) -1
            q_vectors_time[index] *= sigma;
        }

        b0_index = -1;
        if(voxel.half_sphere)
            for(unsigned int index = 0;index < voxel.bvalues.size();++index)
                if(voxel.bvalues[index] == 0)
                    b0_index = index;

        ptr_images.clear();
        for (unsigned int index = 0; index < voxel.image_model->dwi_data.size(); ++index)
            ptr_images.push_back(point_image_type((const unsigned short*)voxel.image_model->dwi_data[index],src_geo));


        voxel.qa_scaling = voxel.reponse_function_scaling/voxel.vs[0]/voxel.vs[1]/voxel.vs[2];
        max_accumulated_qa = 0;

        std::fill(voxel.vs.begin(),voxel.vs.end(),voxel.param[1]);

        jdet.resize(des_geo.size());


        if (voxel.odf_deconvolusion)
        {
            gqi.init(voxel);
            deconvolution.init(voxel);
        }
        if (voxel.odf_decomposition)
        {
            gqi.init(voxel);
            decomposition.init(voxel);
        }
        angle_variance = 8; //degress;
        angle_variance *= M_PI/180;
        angle_variance *= angle_variance;
        angle_variance *= 2.0;

    }

    void get_jacobian(const image::vector<3,double>& pos,float jacobian[9])
    {
        float M[9];
        mni.get_jacobian(pos,M);
        math::matrix_product(affine.scaling_rotation,M,jacobian,math::dim<3,3>(),math::dim<3,3>());
    }

    // combined with deconvolution or decomposition
    void odf_sharpening(Voxel& voxel, VoxelData& data,float jacobian[9])
    {
        gqi.run(voxel,data);
        if (voxel.odf_deconvolusion)
            deconvolution.run(voxel,data);
        else
            decomposition.run(voxel,data);
        std::vector<float> new_odf(data.odf.size());
        std::vector<float> w(voxel.ti.half_vertices_count*voxel.ti.half_vertices_count);
        for(unsigned int i = 0,w_pos = 0;i < data.odf.size();++i,++w_pos)
            {
                image::vector<3,double> new_dir;
                math::matrix_product(jacobian,voxel.ti.vertices[i].begin(),new_dir.begin(),math::dim<3,3>(),math::dim<3,1>());
                new_dir.normalize();
                if(data.odf[i] >= data.min_odf)
                for(unsigned int row = 0,w_row = w_pos;
                    row < voxel.ti.half_vertices_count;
                    ++row,w_row += voxel.ti.half_vertices_count)
                {
                    float angle = std::acos(std::min<float>(1.0,std::abs(voxel.ti.vertices[row]*new_dir)));
                    w[w_row] = std::exp(-angle*angle/angle_variance);
                }
            }
        for(unsigned int i = 0,w_pos = 0;i < data.odf.size();++i,w_pos += voxel.ti.half_vertices_count)
        {
            new_odf[i] = math::vector_op_dot(data.odf.begin(),data.odf.end(),w.begin()+w_pos)/
                    std::accumulate(w.begin()+w_pos,w.begin()+w_pos+voxel.ti.half_vertices_count,0.0f);
        }
        data.odf.swap(new_odf);
    }

    virtual void run(Voxel& voxel, VoxelData& data)
    {
        image::interpolation<image::linear_weighting,3> trilinear_interpolation;
        image::vector<3,double> pos(image::pixel_index<3>(data.voxel_index,des_geo)),Jpos;
        pos[0] *= scale[0];
        pos[1] *= scale[1];
        pos[2] *= scale[2];
        pos += des_offset;
        mni.warp_coordinate(pos,Jpos);
        affine(Jpos.begin());
        if(!trilinear_interpolation.get_location(src_geo,Jpos))
        {
            std::fill(data.odf.begin(),data.odf.end(),0);
            return;
        }
        for (unsigned int i = 0; i < data.space.size(); ++i)
            trilinear_interpolation.estimate(ptr_images[i],data.space[i]);

        if(voxel.half_sphere && b0_index != -1)
            data.space[b0_index] /= 2.0;

        float jacobian[9];
        get_jacobian(pos,jacobian);


        if (voxel.odf_deconvolusion || voxel.odf_decomposition)
            odf_sharpening(voxel,data,jacobian);
        else
        {
            std::vector<float> sinc_ql(data.odf.size()*voxel.q_count);
            for (unsigned int j = 0,index = 0; j < data.odf.size(); ++j)
            {
                image::vector<3,double> dir(voxel.ti.vertices[j]),from;
                math::matrix_product(jacobian,dir.begin(),from.begin(),math::dim<3,3>(),math::dim<3,1>());
                from.normalize();
                if(voxel.r2_weighted)
                    for (unsigned int i = 0; i < voxel.q_count; ++i,++index)
                        sinc_ql[index] = r2_base_function(q_vectors_time[i]*from);
                else
                    for (unsigned int i = 0; i < voxel.q_count; ++i,++index)
                        sinc_ql[index] = boost::math::sinc_pi(q_vectors_time[i]*from);

            }
            math::matrix_vector_product(&*sinc_ql.begin(),&*data.space.begin(),&*data.odf.begin(),
                                        math::dyndim(data.odf.size(),data.space.size()));
        }

        jdet[data.voxel_index] = std::abs(math::matrix_determinant(jacobian,math::dim<3,3>())*voxel_volume_scale);
        std::for_each(data.odf.begin(),data.odf.end(),boost::lambda::_1 *= jdet[data.voxel_index]);
        float accumulated_qa = std::accumulate(data.odf.begin(),data.odf.end(),0.0);
        if (max_accumulated_qa < accumulated_qa)
        {
            max_accumulated_qa = accumulated_qa;
            max_odf = data.odf;
        }
    }
    virtual void end(Voxel& voxel,MatFile& mat_writer)
    {
        mat_writer.add_matrix("free_water_quantity",&voxel.qa_scaling,1,1);
        mat_writer.add_matrix("jdet",&*jdet.begin(),1,jdet.size());
        double trans_to_mni[16];
        std::fill(trans_to_mni,trans_to_mni+16,0.0);
        trans_to_mni[0] = scale[0];
        trans_to_mni[5] = scale[1];
        trans_to_mni[10] = scale[2];
        trans_to_mni[3] = bounding_box_lower[0]-scale[0];
        trans_to_mni[7] = bounding_box_lower[1]-scale[1];
        trans_to_mni[11] = bounding_box_lower[2]-scale[2];
        mat_writer.add_matrix("mni",&*trans_to_mni,4,3);
        mat_writer.add_matrix("R2",&R2,1,1);
    }

};

#endif//MNI_RECONSTRUCTION_HPP
