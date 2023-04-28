#include "header_view_custom.h"
#include <QDebug>

header_view_custom::header_view_custom(Qt::Orientation orientation, QWidget* parent) :
    QHeaderView(orientation, parent)
{    
    //setDefaultSectionSize(30);
    //setMaximumSectionSize(40);
    //setMinimumSectionSize(20);

    //resizeSections(QHeaderView::Fixed);      
    //setFixedWidth(30);
    //setTextElideMode(Qt::ElideLeft);
    
}
QSize header_view_custom::sizeHint() const
{
    return QSize(30, 20);
    //return size();
}
QSize header_view_custom::minimumsizeHint() const
{
    return QSize(30, 20);
    //return size();
}
