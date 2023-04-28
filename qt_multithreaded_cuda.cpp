#include <QThread>

#include "qt_Multithreaded_cuda.h"
#include "worker.h"
#include "global.h"

QT_Multithreaded_Cuda_class::QT_Multithreaded_Cuda_class(int width,int height, QWidget* parent)    
    :screen_width(width),screen_height(height), QWidget(parent)
{
    tabWidget_ptr = new tabWidget(width, height, this);
    //tabdialog_ptr = new TabDialog(width,height,this);
    //tabdialog_ptr->setParent(this);
    //tabdialog_ptr->show() ;
    if (objectName().isEmpty())
        setObjectName(QString::fromUtf8("QT_Multithreaded_Cuda"));
    QSizePolicy sizePolicy_w(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //sizePolicy_w.setHorizontalStretch(1);
    //sizePolicy_w.setVerticalStretch(1);
    //sizePolicy_w.setHeightForWidth(sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy_w);    
    setFixedSize(screen_width-10,screen_height-30);
    //resize(width,height);
       

    QFont font("times", 12);
    QFontMetrics fm(font);
    pixelsWide = fm.width("xxxxxx");
    pixelsHigh = fm.height();

    

    setWindowTitle(QApplication::translate("QT_Multithreaded_Cuda", "QT_Multithreaded_Cuda", nullptr));
    //QGridLayout* mainLayout = new QGridLayout;
    //setLayout(mainLayout);

    //mainLayout->addWidget(tabdialog_ptr,0,0);
    //mainLayout->addWidget(buttonBox);
    //setLayout(mainLayout);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    setLayout(mainLayout);
    mainLayout->addWidget(tabWidget_ptr);
    //mainLayout->addWidget(buttonBox);

    ThreadedRunCommand(this);    
}

QSize QT_Multithreaded_Cuda_class::sizeHint() const
{
    return QSize(screen_width, screen_height);
}

QSize QT_Multithreaded_Cuda_class::minimumSizeHint() const
{
    return QSize(screen_width, screen_height);
}

void QT_Multithreaded_Cuda_class::ThreadedRunCommand(QT_Multithreaded_Cuda_class* QT_Multithreaded_Cuda_class_ptr)
{
    QThread* thread = new QThread;
    Worker* worker = new Worker(QT_Multithreaded_Cuda_class_ptr);
    worker->moveToThread(thread);
    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
   
    //17-9-2021 this signal is used to connect between plotGraph signal and slot to draw graph
    connect(worker, SIGNAL(plotGraph(csv_min_time_with_price_difference* )), QT_Multithreaded_Cuda_class_ptr, SLOT(plottingGraph(csv_min_time_with_price_difference*)));
    connect(worker, SIGNAL(updateTable(csv_min_time_with_price_difference*)), QT_Multithreaded_Cuda_class_ptr, SLOT(updatingTable(csv_min_time_with_price_difference*)));
    //connect(worker, SIGNAL(plotGraph(csv_to_monowave_bin*)), worker, SIGNAL(updateTable(csv_to_monowave_bin*)));    
    //connect(worker, SIGNAL(updateTable(csv_to_monowave_bin*)), worker, SIGNAL(plotGraph(csv_to_monowave_bin*)));
    thread->start();
}
void QT_Multithreaded_Cuda_class::updatingTable(csv_min_time_with_price_difference* current_monowave_class_ptr, int degree)
{
    // allocate resources using new here
    qDebug("Hello World!  updating table now from QT_Multithreaded_Cuda_class");
    tabWidget_ptr->updatingTable(current_monowave_class_ptr, degree);
    //model_ = new MatrixModel(current_monowave_class_ptr);
    //tableView_->setModel(model_);

}
void QT_Multithreaded_Cuda_class::plottingGraph(csv_min_time_with_price_difference* current_monowave_class_ptr, int degree)
{
    // allocate resources using new here
    qDebug("Hello World!  plottingGraph now from QT_Multithreaded_Cuda_class");
    tabWidget_ptr->plottingGraph(current_monowave_class_ptr, degree);
    

}


