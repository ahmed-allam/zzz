
#include "scrollbar.h"

ScrollBar::ScrollBar( QWidget * parent ):
    QScrollBar( parent )
{
    init();
}

ScrollBar::ScrollBar( Qt::Orientation o,
        QWidget *parent ):
    QScrollBar( o, parent )
{
    init();
}

ScrollBar::ScrollBar( double minBase, double maxBase,
        Qt::Orientation o, QWidget *parent ):
    QScrollBar( o, parent )
{
    init();
    setBase( minBase, maxBase );
    moveSlider( minBase, maxBase );
}

void ScrollBar::init()
{
    

    d_inverted = orientation() == Qt::Vertical;
    d_baseTicks = 1000000;
    d_minBase = 0.0;
    d_maxBase = 1.0;
    moveSlider( d_minBase, d_maxBase );
    
    
    //int vxxcc = value();
    connect( this, SIGNAL( sliderMoved( int ) ), SLOT( catchSliderMoved( int ) ) );
    connect( this, SIGNAL( valueChanged( int ) ), SLOT( catchValueChanged( int ) ) );
}
void ScrollBar::setd_baseTicks(int d_baseTicks_a)
{
    d_baseTicks = d_baseTicks_a;
}
void ScrollBar::setInverted( bool inverted )
{
    if ( d_inverted != inverted )
    {
        d_inverted = inverted;
        moveSlider( minSliderValue(), maxSliderValue() );
    }
}

bool ScrollBar::isInverted() const
{
    return d_inverted;
}

void ScrollBar::setBase( double min, double max )
{
    if ( min != d_minBase || max != d_maxBase )
    {
        d_minBase = min;
        d_maxBase = max;

        moveSlider( minSliderValue(), maxSliderValue() );
    }
}
/*
void ScrollBar::moveSlider(int min, int max)
{
    const int sliderTicks = qRound((max - min) /
        (d_maxBase - d_minBase) * d_baseTicks);

    // setRange initiates a valueChanged of the scrollbars
    // in some situations. So we block
    // and unblock the signals.

    blockSignals(true);
    int vxxx = value();
    //setRange( sliderTicks / 2, d_baseTicks - sliderTicks / 2 );
    setRange(0, d_baseTicks - sliderTicks);
    vxxx = value();
    //int steps = sliderTicks / 200;
    //if ( steps <= 0 )
    //    steps = 1;

    //setSingleStep( steps );
    setSingleStep(1);
    setPageStep(sliderTicks);

    //int tick = mapToTick( min + ( max - min ) / 2 );
    int tick = mapToTick(min + (max - min));

    if (isInverted())
        tick = d_baseTicks - tick;

    setSliderPosition(tick);
    blockSignals(false);
}
*/
void ScrollBar::moveSlider( double min, double max )
{
    const int sliderTicks = qRound( (( max - min ) /
        ( d_maxBase - d_minBase )) * d_baseTicks );

    // setRange initiates a valueChanged of the scrollbars
    // in some situations. So we block
    // and unblock the signals.

    blockSignals( true );
    //int vxxx = value();
    //setRange( sliderTicks / 2, d_baseTicks - sliderTicks / 2 );//here we set value of qslider
    //setRange(sliderTicks , d_baseTicks - sliderTicks );//here we set value of qslider
    setRange(0, d_baseTicks - sliderTicks);//here we set value of qslider

    //setRange(0, d_baseTicks - sliderTicks );
    //vxxx = value();
    int steps = sliderTicks / 200;
    if ( steps <= 0 )
        steps = 1;

    setSingleStep( steps );
   // setSingleStep(1);
    setPageStep( sliderTicks );

    int tick = mapToTick( min + (( max - min ) / 2 ));
    //int tick1 = mapToTick(min + (max - min) / 2 );
    //int tick2 = mapToTick(min + ((max - min) ));
    //int tick3 = mapToTick(min);

    


    //setSliderPosition( tick );
    setSliderPosition(tick);
    if (isInverted())
    {
        tick = d_baseTicks - tick;
        setSliderPosition(tick);// + //sliderTicks);
    }
    blockSignals( false );
}

double ScrollBar::minBaseValue() const
{
    return d_minBase;
}

double ScrollBar::maxBaseValue() const
{
    return d_maxBase;
}

void ScrollBar::sliderRange( int value, double &min, double &max ) const
{
    if ( isInverted() )
        value = d_baseTicks - value;

    const int visibleTicks = pageStep();

    min = mapFromTick( value - visibleTicks / 2 );
    max = mapFromTick( value + visibleTicks / 2 );
}
/*
void ScrollBar::sliderRange(int value, int& min, int& max) const
{
    if (isInverted())
        value = d_baseTicks - value;

    const int visibleTicks = pageStep();

    min = mapFromTick(value - visibleTicks / 2);
    max = mapFromTick(value + visibleTicks / 2);
}
*/
/*
int ScrollBar::minSliderValue() const
{
    int min, dummy;
    sliderRange(value(), min, dummy);

    return min;
}

int ScrollBar::maxSliderValue() const
{
    int max, dummy;
    sliderRange(value(), dummy, max);

    return max;
}
*/

double ScrollBar::minSliderValue() const
{
    double min, dummy;
    sliderRange( value(), min, dummy );

    return min;
}

double ScrollBar::maxSliderValue() const
{
    double max, dummy;
    sliderRange( value(), dummy, max );

    return max;
}

int ScrollBar::mapToTick( double v ) const
{
    const double pos = ( v - d_minBase ) / ( d_maxBase - d_minBase ) * d_baseTicks;
    return static_cast<int>( pos );
}

double ScrollBar::mapFromTick( int tick ) const
{
    return d_minBase + ( d_maxBase - d_minBase ) * tick / d_baseTicks;
}
/*
int ScrollBar::mapToTick(int v) const
{
    const double pos = (v - d_minBase) / (d_maxBase - d_minBase) * d_baseTicks;
    return static_cast<int>(pos);
}

int ScrollBar::mapFromTick(int tick) const
{
    return d_minBase + (d_maxBase - d_minBase) * tick / d_baseTicks;
}
*/
void ScrollBar::catchValueChanged( int value )
{
    double min, max;
    sliderRange( value, min, max );
    //Q_EMIT valueChanged( orientation(), min, max );//27-10-2022 this is where normal valueChanged with one argument "value" is converted to valueChanged with 3 arguments
    Q_EMIT valueChanged(orientation(), value);//27-10-2022 this is where normal valueChanged with one argument "value" is converted to valueChanged with 3 arguments
}

void ScrollBar::catchSliderMoved( int value )
{
    double min, max;
    sliderRange( value, min, max );
    //Q_EMIT sliderMoved( orientation(), min, max );
    Q_EMIT sliderMoved(orientation(), value);
}

int ScrollBar::extent() const
{
    QStyleOptionSlider opt;
    opt.init( this );
    opt.subControls = QStyle::SC_None;
    opt.activeSubControls = QStyle::SC_None;
    opt.orientation = orientation();
    opt.minimum = minimum();
    opt.maximum = maximum();
    opt.sliderPosition = sliderPosition();
    opt.sliderValue = value();
    opt.singleStep = singleStep();
    opt.pageStep = pageStep();
    opt.upsideDown = invertedAppearance();
    if ( orientation() == Qt::Horizontal )
        opt.state |= QStyle::State_Horizontal;
    return style()->pixelMetric( QStyle::PM_ScrollBarExtent, &opt, this );
}
