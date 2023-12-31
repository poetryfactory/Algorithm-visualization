#include "myarrowitem.h"
#include <QGraphicsScene>
#include <QPainter>

MyArrowItem::MyArrowItem ( int length, int dir, int size) : direction(dir), arrowSize(size)
{
    QPoint startP(0,0), endP, p1, p2;
    switch (dir) {
    case 0:
        p1=p2=endP=QPoint(0,-length);
        if(size)
            p1+=QPoint(-SIZE1_HEIGHT,SIZE1_WEIGHT),p2+=QPoint(SIZE1_HEIGHT,SIZE1_WEIGHT);
        mboundingRect=QRect(-SIZE1_HEIGHT,-length,SIZE1_HEIGHT<<1,length);
        break;
    case 1:
        p1=p2=endP=QPoint(length,0);
        if(size)
            p1+=QPoint(-SIZE1_WEIGHT,-SIZE1_HEIGHT),p2+=QPoint(-SIZE1_WEIGHT,SIZE1_HEIGHT);
        mboundingRect=QRect(0,-SIZE1_HEIGHT,length,SIZE1_HEIGHT<<1);
        break;
    case 2:
        p1=p2=endP=QPoint(0,length);
        if(size)
            p1+=QPoint(-SIZE1_HEIGHT,-SIZE1_WEIGHT),p2+=QPoint(SIZE1_HEIGHT,-SIZE1_WEIGHT);
        mboundingRect=QRect(-SIZE1_HEIGHT,0,SIZE1_HEIGHT<<1,length);
        break;
    case 3:
        p1=p2=endP=QPoint(-length,0);
        if(size)
            p1+=QPoint(SIZE1_WEIGHT,SIZE1_HEIGHT),p2+=QPoint(SIZE1_WEIGHT,-SIZE1_HEIGHT);
        mboundingRect=QRect(-length,-SIZE1_HEIGHT,length,SIZE1_HEIGHT<<1);
        break;
    default:
        break;
    }
    line1=QLine(startP,endP);
    line2=QLine(endP,p1);
    line3=QLine(endP,p2);
}
MyArrowItem::~MyArrowItem()
{
}
void MyArrowItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                        QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawLine(line1);
    painter->drawLine(line2);
    painter->drawLine(line3);
}
QRectF MyArrowItem::boundingRect() const
{
    return mboundingRect;
}
