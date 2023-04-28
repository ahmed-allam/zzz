#ifndef QT_MULTITHREADED_CUDA_H
#define QT_MULTITHREADED_CUDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

#include "table_model.h"
#include "tableView_custom.h"
#include "tab_dialog0.h"

#include "./csv_to_monowave/csv_min_time_with_price_difference.h"
#include "Worker.h"

class QT_Multithreaded_Cuda_class : public QWidget
{
    Q_OBJECT 

public:
    QT_Multithreaded_Cuda_class(int width, int height, QWidget* parent = Q_NULLPTR);
    //the following two members start new thread for cuda program and update qcustomplot  respectively
    void ThreadedRunCommand(QT_Multithreaded_Cuda_class* QT_Multithreaded_Cuda_class_ptr);

public slots:
    //void showRowHeaderName(QString Input) const;
    void plottingGraph(csv_min_time_with_price_difference* current_monowave_class_ptr, int degree = 0);
    void updatingTable(csv_min_time_with_price_difference* current_monowave_class_ptr,int degree=0);

    //void pushButtonClicked();


private slots:
        
public:    
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

public:
    tabWidget* tabWidget_ptr;
    //TabDialog* tabdialog_ptr;
    Worker* worker;

    //this is for table view
    //MatrixModel* model_;
    int pixelsWide ;
    int pixelsHigh ;    
    //QWidget* scrollAreaWidgetContents_;    
    int screen_width, screen_height;
};

#endif // QT_MULTITHREADED_CUDA_H