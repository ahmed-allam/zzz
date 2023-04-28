#include "Worker.h"
//#include <unistd.h>
#include <windows.h>

#include "qt_Multithreaded_cuda.h"
#include "./csv_to_monowave/csv_min_time_with_price_difference.h"

/*
{
    //csv_to_monowave csv_to_monowave_instance;
    csv_to_monowave_bin csv_to_monowave_instance;
    //5-8-2021csv_to_monowave_instance.csv_graph_array();

    csv_to_monowave_instance.csv_time_bid_ask_difference();

    csv_to_monowave_instance.csv_min_time_with_price_difference();
    /////////////////////////////////////////////////////////////////////////
    //csv_to_monowave_instance.csv_graph_array();

    /////////////////////////////////////////////////////////////////////////

    csv_to_monowave_instance.csv_Directional_NonDirectional();
    /*
    //SECOND start the helper function which is the main target of this program
    // convert csv file to monowave file.
    cudaError_t cudaStatus = csv_file_min_max_time_price(tickTime,
        bidPrice,//	bidVolume,
        askPrice//,askVolume);
        );
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "csv_file_min_max_time_price failed!");
        return 1;
    }

    //THIRD calculate monowaves serially on CPU


    // cudaDeviceReset must be called before exiting in order for profiling and
    // tracing tools such as Nsight and Visual Profiler to show complete traces.
    cudaStatus = cudaDeviceReset();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceReset failed!");
        return 1;
    }
    */
/*return 0;
}
*/

/*
void Worker::run() {
    QString Output = "Hello world";
    while (1) {
        emit resultReady(Output);
        Sleep(5);
    }
}
*/
// --- CONSTRUCTOR ---
Worker::Worker() {
    // you could copy data from constructor arguments to internal variables here.
     //csv_to_monowave_instance = csv_to_monowave_bin(this);

}
// --- CONSTRUCTOR ---
Worker::Worker(QT_Multithreaded_Cuda_class* QT_Multithreaded_Cuda_class_pointer) {
    // you could copy data from constructor arguments to internal variables here.
    //csv_to_monowave_instance = csv_to_monowave_bin(this);
    QT_Multithreaded_Cuda_class_ptr = QT_Multithreaded_Cuda_class_pointer;
    //plotGraph_waiting= QT_Multithreaded_Cuda_class_pointer->plotGraph_waiting;
    //mutex= QT_Multithreaded_Cuda_class_pointer->mutex;
}
// --- DECONSTRUCTOR ---
Worker::~Worker() {
    // free resources
}

// --- PROCESS ---
// Start processing data.
void Worker::process() {
    // allocate resources using new here
    qDebug("Hello World!");
    //csv_to_monowave_instance = csv_to_monowave_bin(this);
    //current_monowave_class_ptr = &csv_to_monowave_instance;
    csv_min_time_with_price_difference   current_monowave_class_instance(this);
    //current_monowave_class_ptr= &csv_to_monowave_instance;

    //current_monowave_class_ptr = &csv_to_monowave_instance;
    //csv_to_monowave_instance.csv_time_bid_ask_difference(this);

    //csv_to_monowave_instance.csv_min_time_with_price_difference(this);


    emit finished();
}

/*
void Worker::plotGraph(csv_to_monowave_bin* csv_to_monowave_ptr) {


}
*/

/*
void Worker::plottingGraph() 
{
    // allocate resources using new here
    qDebug("Hello World!  plotting now");
    QVector<double> x(100), y(100);
    for (int i = 0; i < 100; ++i)
    {
        x[i] = i;
        //y[i] = fRand2(0, 10);
        y[i] = i*2;
        //std::cout<<"????????????"<< csv_to_monowave_instance.askPrice[i]<<std::endl;
        //y[i]= current_monowave_class_ptr->askPrice[i];

    }
    //x = current_monowave_class_ptr;
    //y = QVector<double>::fromStdVector((double)current_monowave_class_ptr->askPrice);

    QT_Multithreaded_Cuda_class_ptr->plot_->graph(0)->setData(x, y);
    QT_Multithreaded_Cuda_class_ptr->plot_->rescaleAxes();
    QT_Multithreaded_Cuda_class_ptr->plot_->replot();
    //csv_to_monowave_instance = csv_to_monowave_bin(this);
    //current_monowave_class_ptr = &csv_to_monowave_instance;

    emit finished();
}
*/

