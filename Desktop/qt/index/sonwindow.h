#ifndef SONWINDOW_H
#define SONWINDOW_H

#include <QWidget>
#include <QRect>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
//#include "graphview.h"

class sonwindow : public QWidget
{
public:
    sonwindow();
    //MyGraphicsView *gv;

private:
    void paintEvent(QPaintEvent *);


};

#endif // SONWINDOW_H
