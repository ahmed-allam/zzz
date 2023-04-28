#include "plot.h"

ScrollBar* Plot::horizontalScrollBar() const
{
    return d_hScrollData->scrollBar;
}
ScrollBar* Plot::verticalScrollBar() const
{
    return d_vScrollData->scrollBar;
}
void Plot::setHScrollBarMode(Qt::ScrollBarPolicy mode)
{
    if (hScrollBarMode() != mode)
    {
        d_hScrollData->mode = mode;
        updateScrollBars();
    }
}
#include "plot.h"
ScrollBarPosition Plot::hScrollBarPosition() const
{
    return d_hScrollData->position;
}

ScrollBarPosition Plot::vScrollBarPosition() const
{
    return d_vScrollData->position;
}
/*
int Plot::oppositeAxis(int axis) const
{
    switch (axis)
    {
    case QwtPlot::xBottom:
        return QwtPlot::xBottom;
    case QwtPlot::xTop:
        return QwtPlot::xTop;
    case QwtPlot::yLeft:
        return QwtPlot::yLeft;
    case QwtPlot::yRight:
        return QwtPlot::yRight;
    default:
        break;
    }

    return axis;
}
*/
int Plot::oppositeAxis(int axis) const
{
    switch (axis)
    {
    case QwtPlot::xBottom:
        return QwtPlot::xTop;
    case QwtPlot::xTop:
        return QwtPlot::xBottom;
    case QwtPlot::yLeft:
        return QwtPlot::yRight;
    case QwtPlot::yRight:
        return QwtPlot::yLeft;
    default:
        break;
    }

    return axis;
}

bool Plot::needScrollBar(Qt::Orientation orientation) const
{
    Qt::ScrollBarPolicy mode;
    double zoomMin, zoomMax, baseMin, baseMax;

    if (orientation == Qt::Horizontal)
    {
        mode = d_hScrollData->mode;
        baseMin = rect().left();
        //baseMax = zoomBase().right();
        //zoomMin = zoomRect().left();
        //zoomMax = zoomRect().right();
    }
    else
    {
        mode = d_vScrollData->mode;
        //baseMin = zoomBase().top();
        //baseMax = zoomBase().bottom();
        //zoomMin = zoomRect().top();
        //zoomMax = zoomRect().bottom();
    }

    bool needed = false;
    switch (mode)
    {
    case Qt::ScrollBarAlwaysOn:
        needed = true;
        break;
    case Qt::ScrollBarAlwaysOff:
        needed = false;
        break;
    default:
    {
        //if (baseMin < zoomMin || baseMax > zoomMax)
        needed = true;
        break;
    }
    }
    return needed;
}
void Plot::setVScrollBarMode(Qt::ScrollBarPolicy mode)
{
    if (vScrollBarMode() != mode)
    {
        d_vScrollData->mode = mode;
        updateScrollBars();
    }
}
Qt::ScrollBarPolicy Plot::hScrollBarMode() const
{
    return d_hScrollData->mode;
}
Qt::ScrollBarPolicy Plot::vScrollBarMode() const
{
    return d_vScrollData->mode;
}
void Plot::setCornerWidget(QWidget* w)
{
    if (w != d_cornerWidget)
    {
        if (canvas())
        {
            delete d_cornerWidget;
            d_cornerWidget = w;
            if (d_cornerWidget->parent() != canvas())
                d_cornerWidget->setParent(canvas());

            updateScrollBars();
        }
    }
}
QWidget* Plot::cornerWidget() const
{
    return d_cornerWidget;
}