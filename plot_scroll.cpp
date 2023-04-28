#include "plot.h"


/*
void Plot::moveTo(const QPointF& pos)
{
    double x = pos.x();
    double y = pos.y();

    if (x < curve->minXValue();)
        x = curve->minXValue();;
    if (x > curve->maxXValue() )
        x = curve->maxXValue();

    if (y < vscroll_min)
        y = vscroll_min;
    if (y > vscroll_max)
        y = vscroll_max;

    if (x != zoomRect().left() || y != zoomRect().top())
    {
        d_data->zoomStack[d_data->zoomRectIndex].moveTo(x, y);
        rescale();
    }
}
*/
/*
ui->horizontalScrollBar->setRange(-500, 500);
ui->verticalScrollBar->setRange(-500, 500);

connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));
connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(vertScrollBarChanged(int)));
connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));
void MainWindow::horzScrollBarChanged(int value)
{
    if (qAbs(ui->plot->xAxis->range().center() - value / 100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
    {
        ui->plot->xAxis->setRange(value / 100.0, ui->plot->xAxis->range().size(), Qt::AlignCenter);
        ui->plot->replot();
    }
}

void MainWindow::vertScrollBarChanged(int value)
{
    if (qAbs(ui->plot->yAxis->range().center() + value / 100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
    {
        ui->plot->yAxis->setRange(-value / 100.0, ui->plot->yAxis->range().size(), Qt::AlignCenter);
        ui->plot->replot();
    }
}
*/
void Plot::scrollBarMoved(
    Qt::Orientation o, int value)
{
    int zx = canvas_->width() / 45;
    int zy = canvas_->height() / 45;

    //Q_UNUSED(max);
    if (o == Qt::Horizontal)
    {
        //here we build on setup that x axis is formed of x int points with single step =1 and page step =50  
        //setAxisScale(QwtPlot::xBottom, minX, minX + 49);
        //if (qAbs(((axisMaxMajor(QwtPlot::xBottom)-axisMaxMinor(QwtPlot::xBottom))/2) - (min+((max-min)/2))) > 1) // if user is dragging plot, we don't want to replot twice
        if (qAbs(((curve->maxXValue() - curve->minXValue()) / 2) - (value)) > 1) // if user is dragging plot, we don't want to replot twice
        {
            //int value_scroll = (min + ((max - min) / 2));

            //setAxisScale(QwtPlot::xBottom, (curve->minXValue() + value_scroll),curve->maxXValue() - value_scroll);
            //setAxisScale(QwtPlot::xBottom, axisScaleDiv(QwtPlot::xBottom).lowerBound()+value, axisScaleDiv(QwtPlot::xBottom).upperBound()+value);
            setAxisScale(QwtPlot::xBottom,  value+curve->minXValue(), value+curve->minXValue()+zx);

            //ui->plot->xAxis->setRange(value / 100.0, ui->plot->xAxis->range().size(), Qt::AlignCenter);
            replot();
        }

    }
    //moveTo(QPointF(min, zoomRect().top()));-value + curve->maxYValue()
    else
        if (qAbs(((curve->maxYValue() - curve->minYValue()) / 2) - (value)) > 1) // if user is dragging plot, we don't want to replot twice
        {
            //setAxisScale(QwtPlot::yLeft, axisScaleDiv(QwtPlot::yLeft).lowerBound() + value, axisScaleDiv(QwtPlot::yLeft).upperBound() + value);
            //setAxisScale(QwtPlot::yLeft,  value + curve->minYValue() , value + curve->minYValue()+zy);
            verticalScrollBar()->setInverted(true);
            //ScrollBar* sb = verticalScrollBar();
            int value_org = value;
            //value = (curve->maxYValue() - curve->minYValue()) - value;
            //double min, max;
            //verticalScrollBar()->sliderRange(value, min, max);
            //setAxisScale(QwtPlot::yLeft, value + curve->minYValue()-5, value + curve->minYValue() +zy-5);
            //setAxisScale(QwtPlot::yLeft, value_org + curve->minYValue() -value, value_org + curve->minYValue() + zy - value);
            //setAxisScale(QwtPlot::yLeft, curve->minYValue() + value,  curve->minYValue() + zy + value);
            int z = verticalScrollBar()->d_baseTicks;
            int sliderticks = z - verticalScrollBar()->maximum();
            setAxisScale(QwtPlot::yLeft, curve->maxYValue() - value - sliderticks, curve->maxYValue() - value);

            //setAxisScale(QwtPlot::yLeft, curve->maxYValue() - value -zy, curve->maxYValue()  - value);
            //we might think of calculating slider ticks and subtract them instead of zy
            //ui->plot->yAxis->setRange(-value / 100.0, ui->plot->yAxis->range().size(), Qt::AlignCenter);
            replot();
        }
    //moveTo(QPointF(zoomRect().left(), min));

//Q_EMIT zoomed(zoomRect());
}
void Plot::scrollBarMoved(
    Qt::Orientation o, double min, double max)
{
    Q_UNUSED(max);
    if (o == Qt::Horizontal) 
    {
        //here we build on setup that x axis is formed of x int points with single step =1 and page step =50  
        //setAxisScale(QwtPlot::xBottom, minX, minX + 49);
        //if (qAbs(((axisMaxMajor(QwtPlot::xBottom)-axisMaxMinor(QwtPlot::xBottom))/2) - (min+((max-min)/2))) > 1) // if user is dragging plot, we don't want to replot twice
        if (qAbs(((curve->maxXValue() - curve->minXValue()) / 2) - (min + ((max - min) / 2))) > 1) // if user is dragging plot, we don't want to replot twice
        {
            int value_scroll = (min + ((max - min) / 2));

            //setAxisScale(QwtPlot::xBottom, (curve->minXValue() + value_scroll),curve->maxXValue() - value_scroll);
            setAxisScale(QwtPlot::xBottom, min, max);
            //ui->plot->xAxis->setRange(value / 100.0, ui->plot->xAxis->range().size(), Qt::AlignCenter);
            replot();
        }

    }
        //moveTo(QPointF(min, zoomRect().top()));
    else
         if (qAbs(((curve->maxYValue() - curve->minYValue()) / 2) - (min + ((max - min) / 2))) > 1) // if user is dragging plot, we don't want to replot twice
         {
             setAxisScale(QwtPlot::yLeft, min, max);
             //ui->plot->yAxis->setRange(-value / 100.0, ui->plot->yAxis->range().size(), Qt::AlignCenter);
             replot();
         }
        //moveTo(QPointF(zoomRect().left(), min));

    //Q_EMIT zoomed(zoomRect());
}
/*
void Plot::moveTo_scroll(const QPointF& pos)
{
    double x = pos.x();
    double y = pos.y();

    if (x < zoomBase().left())
        x = zoomBase().left();
    if (x > zoomBase().right() - zoomRect().width())
        x = zoomBase().right() - zoomRect().width();

    if (y < zoomBase().top())
        y = zoomBase().top();
    if (y > zoomBase().bottom() - zoomRect().height())
        y = zoomBase().bottom() - zoomRect().height();

    if (x != zoomRect().left() || y != zoomRect().top())
    {
        d_data->zoomStack[d_data->zoomRectIndex].moveTo(x, y);
        rescale();
    }
}
*/
ScrollBar* Plot::scrollBar(Qt::Orientation orientation)
{
    ScrollBar*& sb = (orientation == Qt::Vertical)
        ? d_vScrollData->scrollBar : d_hScrollData->scrollBar;

    if (sb == NULL)
    {
        sb = new ScrollBar(orientation, canvas());
        //sb = new ScrollBar(orientation, this);//here we create scrollbar for first time

        //sb->hide();
        //connect(sb,
        //    SIGNAL(valueChanged(Qt::Orientation, double, double)),
        //    SLOT(scrollBarMoved(Qt::Orientation, double, double)));
            //SLOT(sliderMoved(Qt::Orientation, double, double)));
        //connect(sb,
        //    SIGNAL(sliderMoved(Qt::Orientation, double, double)),
        //    SLOT(scrollBarMoved(Qt::Orientation, double, double)));
        connect(sb,
            SIGNAL(valueChanged(Qt::Orientation, int)),
            SLOT(scrollBarMoved(Qt::Orientation, int)));
        //SLOT(sliderMoved(Qt::Orientation, double, double)));
        connect(sb,
            SIGNAL(sliderMoved(Qt::Orientation, int)),
            SLOT(scrollBarMoved(Qt::Orientation, int)));


    }
    return sb;
}
bool Plot::eventFilter(QObject* object, QEvent* event)
{
    if (object == canvas())
    {
        switch (event->type())
        {
        case QEvent::Resize:
        {
            
            int left, top, right, bottom;
            canvas()->getContentsMargins(&left, &top, &right, &bottom);

            QRect rect;
            rect.setSize(static_cast<QResizeEvent*>(event)->size());
            rect.adjust(left, top, -right, -bottom);
            rescale();
            layoutScrollBars(rect);
            break;
        }
        case QEvent::ChildRemoved:
        {
            const QObject* child =
                static_cast<QChildEvent*>(event)->child();

            if (child == d_cornerWidget)
                d_cornerWidget = NULL;
            else if (child == d_hScrollData->scrollBar)
                d_hScrollData->scrollBar = NULL;
            else if (child == d_vScrollData->scrollBar)
                d_vScrollData->scrollBar = NULL;
            break;
        }
        default:
            break;
        }
    }
    //return QwtPlotZoomer::eventFilter(object, event);
    return false;

}

void Plot::layoutScrollBars(const QRect& rect)
{
    QwtScaleWidget* scaleWidget_H = axisWidget(QwtPlot::xBottom);
    QwtScaleWidget* scaleWidget_V = axisWidget(QwtPlot::yLeft);

    int hPos = QwtPlot::xBottom;
    if (hScrollBarPosition() == OppositeToScale)
        hPos = oppositeAxis(hPos);

    int vPos = QwtPlot::yLeft;
    if (vScrollBarPosition() == OppositeToScale)
        vPos = oppositeAxis(vPos);

    ScrollBar* hScrollBar = horizontalScrollBar();
    ScrollBar* vScrollBar = verticalScrollBar();

    const int hdim = hScrollBar ? hScrollBar->extent() : 0;
    const int vdim = vScrollBar ? vScrollBar->extent() : 0;
    //hScrollBar->setVisible(true);
    //vScrollBar->setVisible(true);
    //if (hScrollBar)
    //{ 
    //    hScrollBar->setVisible(true);

    //}
    //if (!hScrollBar->isVisible())
    //{
    //    hScrollBar->setVisible(true);

    //}
    //hScrollBar->show();
    if (hScrollBar )
    //if (hScrollBar && hScrollBar->isVisible())
    {
        int x = rect.x();
        //int x = (rect.x()+ scaleWidget_V->width())- scaleWidget_V->margin();
        int y = (hPos == QwtPlot::xTop)
            ? rect.top() : rect.bottom() - hdim + 1;
        //int y = (hPos == QwtPlot::xTop)
        //   ? rect.top() :( rect.bottom() - ( scaleWidget_H->height() ) )+ 1;
        int w = rect.width();
        //int w = rect.width() - (scaleWidget_V->width());

        //if (vScrollBar && vScrollBar->isVisible())
        if (vScrollBar )
        {
            if (vPos == QwtPlot::yLeft)
                x += vdim;
            w -= vdim;
        }

        hScrollBar->setGeometry(x, y, w, hdim);
        //hScrollBar->setGeometry(x, 467, w, hdim);
    }
    //if (vScrollBar && vScrollBar->isVisible())
    if (vScrollBar)
    {
        int pos = QwtPlot::yLeft;
        if (vScrollBarPosition() == OppositeToScale)
            pos = oppositeAxis(pos);

        int x = (vPos == QwtPlot::yLeft)
            ? rect.left() : rect.right() - vdim + 1;
        //int x = (vPos == QwtPlot::yLeft)
        //    ? rect.left()+ scaleWidget_V->width() - scaleWidget_V->margin() : rect.right() - vdim + 1;
        int y = rect.y();
        //int y = rect.y();

        int h = rect.height();
        //int h = (rect.height()- scaleWidget_H->height())+ scaleWidget_H->margin();

        //if (hScrollBar && hScrollBar->isVisible())
        if (hScrollBar)
        {
            if (hPos == QwtPlot::xTop)
                y += hdim;

            h -= hdim;
        }

        vScrollBar->setGeometry(x, y, vdim, h);
        //vScrollBar->setGeometry(x, 1000, vdim, h);

    }
    //if (hScrollBar && hScrollBar->isVisible() && vScrollBar && vScrollBar->isVisible())
    if (hScrollBar  && vScrollBar)
    {
        if (d_cornerWidget)
        {
            QRect cornerRect(
                vScrollBar->pos().x(), hScrollBar->pos().y(),
                vdim, hdim);
            d_cornerWidget->setGeometry(cornerRect);
        }
    }
}

void Plot::updateScrollBars()
{
    if (!canvas())
        return;
    int zx = canvas_->width() / 45;
    int zy = canvas_->height() / 45;

    const int xAxis = QwtPlot::xBottom;
    const int yAxis = QwtPlot::yLeft;

    int xScrollBarAxis = xAxis;
    if (hScrollBarPosition() == OppositeToScale)
        xScrollBarAxis = oppositeAxis(xScrollBarAxis);

    int yScrollBarAxis = yAxis;
    if (vScrollBarPosition() == OppositeToScale)
        yScrollBarAxis = oppositeAxis(yScrollBarAxis);


    QwtPlotLayout* layout = plotLayout();

    bool showHScrollBar = needScrollBar(Qt::Horizontal);
    if (showHScrollBar)
    {
        ScrollBar* sb = scrollBar(Qt::Horizontal);
        //sb->setGeometry(x()+17,y(),width(),17);
        sb->setPalette(palette());
        sb->setInverted(!axisScaleDiv(xAxis).isIncreasing());
        sb->setd_baseTicks((curve->maxXValue() - curve->minXValue()) + 1);
        sb->setSingleStep(1);//we should make it sb->setSingleStep(1*factor)where factor default is 1
        sb->setPageStep(1 * zx);
        int mi=sb->minimum();
        int mx=sb->maximum();
        int mv=sb->value();
        sb->setBase(curve->minXValue(), curve->maxXValue());
        //verticalScrollBar()->setBase(0, 10);
        //double minx, maxx;
        //minx = curve->minXValue();
        //maxx = curve->maxXValue();
        //sb->setBase(curve->minXValue(), curve->maxXValue());
        //double minx, maxx;
        //minx = contentsRect().left();
        //maxx = contentsRect().right();
        //sb->setBase(contentsRect().left(), contentsRect().right());

        //sb->setVisible(true);
        //sb->moveSlider(curve->minXValue(), curve->maxXValue());//originally zoomRect from scrollzoomer
        sb->moveSlider(curve->minXValue(), curve->minXValue()+sb->pageStep());//originally zoomRect from scrollzoomer
        //scrollBarMoved(sb->orientation(), curve->minXValue(), curve->minXValue() + sb->pageStep());
        //Q_EMIT sb->valueChanged(sb->orientation(),curve->minXValue(), curve->minXValue() + sb->pageStep());
        //axisScaleEngine(2)->lowerMargin()
        //Q_EMIT verticalScrollBar()->valueChanged(Qt::Vertical, curve->minXValue() , curve->minYValue() + sb->pageStep());

        //Q_EMIT sb->sliderMoved(sb->orientation(), curve->minXValue(), curve->minXValue() + sb->pageStep());


        //sb->moveSlider(contentsRect().left(), contentsRect().right());//originally zoomRect from scrollzoomer
        //sb->show();
        //if (!sb->isVisibleTo(canvas()))
        //if (!sb->isVisibleTo(this))
        if(sb)
        {
            sb->show();
            //margin_h = margin+ sb->extent();
            //setContentsMargins(margin, margin_h, margin, margin);
            //int z = sb->extent();
            //layout->setCanvasMargin(layout->canvasMargin(xScrollBarAxis) + sb->extent()+ (layout->scaleRect(xScrollBarAxis).height()), xScrollBarAxis);
            layout->setCanvasMargin(layout->canvasMargin(xScrollBarAxis) + sb->extent(), xScrollBarAxis);

        }
    }
    else
    {
        if (horizontalScrollBar())
        {
            //horizontalScrollBar()->hide();
            //margin_h = margin + horizontalScrollBar()->extent();
            //setContentsMargins(margin_v, margin_h, margin_v, margin_h);

            //layout->setCanvasMargin(layout->canvasMargin(xScrollBarAxis) - horizontalScrollBar()->extent(), xScrollBarAxis);
        }
    }

    bool showVScrollBar = needScrollBar(Qt::Vertical);
    if (showVScrollBar)
    {
        ScrollBar* sb = scrollBar(Qt::Vertical);
        sb->setPalette(palette());
        //sb->setInverted(!axisScaleDiv(yAxis).isIncreasing());
        sb->setInverted(axisScaleDiv(yAxis).isIncreasing());
        //sb->setInverted(true);
        sb->setd_baseTicks((curve->maxYValue() - curve->minYValue()) + 1);
        sb->setSingleStep(1);//we should make it sb->setSingleStep(1*factor)where factor default is 1
        sb->setPageStep(1 * zy);
        int mi = sb->minimum();
        int mx = sb->maximum();
        int mv = sb->value();
        sb->setBase(curve->minYValue(), curve->maxYValue());
        //sb->setBase(curve->maxYValue(), curve->minYValue());

        //double minx, maxx;
        //minx = contentsRect().top();
        //maxx = contentsRect().bottom();
        //sb->setBase(contentsRect().top(), contentsRect().bottom());
        //sb->setBase(curve->minYValue(), curve->maxYValue()); //zoomBase().top(), zoomBase().bottom()
        //sb->moveSlider(curve->minYValue(), curve->maxYValue()); //zoomRect().top(), zoomRect().bottom()
        //int p=sb->pageStep();
        sb->moveSlider(curve->minYValue(), curve->minYValue()+sb->pageStep()); //zoomRect().top(), zoomRect().bottom()
        //sb->moveSlider(curve->maxYValue(), curve->maxYValue() - sb->pageStep()); //zoomRect().top(), 
        //scrollBarMoved(sb->orientation(), curve->minYValue(), curve->minYValue() + sb->pageStep());
        //int z = sb->pageStep();
        //Q_EMIT sb->valueChanged(sb->orientation(), curve->minYValue(), curve->minYValue() + sb->pageStep());
        //Q_EMIT sb->valueChanged(sb->orientation(), curve->minYValue(), curve->minYValue() + sb->pageStep());

        //Q_EMIT sb->sliderMoved(sb->orientation(), curve->minYValue(), curve->minYValue() + sb->pageStep());

        //sb->moveSlider(contentsRect().top(), contentsRect().bottom()); //zoomRect().top(), zoomRect().bottom()
        //sb->show();

                                                                //sb->setVisible(true);
        //const int fmh_H = QFontMetrics(this->font()).height();
        //sb->setGeometry(x(), y()+17, 17, height()-50);

        //if (!sb->isVisibleTo(canvas()))
        //if (!sb->isVisibleTo(this))
        if (sb)
        {
            sb->show();
            //margin_v = margin + sb->extent();
            //setContentsMargins(margin_v, margin_h, margin_v, margin_h);

            layout->setCanvasMargin(layout->canvasMargin(yScrollBarAxis) + sb->extent(), yScrollBarAxis);
        }
    }
    else
    {
        if (verticalScrollBar())
        {
            //verticalScrollBar()->hide();
            //margin_v = margin + verticalScrollBar()->extent();
            //setContentsMargins(margin_v, margin_h, margin_v, margin_h);

            //layout->setCanvasMargin(layout->canvasMargin(yScrollBarAxis) - verticalScrollBar()->extent(), yScrollBarAxis);
        }
    }

    if (showHScrollBar && showVScrollBar)
    {
        if (d_cornerWidget == NULL)
        {
            d_cornerWidget = new QWidget(canvas());//this line is responsible for the vague box at 0,0
            //d_cornerWidget = new QWidget(this);

            d_cornerWidget->setAutoFillBackground(true);
            d_cornerWidget->setPalette(palette());
        }
        d_cornerWidget->show();
    }
    else
    {
        if (d_cornerWidget)
            d_cornerWidget->hide();
    }
    //canvas()->updateGeometry();
    layoutScrollBars(canvas()->contentsRect());
    //layoutScrollBars(this->contentsRect());
    updateLayout();
}
