#include "plot.h"

const unsigned int c_rangeMax = 1000;

class Zoomer : public ScrollZoomer
{
public:
    Zoomer(QWidget* canvas) :
        ScrollZoomer(canvas)
    {
#if 0
        setRubberBandPen(QPen(Qt::red, 2, Qt::DotLine));
#else
        setRubberBandPen(QPen(Qt::red));
#endif
    }

    virtual QwtText trackerTextF(const QPointF& pos) const
    {
        QColor bg(Qt::white);

        QwtText text = QwtPlotZoomer::trackerTextF(pos);
        text.setBackgroundBrush(QBrush(bg));
        return text;
    }

    virtual void rescale()
    {
        QwtScaleWidget* scaleWidget = plot()->axisWidget(yAxis());
        QwtScaleDraw* sd = scaleWidget->scaleDraw();

        double minExtent = 0.0;
        if (zoomRectIndex() > 0)
        {
            // When scrolling in vertical direction
            // the plot is jumping in horizontal direction
            // because of the different widths of the labels
            // So we better use a fixed extent.

            minExtent = sd->spacing() + sd->maxTickLength() + 1;
            minExtent += sd->labelSize(
                scaleWidget->font(), c_rangeMax).width();
        }

        sd->setMinimumExtent(minExtent);

        ScrollZoomer::rescale();
    }
};
Plot::~Plot()
{
    delete curve;
    delete grid;
    delete symbol;
    delete d_vScrollData;
    delete d_hScrollData;

}
void Plot::replot()
{
    //QwtPlot::replot();
    //updateScrollBars();
    //canvas_->updateGeometry();
    layoutScrollBars(canvas_->contentsRect());
    QwtPlot::replot();
   
}
void Plot::rescale()
{
    QwtScaleWidget* xScale = axisWidget(QwtPlot::xBottom);
    QwtScaleWidget* yScale = axisWidget(QwtPlot::yLeft);
    int zx = canvas_->width() / 45;
    int zy = canvas_->height() / 45;
    double x =axisScaleDiv(QwtPlot::xBottom).lowerBound();
    double y =axisScaleDiv(QwtPlot::yLeft).lowerBound();
    setAxisScale(QwtPlot::xBottom, axisScaleDiv(QwtPlot::xBottom).lowerBound(), axisScaleDiv(QwtPlot::xBottom).lowerBound() + zx);
    setAxisScale(QwtPlot::yLeft, axisScaleDiv(QwtPlot::yLeft).lowerBound()
    , axisScaleDiv(QwtPlot::yLeft).lowerBound() + zy);
    replot();
}
//Plot::Plot(int width, int height, csv_to_monowave_bin* current_monowave_class_ptr, QWidget* parent) :
    Plot::Plot(csv_min_time_with_price_difference* current_monowave_class_ptr, QWidget* parent) :
    current_monowave_class_ptr_m_plot(current_monowave_class_ptr), QwtPlot(parent),
    //d_mapRect(0,0,0,0),
    d_hScrollData(NULL),
    d_vScrollData(NULL),
    d_cornerWidget(NULL)
{
    //setTitle("Plot Demo");

    //margin = horizontalScrollBar()->rect().height();
    //margin = 17;
    //setContentsMargins(margin, margin, margin, margin);
    //int x = frameGeometry().width(); int y = frameGeometry().height();
    //int xx = this->geometry().width(); int yy = geometry().height();
    //int xxx = width(); int yyy = height();

    //resize( width,height);
    //resize(frameGeometry().width() , frameGeometry().height());
    //QString z=parentWidget()->accessibleName();
    //scrollbar settings
    d_hScrollData = new ScrollData;
    d_vScrollData = new ScrollData;

    //zoom settings
    // enable zooming
    //d_zoomer = new Zoomer(canvas());

    //panner settings
    //d_panner = new QwtPlotPanner(canvas());
    //d_panner->setMouseButton(Qt::MidButton);

    //picker settings
    //d_picker = new QwtPlotPicker(canvas());
    //d_picker->setTrackerMode(QwtPlotPicker::AlwaysOn);
    //d_picker = new QwtPlotPicker(QwtPlot::xBottom, QwtPlot::yLeft,        QwtPlotPicker::CrossRubberBand, QwtPicker::AlwaysOn,        d_plot->canvas());
    //d_picker->setStateMachine(new QwtPickerDragPointMachine());
    //d_picker->setRubberBandPen(QColor(Qt::green));
    //d_picker->setRubberBand(QwtPicker::CrossRubberBand);
    //d_picker->setTrackerPen(QColor(Qt::white));
    //canvas settings
    canvas_ = new QwtPlotCanvas();
    canvas_->setBorderRadius(0);//this represents corner of border curve radius

    setCanvas(canvas_);
    //plotLayout()->setAlignCanvasToScales(true);
    setCanvasBackground(Qt::white);

    //22-12-21// period as decimal separator and comma as thousand separator
    setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); 

    //grid settings
    QwtPlotGrid* grid = new QwtPlotGrid();
    grid->setMajorPen(Qt::gray, 0, Qt::DotLine);
    grid->setMinorPen(Qt::black, 0, Qt::DashLine);
    grid->enableXMin(true);
    grid->attach(this);

    //curve settings
    curve = new QwtPlotCurve();
    curve->setTitle("Bid Price");
    curve->setPen(Qt::blue, 4), curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    //22-12-21
    curve->setBrush(QBrush(QPixmap("./balboa.jpg"))); // same fill as we used for curve
    QwtSymbol* symbol = new QwtSymbol(QwtSymbol::Ellipse,
        QBrush(Qt::yellow), QPen(Qt::red, 2), QSize(8, 8));
    curve->setSymbol(symbol);

    //axes settings
    //setAxisScale(QwtPlot::yLeft, 0.0, 10.0 );
    QwtScaleWidget* scaleWidget_H = axisWidget(QwtPlot::xBottom);
    const int fmh_H = QFontMetrics(scaleWidget_H->font()).height();
    scaleWidget_H->setMinBorderDist(0, fmh_H / 2);
    //scaleWidget_H->setMinBorderDist(20, 40);

    //scaleWidget_H->setColorBarEnabled(true);
    //int wth=scaleWidget_H->colorBarWidth();
    //scaleWidget_H->setMargin(17);

    QwtScaleWidget* scaleWidget_V = axisWidget(QwtPlot::yLeft);
    const int fmh_V = QFontMetrics(scaleWidget_V->font()).height();
    scaleWidget_V->setMinBorderDist(0, fmh_V / 2);
    //scaleWidget_V->setMinBorderDist(0, 70);
    //scaleWidget_V-;
    //scaleWidget_V->setMargin(17);

    setTransformation1(new QwtNullTransform());
    populate();
    //hscroll_min = curve->minXValue();
    //hscroll_max = curve->maxXValue();
    //vscroll_min = curve->minYValue();
    //vscroll_max = curve->maxYValue();

    //updateScrollBars();
    replot();
}

void Plot::populate()
{   
    //allam here we create points and add them to curve    
    QPolygonF points;
    points << QPointF( 10.0, 4.4 )
        << QPointF( 100.0, 3.0 ) << QPointF( 200.0, 4.5 )
        << QPointF( 300.0, 6.8 ) << QPointF( 400.0, 7.9 )
        << QPointF( 500.0, 7.1 ) << QPointF( 600.0, 7.9 )
        << QPointF( 700.0, 7.1 ) << QPointF( 800.0, 5.4 )
        << QPointF( 900.0, 2.8 ) << QPointF( 1000.0, 3.6 );
    curve->setSamples( points );
    setAxisScale(QwtPlot::yLeft, curve->minYValue(), curve->maxYValue());
    verticalScrollBar()->setd_baseTicks(axisMaxMajor(QwtPlot::yLeft) * axisMaxMinor(QwtPlot::yLeft) / 8);
    verticalScrollBar()->setSingleStep(1);
    verticalScrollBar()->setPageStep(1 * 2);
    verticalScrollBar()->setInverted(true);
    verticalScrollBar()->setBase(curve->minYValue(), curve->maxYValue());
    //verticalScrollBar()->setBase(0, 10);

    horizontalScrollBar()->setd_baseTicks(curve->maxXValue() - curve->minXValue());
    //horizontalScrollBar()->setd_baseTicks(1000 - 10);
    horizontalScrollBar()->setSingleStep(1);
    horizontalScrollBar()->setPageStep(1 * 30);
    horizontalScrollBar()->setBase(curve->minXValue(), curve->maxXValue());
    //horizontalScrollBar()->setBase(10, 1000);

    
    //d_zoomer->setZoomBase();
    //hscroll_min = curve->minXValue();
    //hscroll_max = curve->maxXValue();
    //vscroll_min = curve->minYValue();
    //vscroll_max = curve->maxYValue();
    updateScrollBars();

    curve->attach( this );
}
void Plot::setTransformation1(QwtTransform* transform)
{
    setAxisScale(QwtPlot::yLeft, 0.0, 10.0);
    //d_zoomer->setZoomBase();
    QwtLinearScaleEngine* scaleEngine = new QwtLinearScaleEngine();
    scaleEngine->setTransformation(transform);

    setAxisScaleEngine(QwtPlot::xBottom, scaleEngine);

    // we have to reassign the axis settinge, because they are
    // invalidated, when the scale engine has changed

    QwtScaleDiv scaleDiv =
        axisScaleEngine(QwtPlot::xBottom)->divideScale(10.0, 1000.0, 8, 10);

    QList<double> ticks;
    ticks += 10.0;
    ticks += scaleDiv.ticks(QwtScaleDiv::MajorTick);
    scaleDiv.setTicks(QwtScaleDiv::MajorTick, ticks);

    setAxisScaleDiv(QwtPlot::xBottom, scaleDiv);
    //hscroll_min = curve->minXValue();
    //hscroll_max = curve->maxXValue();
    //vscroll_min = curve->minYValue();
    //vscroll_max = curve->maxYValue();
    updateScrollBars();

    replot();
}
void Plot::setTransformation(csv_min_time_with_price_difference* current_monowave_class_ptr, QwtTransform *transform )
{
    QwtLinearScaleEngine *scaleEngine = new QwtLinearScaleEngine();
    scaleEngine->setTransformation( transform );

    setAxisScaleEngine( QwtPlot::xBottom, scaleEngine );

    // we have to reassign the axis settinge, because they are
    // invalidated, when the scale engine has changed

    //if (current_monowave_class_ptr->askPrice.size()==0)
    //{
        //25-12-21 the next line should recieve the starting and ending time involved and the mintimeunit to be used
        int startTime, endTime, mintimeunit = 50;
        size_t sizeArray = (current_monowave_class_ptr->epochpartTime.size()) - 1;
        startTime = current_monowave_class_ptr->epochpartTime[0] + current_monowave_class_ptr->tickpartTime[0];
        endTime = current_monowave_class_ptr->epochpartTime[sizeArray] + current_monowave_class_ptr->tickpartTime[sizeArray];
        // we have to reassign the axis settinge, because they are
    // invalidated, when the scale engine has changed
        //we STILL need to convert start and end time from int to datetime
        QwtScaleDiv scaleDiv =
            axisScaleEngine(QwtPlot::xBottom)->divideScale(startTime, endTime, 50, 1000, 50);
    //}
    
    
    // we have to reassign the axis settinge, because they are
    // invalidated, when the scale engine has changed
   // QwtScaleDiv scaleDiv = axisScaleEngine(QwtPlot::xBottom)->divideScale(10.0, 1000.0, 8, 10);

    QList<double> ticks;
    ticks += 50.0;
    ticks += scaleDiv.ticks( QwtScaleDiv::MajorTick );
    scaleDiv.setTicks( QwtScaleDiv::MajorTick, ticks );

    setAxisScaleDiv( QwtPlot::xBottom, scaleDiv );
    //d_zoomer->setZoomBase();
    //hscroll_min = curve->minXValue();
    //hscroll_max = curve->maxXValue();
    //vscroll_min = curve->minYValue();
    //vscroll_max = curve->maxYValue();
    updateScrollBars();
    replot();
}
/*
void Plot::rescale()
{
    setAxisScale(QwtPlot::xBottom,
        d_mapRect.left(), d_mapRect.right());
    setAxisScale(QwtPlot::yLeft,
        d_mapRect.top(), d_mapRect.bottom());
    //d_zoomer->setZoomBase();

}
*/