#include "sonwindow.h"

sonwindow::sonwindow()
{
    this->setFixedSize(800,570);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->setMouseTracking(true);
    this->setCursor(Qt::CrossCursor);

    /*gv=new MyGraphicsView();
    gv->setParent(this);
    gv->show();*/
}

void sonwindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(QColor(180,180,180));
    pen.setWidth(3);
    painter.setPen(pen);

    QBrush brush(QColor(255,255,255));
    painter.setBrush(brush);

    /* set the rounded border */
    QRect rect=this->rect();
    rect.setWidth((rect.width()-1));
    rect.setHeight(rect.height()-1);
    painter.drawRoundedRect(rect,30,30);
}

/*void sonwindow::createNew()
{
    gv->init();
}

void sonwindow::build()
{
    gv->buildTree();
}

void sonwindow::build2()
{
    gv->buildTree2();
}

void sonwindow::pre()
{
    gv->pre(gv->root);
}

void sonwindow::in()
{
    gv->in(gv->root);
}

void sonwindow::pos()
{
    gv->pos(gv->root);
}

void sonwindow::morris()
{
    gv->morris(gv->root);
}*/
