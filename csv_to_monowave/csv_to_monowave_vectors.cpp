#include "csv_to_monowave_vectors.h"
#include "../Worker.h"


csv_to_monowave_vectors::csv_to_monowave_vectors()
{

}
//17-9-2021 this modification is for Qt graphing
csv_to_monowave_vectors::csv_to_monowave_vectors(Worker* workerPtr)
{
    plot_flag = csv_bin;
    //day_seconds=1*24*60*60;
    //path ="E:/backup_starting_6-4-2020/visualstudio2019_9-4-2020/csv_to_cuda_vs_2019_sln/csv_to_cuda_vs_2019/csv_to_monowave/GBPJPY_2020_08_30_.csv";
    path = "GBPJPY_2020_08_30_.bin";
    //path = "00h_ticks.binepoch";
    //30-11-2020 get the symbol name
    std::size_t pos = path.find("_");
    std::string symbol = path.substr(0, pos);
    //data_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    //try
    //{


    //}
    //catch (std::ifstream::failure e)
    //{
    //    std::cerr << "Exception opening file: " << std::strerror(errno) << "\n";
    //}


    double PV;
    int PV_fraction_precision = 0;

    std::vector<std::string>::iterator it3 = std::find(point_value_xxx.begin(), point_value_xxx.end(), symbol);

    std::vector<std::string>::iterator it4 = std::find(point_value_xxxx.begin(), point_value_xxxx.end(), symbol);

    std::vector<std::string>::iterator it5 = std::find(point_value_xxxxx.begin(), point_value_xxxxx.end(), symbol);
    if (it3 != point_value_xxx.end())
    {
        PV = 0.001;
        PV_fraction_precision = 3;
    }
    else if (it4 != point_value_xxxx.end())
    {
        PV = 0.0001;
        PV_fraction_precision = 4;
    }
    else if (it5 != point_value_xxxxx.end())
    {
        PV = 0.00001;
        PV_fraction_precision = 5;
    }
    else
    {
        //10-1-2020throw;
        PV = 0.001;
        PV_fraction_precision = 3;

    }
    lineCounter = 0;
    //read binary file
    auto currentPath = boost::filesystem::current_path();
    //auto parentPath = currentPath.parent_path();
    //string subFolder = "foo2";
    std::string folderPath = currentPath.string() + "/" + path; //+ "/";
    boost::filesystem::path boostPath{ folderPath };

    int raw_size_epoch = boost::filesystem::file_size(boostPath);

    data_file.open(path, std::ios::in | std::ios::binary);
    if (!data_file.is_open()) {
        std::cout << path << " failed to open!" << std::endl;
    }

    int field_vector_size = raw_size_epoch / (sizeof(unsigned int) * 6);
    size_t offset = 0;
    unsigned int unsigned_integer_variable = 0;
    //for (int i = 0; i < field_vector_size; i++)
    //21-2-2021 i will get 20 data points only
    for (int i = 0; i < 100; i++)
        //while(!data_file.eof())
    {
        data_file.read(reinterpret_cast<char*>(&unsigned_integer_variable), sizeof(unsigned int));
        if (data_file.eof()) {
            std::cout << path << " file reached its end!" << std::endl;
            break;
        }
        epochpartTime.push_back(unsigned_integer_variable);
        //std::cout << unsigned_integer_variable << std::endl;
        data_file.read(reinterpret_cast<char*>(&unsigned_integer_variable), sizeof(unsigned int));
        tickpartTime.push_back(unsigned_integer_variable);

        data_file.read(reinterpret_cast<char*>(&unsigned_integer_variable), sizeof(unsigned int));
        askPrice.push_back(unsigned_integer_variable);

        data_file.read(reinterpret_cast<char*>(&unsigned_integer_variable), sizeof(unsigned int));
        bidPrice.push_back(unsigned_integer_variable);

        data_file.read(reinterpret_cast<char*>(&unsigned_integer_variable), sizeof(unsigned int));
        askVolume.push_back(unsigned_integer_variable);

        data_file.read(reinterpret_cast<char*>(&unsigned_integer_variable), sizeof(unsigned int));
        bidVolume.push_back(unsigned_integer_variable);

    }

    //21-2-2021 I make DIRECTIONAL_NONDIRECTIONAL_DEGREE_CLASS which has the following variables
    //I will make array of 21 instances of directional_nondirectional_degree_class
    //for (int degree_count = -10; degree_count < 10; degree_count++)
    //{
        // directional_nondirectional_degree_class directional_nondirectional_degree_class(degree_count);
    //    D_ND_degree_vec.push_back(directional_nondirectional_degree_class(this, degree_count));
    //}
    data_file.close();
    /*
    //17-9-2021 we will plot bid ask prices
    //workerPtr->current_monowave_class_ptr = this;
    //(*(workerPtr->QT_Multithreaded_Cuda_class_ptr)). ;
    emit workerPtr->updateTable(this);
    mutex.lock();
    updateTable_waiting.wait(&mutex);
    mutex.unlock();
    emit workerPtr->plotGraph(this);
    mutex.lock();
    plotGraph_waiting.wait(&mutex);
    mutex.unlock();
    */
}