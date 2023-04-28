#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QDialog>
#include <QEvent>
#include <QLabel>
#include <QMouseEvent>
#include <QTableView>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTimer>
#include <QDebug>

#include "header_view_custom.h"


class TableView : public QTableView {
    Q_OBJECT
    QDialog* popup;
    QLabel* popupLabel;
    int editor_index ;
public:
    void setHorizontalHeader(header_view_custom* mHorizontalHeader)
    {
        QTableView::setHorizontalHeader(mHorizontalHeader);
    }
    TableView(QWidget* parent = Q_NULLPTR) :QTableView(parent) 
    {
        
        viewport()->installEventFilter(this);
        mHorizontalHeader = new header_view_custom(Qt::Orientation::Horizontal, this);
        setHorizontalHeader(mHorizontalHeader);
        mHorizontalHeader->hide();
        QSizePolicy sizePolicy_w(QSizePolicy::Preferred, QSizePolicy::Preferred);
        //sizePolicy_w.setHorizontalStretch(1);
        //sizePolicy_w.setVerticalStretch(1);
        //sizePolicy_w.setHeightForWidth(sizePolicy().hasHeightForWidth());
        setSizePolicy(sizePolicy_w);
        //setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        verticalHeader()->setFixedWidth(45);
        //verticalHeader()->setTextElideMode(Qt::TextElideMode::ElideMiddle);
        //int x=geometry().width(),y= geometry().height();
        //setFixedSize(frameGeometry().width(), geometry().height());
        setShowGrid(true);
        setWordWrap(true);
        //mHorizontalHeader->setSectionResizeMode(QHeaderView::ResizeToContents);
        //mHorizontalHeader->setDefaultAlignment(Qt::AlignHCenter | Qt::Alignment(Qt::TextWordWrap));
        mHorizontalHeader->setDefaultSectionSize(45);
        //mHorizontalHeader->setMaximumSectionSize(50);

        //setColumnWidth();

        viewport()->installEventFilter(this);
        horizontalHeader()->viewport()->installEventFilter(this);
        verticalHeader()->viewport()->installEventFilter(this);
        setMouseTracking(true);        
    }

    bool eventFilter(QObject* watched, QEvent* event) {
        //if (viewport() == watched) 
        if ((watched == horizontalHeader()->viewport() ||
            watched == verticalHeader()->viewport())) 
        {
            if (event->type() == QEvent::MouseMove) 
            {
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);                
                QHeaderView* header = static_cast<QHeaderView*>(watched->parent());
                int mouse_pos = header->orientation() == Qt::Horizontal ? mouseEvent->x() : mouseEvent->y();
                int logical_index = header->logicalIndex(header->visualIndexAt(mouse_pos));
                QString text = header->model()->
                    headerData(logical_index, header->orientation()).toString();
                if (logical_index >= 0) 
                { // if mouse is over an item                      
                    emit showRowHeaderNameSignal(text);
                }                
                else 
                {
                    emit showRowHeaderNameSignal("");
                }
            }
            else if (event->type() == QEvent::Leave) {
                emit showRowHeaderNameSignal("");
            }
        }
        else if (popup == watched) 
        {
            if (event->type() == QEvent::Leave) 
            {
                emit showRowHeaderNameSignal("");
            }
        }
        return QTableView::eventFilter(watched, event);
    }
signals:
    void showRowHeaderNameSignal(QString) const;

private:
    header_view_custom* mHorizontalHeader;
};

#endif // TABLEVIEW_H
