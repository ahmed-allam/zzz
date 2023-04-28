#ifndef _SCROLLDATA_
#define _SCROLLDATA_
#include "scrollbar.h"
enum ScrollBarPosition
{
    AttachedToScale,
    OppositeToScale
};
class ScrollData
{
public:
    ScrollData() :
        scrollBar(NULL),
        //position(ScrollBarPosition::OppositeToScale),
        position(ScrollBarPosition::AttachedToScale),
        //mode(Qt::ScrollBarAsNeeded)
        mode(Qt::ScrollBarAlwaysOn)
    {
    }

    ~ScrollData()
    {
        delete scrollBar;
    }

    ScrollBar* scrollBar;
    ScrollBarPosition position;
    Qt::ScrollBarPolicy mode;
};

#endif
