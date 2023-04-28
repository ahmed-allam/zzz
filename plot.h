#ifndef _PLOT_H_
#define _PLOT_H_
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_picker.h>
#include <qwt_plot_panner.h>
#include <qwt_picker_machine.h>

#include <qwt_scale_engine.h>
//#include <qwt_plot_panner.h>
//#include <qwt_plot_magnifier.h>
#include <qwt_plot.h>
#include <qglobal.h>
#include <qtimer.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_layout.h>
#include <qwt_scale_widget.h>
#include <qwt_scale_draw.h>
#include "scrollzoomer.h"
//22-12-2021 the following members are copied from svgmap playgroung example to allow for zooming,panning and dragging 
#include <qrect.h>

#include "./csv_to_monowave/csv_min_time_with_price_difference.h"
#include "scrollbar.h"
#include "scrollData.h"

class QwtTransform;


class Plot: public QwtPlot
{
    Q_OBJECT

public:
    //Plot(int width, int height, csv_to_monowave_bin* csv_to_monowave_pointer , QWidget *parent = NULL );
    //Plot(int width, int height, QWidget* parent = NULL);
    Plot(csv_min_time_with_price_difference* current_monowave_class_ptr, QWidget* parent = NULL);

    virtual ~Plot();
    virtual void replot();
    virtual bool eventFilter(QObject*, QEvent*);
    void rescale();
    void updateScrollBars();
    ScrollBarPosition hScrollBarPosition() const;
    ScrollBarPosition vScrollBarPosition() const;
    int oppositeAxis(int) const;
    bool needScrollBar(Qt::Orientation) const;
    virtual ScrollBar* scrollBar(Qt::Orientation);
    ScrollBar* horizontalScrollBar() const;
    ScrollBar* verticalScrollBar() const;
    void setHScrollBarMode(Qt::ScrollBarPolicy);
    void setVScrollBarMode(Qt::ScrollBarPolicy);
    Qt::ScrollBarPolicy vScrollBarMode() const;
    Qt::ScrollBarPolicy hScrollBarMode() const;

    QWidget* d_cornerWidget;
    QWidget* cornerWidget() const;
    virtual void setCornerWidget(QWidget*);

    virtual void layoutScrollBars(const QRect&);
//private Q_SLOTS:
    //void scrollBarMoved(Qt::Orientation o, double min, double max);

     //void moveTo(const QPointF&);
    void moveTo_scroll(const QPointF& pos);

//public Q_SIGNALS:


public Q_SLOTS:
    void setTransformation(csv_min_time_with_price_difference* , QwtTransform * );
    void setTransformation1(QwtTransform* transform);

    void scrollBarMoved(Qt::Orientation o, double min, double max);
    void scrollBarMoved(Qt::Orientation o, int value);
//private:
public:
    void populate();
    //22-12-2021 the following members are copied from svgmap playgroung example to allow for zooming,panning and dragging 
    //void rescale();   
    //const QRectF d_mapRect;
    //QRectF d_mapRect;
    int margin,margin_v, margin_h = 0;
    QwtPlotCanvas* canvas_;
    QwtPlotGrid* grid;
    QwtPlotCurve* curve;
    QwtSymbol* symbol;
    csv_min_time_with_price_difference* current_monowave_class_ptr_m_plot;
    //QwtPlotZoomer* d_zoomer;
    QwtPlotPicker* d_picker;
    QwtPlotPanner* d_panner;

    ScrollData* d_hScrollData;
    ScrollData* d_vScrollData;
    //int hscroll_min=0, hscroll_max=0, vscroll_min=0, vscroll_max=0;
};

#endif
