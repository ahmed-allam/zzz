#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QVector>
#include "./csv_to_monowave/csv_min_time_with_price_difference.h"
//#include "qt_Multithreaded_cuda.h"

//class csv_to_monowave_bin;
class QT_Multithreaded_Cuda_class;

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(QT_Multithreaded_Cuda_class*);
    explicit Worker();

    ~Worker();
    //void run();
Q_SIGNALS:    //these should be made templates which take any of csv_ classes
    void plotGraph(csv_min_time_with_price_difference* );
    void updateTable(csv_min_time_with_price_difference* );

    void newData(QVector<double> x, QVector<double> y);
    void finished();

    //void resultReady(QString Input);
    //void error(QString err);
public Q_SLOTS:
    //void start();
    //void stop();

    void process();
    //void plottingGraph();
private:
    // add your variables here
    bool run_ = false;
public:
    //csv_to_monowave_bin  csv_to_monowave_instance;
    csv_min_time_with_price_difference * current_monowave_class_ptr;
    QT_Multithreaded_Cuda_class* QT_Multithreaded_Cuda_class_ptr;
    //QWaitCondition &plotGraph_waiting;
    //QMutex &mutex;

};

#endif // WORKER_H