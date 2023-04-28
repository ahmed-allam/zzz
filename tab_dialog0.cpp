#include <QtWidgets>

#include "tab_dialog0.h"

//! [0]
tabWidget::tabWidget(int width,int height, QWidget* parent)
    :screen_width(width), screen_height(height), QTabWidget(parent)
{
    QSizePolicy sizePolicy_w(QSizePolicy::Preferred, QSizePolicy::Preferred);
    if (objectName().isEmpty())
        setObjectName(QString::fromUtf8("TabDialog"));
    //sizePolicy_w.setHorizontalStretch(1);
    //sizePolicy_w.setVerticalStretch(1);
    //sizePolicy_w.setHeightForWidth(sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy_w);
    //setFixedSize(screen_width - 10, screen_height - 30);
    //resize(width,height);
    //parentWidget();
    //setParent(parent);
    //show();
    //setWindowTitle(QApplication::translate("TabDialog", "TabDialog", nullptr));

    //tabWidget = new QTabWidget;
    
    //allam 16-9-2022
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));
    tab_ptr_vector.push_back(new qtTab(width, height));

    Degree_minus10= addTab(tab_ptr_vector[0], tr("Degree -10"));
    Degree_minus9 = addTab(tab_ptr_vector[1], tr("Degree -9"));
    Degree_minus8 = addTab(tab_ptr_vector[2], tr("Degree -8"));
    Degree_minus7 = addTab(tab_ptr_vector[3], tr("Degree -7"));
    Degree_minus6 = addTab(tab_ptr_vector[4], tr("Degree -6"));
    Degree_minus5 = addTab(tab_ptr_vector[5], tr("Degree -5"));
    Degree_minus4 = addTab(tab_ptr_vector[6], tr("Degree -4"));
    Degree_minus3 = addTab(tab_ptr_vector[7], tr("Degree -3"));
    Degree_minus2 = addTab(tab_ptr_vector[8], tr("Degree -2"));
    Degree_minus1 = addTab(tab_ptr_vector[9], tr("Degree -1"));
    Degree0 = addTab(tab_ptr_vector[10], tr("Degree 0"));
    Degree1 = addTab(tab_ptr_vector[11], tr("Degree 1"));
    Degree2 = addTab(tab_ptr_vector[12], tr("Degree 2"));
    Degree3 = addTab(tab_ptr_vector[13], tr("Degree 3"));
    Degree4 = addTab(tab_ptr_vector[14], tr("Degree 4"));
    Degree5 = addTab(tab_ptr_vector[15], tr("Degree 5"));
    Degree6 = addTab(tab_ptr_vector[16], tr("Degree 6"));
    Degree7 = addTab(tab_ptr_vector[17], tr("Degree 7"));
    Degree8 = addTab(tab_ptr_vector[18], tr("Degree 8"));
    Degree9 = addTab(tab_ptr_vector[19], tr("Degree 9"));
    Degree10 = addTab(tab_ptr_vector[20], tr("Degree 10"));

    //! [0]

    //! [1] //! [2]
    //buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
        //! [1] //! [3]
     //   | QDialogButtonBox::Cancel);

    //connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    //connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    //! [2] //! [3]

    //! [4]
    //QVBoxLayout* mainLayout = new QVBoxLayout;
    //mainLayout->addWidget(tabWidget);
    //mainLayout->addWidget(buttonBox);
    //setLayout(mainLayout);
    //! [4]

    //! [5]
    setWindowTitle(tr("Tab Dialog"));
    //setCurrentIndex(11);

}
//! [5]
/*
//! [6]
GeneralTab::GeneralTab(const QFileInfo& fileInfo, QWidget* parent)
    : QWidget(parent)
{
    QLabel* fileNameLabel = new QLabel(tr("File Name:"));
    QLineEdit* fileNameEdit = new QLineEdit(fileInfo.fileName());

    QLabel* pathLabel = new QLabel(tr("Path:"));
    QLabel* pathValueLabel = new QLabel(fileInfo.absoluteFilePath());
    pathValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QLabel* sizeLabel = new QLabel(tr("Size:"));
    qlonglong size = fileInfo.size() / 1024;
    QLabel* sizeValueLabel = new QLabel(tr("%1 K").arg(size));
    sizeValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QLabel* lastReadLabel = new QLabel(tr("Last Read:"));
    QLabel* lastReadValueLabel = new QLabel(fileInfo.lastRead().toString());
    lastReadValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QLabel* lastModLabel = new QLabel(tr("Last Modified:"));
    QLabel* lastModValueLabel = new QLabel(fileInfo.lastModified().toString());
    lastModValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(fileNameLabel);
    mainLayout->addWidget(fileNameEdit);
    mainLayout->addWidget(pathLabel);
    mainLayout->addWidget(pathValueLabel);
    mainLayout->addWidget(sizeLabel);
    mainLayout->addWidget(sizeValueLabel);
    mainLayout->addWidget(lastReadLabel);
    mainLayout->addWidget(lastReadValueLabel);
    mainLayout->addWidget(lastModLabel);
    mainLayout->addWidget(lastModValueLabel);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}
//! [6]

//! [7]
PermissionsTab::PermissionsTab(const QFileInfo& fileInfo, QWidget* parent)
    : QWidget(parent)
{
    QGroupBox* permissionsGroup = new QGroupBox(tr("Permissions"));

    QCheckBox* readable = new QCheckBox(tr("Readable"));
    if (fileInfo.isReadable())
        readable->setChecked(true);

    QCheckBox* writable = new QCheckBox(tr("Writable"));
    if (fileInfo.isWritable())
        writable->setChecked(true);

    QCheckBox* executable = new QCheckBox(tr("Executable"));
    if (fileInfo.isExecutable())
        executable->setChecked(true);

    QGroupBox* ownerGroup = new QGroupBox(tr("Ownership"));

    QLabel* ownerLabel = new QLabel(tr("Owner"));
    QLabel* ownerValueLabel = new QLabel(fileInfo.owner());
    ownerValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QLabel* groupLabel = new QLabel(tr("Group"));
    QLabel* groupValueLabel = new QLabel(fileInfo.group());
    groupValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QVBoxLayout* permissionsLayout = new QVBoxLayout;
    permissionsLayout->addWidget(readable);
    permissionsLayout->addWidget(writable);
    permissionsLayout->addWidget(executable);
    permissionsGroup->setLayout(permissionsLayout);

    QVBoxLayout* ownerLayout = new QVBoxLayout;
    ownerLayout->addWidget(ownerLabel);
    ownerLayout->addWidget(ownerValueLabel);
    ownerLayout->addWidget(groupLabel);
    ownerLayout->addWidget(groupValueLabel);
    ownerGroup->setLayout(ownerLayout);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(permissionsGroup);
    mainLayout->addWidget(ownerGroup);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}
//! [7]

//! [8]
ApplicationsTab::ApplicationsTab(const QFileInfo& fileInfo, QWidget* parent)
    : QWidget(parent)
{
    QLabel* topLabel = new QLabel(tr("Open with:"));

    QListWidget* applicationsListBox = new QListWidget;
    QStringList applications;

    for (int i = 1; i <= 30; ++i)
        applications.append(tr("Application %1").arg(i));
    applicationsListBox->insertItems(0, applications);

    QCheckBox* alwaysCheckBox;

    if (fileInfo.suffix().isEmpty())
        alwaysCheckBox = new QCheckBox(tr("Always use this application to "
            "open this type of file"));
    else
        alwaysCheckBox = new QCheckBox(tr("Always use this application to "
            "open files with the extension '%1'").arg(fileInfo.suffix()));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(topLabel);
    layout->addWidget(applicationsListBox);
    layout->addWidget(alwaysCheckBox);
    setLayout(layout);
}
//! [8]
*/

//allam 16-9-2022
qtTab::qtTab(int width, int height, QWidget* parent)
    : QWidget(parent)
{
    QSizePolicy sizePolicy_w(QSizePolicy::Preferred, QSizePolicy::Preferred);    
    setSizePolicy(sizePolicy_w);    
    resize(width,height);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    //mainLayout->addWidget(this);
    //mainLayout->addWidget(buttonBox);
    //setLayout(mainLayout);

    splitter = new QSplitter(this);
    splitter->setObjectName(QString::fromUtf8("splitter"));
    splitter->setOrientation(Qt::Vertical);
    QSizePolicy sizePolicy_sp(QSizePolicy::Expanding, QSizePolicy::Expanding);
    splitter->setSizePolicy(sizePolicy_sp);
    splitter->resize(width-30, height-70);

    
    layout_H_label = new QGridLayout();
    QWidget* topWidget = new QWidget(this);
    topWidget->setLayout(layout_H_label);

    label_ = new QLabel(topWidget);
    label_->setObjectName(QString::fromUtf8("label"));
    //label_->setMinimumSize(QSize(0, pixelsHigh));
    //label_->setMaximumSize(QSize(16777215, pixelsHigh));
    //label_->setMaximumSize(contentsRect().size());

    //label_->setText("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    pushButton = new QPushButton(topWidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    //pushButton->setLayout(layout_H_label);
    layout_H_label->addWidget(label_,0,1);
    layout_H_label->addWidget(pushButton,0,0);

    
    
    layout_V_table = new QVBoxLayout();
    QWidget* bottomWidget = new QWidget(this);
    bottomWidget->setLayout(layout_V_table);

    tableView_ = new TableView(bottomWidget);
    tableView_->setObjectName(QString::fromUtf8("tableView"));
    tableView_->resize(width,height);
    //tableView_->setLayout(layout_H_table);
    layout_V_table->addWidget(tableView_);

    layout_V_plot = new QVBoxLayout();
    QWidget* plotWidget = new QWidget(this);
    plotWidget->setLayout(layout_V_plot);
    plotWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //plotWidget->setMinimumWidth(splitter->width());
    splitter->addWidget(topWidget);
    splitter->addWidget(bottomWidget);
    splitter->addWidget(plotWidget);
    //splitter->updateGeometry();
    //Plot_ = new Plot(splitter->width(), splitter->height(), current_monowave_class_ptr_m, bottomWidget);
    //Plot_ = new Plot(current_monowave_class_ptr_m, bottomWidget);
    Plot_ = new Plot(csv_to_monowave_vectors_pointer_m, plotWidget);

    Plot_->setObjectName(QString::fromUtf8("qwtplot"));
    Plot_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //Plot_->resize(geometry().size());
    layout_V_plot->addWidget(Plot_);

   

    //splitter->showMaximized();
    label_->setText(QApplication::translate("QT_Multithreaded_Cuda", "TextLabel", nullptr));
    pushButton->setText(QApplication::translate("QT_Multithreaded_Cuda", "Resume_thread", nullptr));
    connect(this->pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
    connect(tableView_, SIGNAL(showRowHeaderNameSignal(QString)), this, SLOT(showRowHeaderName(QString)));

}
void qtTab::showRowHeaderName(QString text) const
{
    label_->setText(text);
}

void tabWidget::updatingTable(csv_min_time_with_price_difference* current_monowave_class_ptr, int degree)
{
    // allocate resources using new here
    qDebug("Hello World!  updating table now from tabWidget");
    csv_to_monowave_vectors_pointer_m = current_monowave_class_ptr;
    setCurrentIndex(degree + 10);
    tab_ptr_vector[(degree + 10)]->updatingTable(csv_to_monowave_vectors_pointer_m);
    //model_ = new MatrixModel(current_monowave_class_ptr);
    //tableView_->setModel(model_);

}

void tabWidget::plottingGraph(csv_min_time_with_price_difference* current_monowave_class_ptr, int degree)
{
    // allocate resources using new here
    qDebug("Hello World!  plottingGraph now from tabWidget");
    csv_to_monowave_vectors_pointer_m = current_monowave_class_ptr;
    setCurrentIndex(degree+10);
    tab_ptr_vector[(degree + 10)]->plottingGraph(csv_to_monowave_vectors_pointer_m);
    //model_ = new MatrixModel(current_monowave_class_ptr);
    //tableView_->setModel(model_);

}
void qtTab::pushButtonClicked()
{
    mutex.lock();   
    updateTable_waiting.wakeAll();
    plotGraph_waiting.wakeAll();

    qDebug("Hello World!  plotGraph_waiting.wakeAll()");
    mutex.unlock();

}
void qtTab::updatingTable(csv_min_time_with_price_difference* current_monowave_class_ptr)
{
    // allocate resources using new here
    qDebug("Hello World!  updating table now from qtTab");
    csv_to_monowave_vectors_pointer_m = current_monowave_class_ptr;

    model_ = new MatrixModel(csv_to_monowave_vectors_pointer_m);
    tableView_->setModel(model_);

}
void qtTab::plottingGraph(csv_min_time_with_price_difference* current_monowave_class_ptr)
{
    // allocate resources using new here
    qDebug("Hello World!  plottingGraph now from qtTab");
    csv_to_monowave_vectors_pointer_m = current_monowave_class_ptr;
    
    Plot_->curve->setData(NULL);
    Plot_->plotLayout()->setCanvasMargin(4);
    //Plot_->d_hScrollData= new ScrollData;

    //Plot_->curve = new QwtPlotCurve();
    //Plot_->curve->attach(Plot_);

    //15-10-2022 the following is using pointers instead of copying data to Qvector
    //   Array Sizes
    Size = current_monowave_class_ptr->askPrice.size();
    const int CurvCnt = 1;
    //
    //   Arrays holding the values
    //
    //double xval[Size];
    //double yval[Size];
    //const double* xData;
    //const double* yData;
    //const unsigned int* yData_unsigned_int;
    std::vector<double> yData_vec(Size);

    //QwtScaleMap xMap;
    //QwtScaleMap yMap;
    
    QVector<double> x_q(current_monowave_class_ptr->askPrice.size()), y_q(current_monowave_class_ptr->askPrice.size());
    ////std::vector<double> x(Size);
    for (int i = 0; i < current_monowave_class_ptr->askPrice.size(); ++i)
    {
        ////x[i] = i;
        x_q[i] = i;
        //x[i] = current_monowave_class_ptr->epochpartTime[i];
        //x[i] = current_monowave_class_ptr->tickpartTime[i];
        /////y[i]= current_monowave_class_ptr->askPrice[i];
        ////yData_vec[i] = current_monowave_class_ptr->askPrice[i];
        y_q[i] = current_monowave_class_ptr->askPrice[i];
        //double newKey = keyAxis->pixelToCoord(keyAxis->coordToPixel(oldKey) + 10 * keyAxis->pixelOrientation());

    }
    ////xData = x.data();
    ////yData_unsigned_int = current_monowave_class_ptr->askPrice.data();
    ////yData = yData_vec.data();

    //yData = (const double*)yData_unsigned_int;
    //Plot_->curve->
    ////Plot_->curve->setRawSamples(xData,yData,Size);
    //QPolygonF points;
    Plot_->curve->setSamples(x_q, y_q);
    //QPointF s= Plot_->curve->sample(10);
    int zx=Plot_->canvas_->width()/45;
    int zy = Plot_->canvas_->height()/45;

    //Plot_->curve->setPen(Qt::blue, 4),
    //    Plot_->curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    // set ranges appropriate to show data:
    ////double minX = *std::min_element(x.cbegin(), x.cend());
    ////double maxX = *std::max_element(x.cbegin(), x.cend());
    ////double minY = *std::min_element(yData_vec.cbegin(), yData_vec.cend());
    ////double maxY = *std::max_element(yData_vec.cbegin(), yData_vec.cend());
    ////Plot_->setAxisScale(QwtPlot::yLeft, minY, maxY);
    ////Plot_->setAxisScale(QwtPlot::xBottom, minX, maxX);
    double minX = *std::min_element(x_q.cbegin(), x_q.cend());
    double maxX = *std::max_element(x_q.cbegin(), x_q.cend());
    double minY = *std::min_element(y_q.cbegin(), y_q.cend());
    double maxY = *std::max_element(y_q.cbegin(), y_q.cend());
    Plot_->setAxisScale(QwtPlot::yLeft, minY, minY+zy);
    //Plot_->setAxisScale(QwtPlot::xBottom, minX, maxX);
    //Plot_->setAxisScale(QwtPlot::yLeft, minY, maxY);
    Plot_->setAxisScale(QwtPlot::xBottom, minX, minX+zx);
    //Plot_->axisScaleDraw(QwtPlot::xBottom)->setLabelRotation(90);
    //axisScaleDraw(QwtPlot::xBottom)->setLabelAlignment(Qt::AlignRight);
    //setAxisFont(QwtPlot::xBottom, QFont("MS Shell Dlg 2", 9));

    //QwtScaleDiv scaleDiv =
    //    Plot_->axisScaleEngine(QwtPlot::xBottom)->divideScale(0, 100, 100, 0,1);
    QwtScaleDiv scaleDiv =  Plot_->axisScaleEngine(QwtPlot::xBottom)->divideScale(minX, minX + zx, zx+1, 0, 1);
    QList<double> ticks;
    //ticks += 0.0;
    ticks += scaleDiv.ticks(QwtScaleDiv::MajorTick);
    scaleDiv.setTicks(QwtScaleDiv::MajorTick, ticks);

    Plot_->setAxisScaleDiv(QwtPlot::xBottom, scaleDiv);
    //Plot_->curve->attach(Plot_);
    //Plot_->curve->show();
    //Plot_->d_zoomer->setZoomBase();
    //Plot_-> ->setRange(minX, minX + 10);
    //Plot_->d_mapRect = Plot_->geometry();
    //Plot_->hscroll_min = Plot_->curve->minXValue();
    //Plot_->hscroll_max = Plot_->curve->maxXValue();
    //Plot_->vscroll_min = Plot_->curve->minYValue();
    //Plot_->vscroll_max = Plot_->curve->maxYValue();
    //double y1=
    //int vy = Plot_->verticalScrollBar()->value();
    //int vx = Plot_->horizontalScrollBar()->value();
    //Plot_->verticalScrollBar()->setValue(Plot_->verticalScrollBar()->maximum());
    //Plot_->horizontalScrollBar()->setValue(Plot_->horizontalScrollBar()->maximum());
    //int vyy = Plot_->verticalScrollBar()->value();
    //int vxx = Plot_->horizontalScrollBar()->value();
    delete Plot_->d_vScrollData;
    Plot_->d_vScrollData = new ScrollData;
    Plot_->scrollBar(Qt::Vertical);
    delete Plot_->d_hScrollData ;
    Plot_->d_hScrollData = new ScrollData;
    Plot_->scrollBar(Qt::Horizontal);
    //int vxxx = Plot_->horizontalScrollBar()->value();

    //Plot_->verticalScrollBar()->value();
    //int vxxcc = Plot_->horizontalScrollBar()->value();


    Plot_->verticalScrollBar()->setd_baseTicks((Plot_->curve->maxYValue() - Plot_->curve->minYValue()) + 1);
    Plot_->verticalScrollBar()->setSingleStep(1);
    Plot_->verticalScrollBar()->setPageStep(1 * zy);
    Plot_->verticalScrollBar()->setInverted(true);
    Plot_->verticalScrollBar()->setValue(0);
    Plot_->verticalScrollBar()->setMinimum(0);
    Plot_->verticalScrollBar()->setMaximum(0);

    Plot_->verticalScrollBar()->setBase(Plot_->curve->minYValue(), Plot_->curve->maxYValue());
    //verticalScrollBar()->setBase(0, 10);
   

    Plot_->horizontalScrollBar()->setd_baseTicks((Plot_->curve->maxXValue() - Plot_->curve->minXValue()) + 1);
    Plot_->horizontalScrollBar()->setSingleStep(1);
    Plot_->horizontalScrollBar()->setPageStep(1 * zx);
    Plot_->horizontalScrollBar()->setValue(0);
    Plot_->horizontalScrollBar()->setMinimum(0);
    Plot_->horizontalScrollBar()->setMaximum(0);

    Plot_->horizontalScrollBar()->setBase(Plot_->curve->minXValue(), Plot_->curve->maxXValue());
    //horizontalScrollBar()->setBase(10, 1000);
    //horizontalScrollBar()->setd_baseTicks(1000 - 10);
    
    Plot_-> updateScrollBars();

    Plot_->replot();
    /*
     Plot_->setgraph(0)->setData(x, y);
    // set ranges appropriate to show data:
    double minX = *std::min_element(x.constBegin(), x.constEnd());
    double maxX = *std::max_element(x.constBegin(), x.constEnd());
    double minY = *std::min_element(y.constBegin(), y.constEnd());
    double maxY = *std::max_element(y.constBegin(), y.constEnd());

     Plot_->xAxis->setRange(minX, minX+10);
    // Plot_->yAxis->setRange(minY, minY+10);
     Plot_->yAxis->setRange(y[minX], y[minX+10] );
    //horizontalScrollBar->setRange(minX, (minX) + 100);
    //verticalScrollBar->setRange(y[minX], (y[minX] )+ 100);
    /
    ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->customPlot->xAxis->setDateTimeFormat("h:mm");

    ui->customPlot->xAxis->setAutoTickStep(false);   // <-- disable to use your own value

    ui->customPlot->xAxis->setTickStep(7200);
    /
    // set labels:
     Plot_->xAxis->setLabel("Bottom axis with outward ticks time");
     Plot_->yAxis->setLabel("Left axis label askprice");
    // make ticks on bottom axis go outward:
     Plot_->xAxis->setTickLength(0, 5);
     Plot_->xAxis->setSubTickLength(0, 3);
     Plot_->yAxis->setTickLength(0, 5);
     Plot_->yAxis->setSubTickLength(0, 3);
    // let setScaleRatio change yAxis range:
     Plot_->yAxis->setScaleRatio( Plot_->xAxis, 1.0);
    // Plot_->rescaleAxes();
     Plot_->replot();
    //QWaitCondition resumeThread;
    //resumeThread.wakeAll();
    //plotGraph_waiting.wakeAll();

    //csv_to_monowave_vectors_instance = csv_time_bid_ask_difference(this);
    //current_monowave_class_ptr = &csv_to_monowave_vectors_instance;

    //emit finished();
}

*/
   

}