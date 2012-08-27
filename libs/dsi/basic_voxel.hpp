#ifndef BASIC_VOXEL_HPP
#define BASIC_VOXEL_HPP
#include <boost/mpl/vector.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/inherit_linearly.hpp>
#include <boost/utility.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <image/image.hpp>
#include <string>
#include "tessellated_icosahedron.hpp"



struct ImageModel;
struct VoxelParam;
class Voxel;
struct VoxelData;
class BaseProcess : public boost::noncopyable
{
public:
    BaseProcess(void) {}
    virtual void init(Voxel&) {}
    virtual void run(Voxel&, VoxelData&) {}
    virtual void end(Voxel&,MatFile& mat_writer) {}
    virtual ~BaseProcess(void) {}
};



struct VoxelData
{
    unsigned int voxel_index;
    std::vector<float> space;
    std::vector<float> odf;
    std::vector<float> fa;
    std::vector<image::vector<3,float> > dir;
    std::vector<short> dir_index;
    float min_odf;

    void init(void)
    {
        std::fill(fa.begin(),fa.end(),0.0);
        std::fill(dir_index.begin(),dir_index.end(),0);
        std::fill(dir.begin(),dir.end(),image::vector<3,float>());
        min_odf = 0.0;
    }
};

class Voxel : public boost::noncopyable
{
private:
    boost::ptr_vector<BaseProcess> process_list;
public:
    unsigned int matrix_width;
    unsigned int matrix_height;
    unsigned int slice_number;
    unsigned int total_size;
    float voxel_size[3];

    unsigned int q_count;
    std::vector<image::vector<3,float> > bvectors;
    std::vector<float> bvalues;
public:// parameters;
    tessellated_icosahedron ti;
    const float* param;
    bool need_odf;
    bool odf_deconvolusion;
    bool odf_decomposition;
    bool half_sphere;
    bool r2_weighted;// used in GQI only
    unsigned int max_fiber_number;
    std::vector<std::string> file_list;
public:
    float qa_scaling;
    // other information for second pass processing
    std::vector<float> response_function,free_water_diffusion;
    image::basic_image<float,3> qa_map;
    float reponse_function_scaling;
public:// for template creation
    std::vector<std::vector<float> > template_odfs;
    std::string template_file_name;
private:
    std::vector<VoxelData> voxel_data;
public:
    ImageModel* image_model;
public:
    template<typename ProcessList>
    void CreateProcesses(void)
    {
        process_list.clear();
        boost::mpl::for_each<ProcessList>(boost::ref(*this));
    }

    template<typename Process>
    void operator()(Process& X)
    {
        process_list.push_back(new Process);
    }
public:
    void init(unsigned int thread_count)
    {
        voxel_data.resize(thread_count);
        for (unsigned int index = 0; index < thread_count; ++index)
        {
            voxel_data[index].space.resize(q_count);
            voxel_data[index].odf.resize(ti.half_vertices_count);
            voxel_data[index].fa.resize(max_fiber_number);
            voxel_data[index].dir_index.resize(max_fiber_number);
            voxel_data[index].dir.resize(max_fiber_number);
        }
        for (unsigned int index = 0; index < process_list.size(); ++index)
            process_list[index].init(*this);
    }

    void thread_run(unsigned char thread_index,unsigned char thread_count,
                    const std::vector<unsigned char>& mask,
                    bool& terminated)
    {
        unsigned int sum_mask = std::accumulate(mask.begin(),mask.end(),(unsigned int)0)/thread_count;
        unsigned int cur = 0;
        for(unsigned int voxel_index = thread_index;
            voxel_index < total_size && !terminated &&
            (thread_index != 0 || check_prog(cur,sum_mask));voxel_index += thread_count)
        {
            if (!mask[voxel_index])
                continue;
            cur += mask[voxel_index];
            voxel_data[thread_index].init();
            voxel_data[thread_index].voxel_index = voxel_index;
            for (int index = 0; index < process_list.size(); ++index)
                process_list[index].run(*this,voxel_data[thread_index]);
        }
        if(prog_aborted())
            terminated = true;
    }
    void end(MatFile& writer)
    {
        for (unsigned int index = 0; index < process_list.size(); ++index)
            process_list[index].end(*this,writer);
    }

    BaseProcess* get(unsigned int index)
    {
        return &process_list[index];
    }
public:
    /*
    bool read(std::ifstream& in)
    {
        std::vector<unsigned short> pixel_data(q_count);
        if (!in.read((char*)&*pixel_data.begin(),pixel_data.size() << 1)) // << 1 for unsigned short = 2 byte
            return false;
        std::copy(pixel_data.begin(),pixel_data.end(),space.begin());
        return true;
    }*/
};


#endif//BASIC_VOXEL_HPP