#ifndef LIST_MAINWINDOW_H
#define LIST_MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QRect>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QScrollArea>
#include <QVBoxLayout>
#include "mybutton.h"
#include "index_mainwindow.h"
#include "slidepage.h"
#include "mydialog.h"
#include "sonwindow.h"
#include "graphview.h"
#include "listpage.h"

class list_mainwindow : public QMainWindow
{
public:
    list_mainwindow(QWidget *parent = nullptr);

    mybutton * returnBtn;
    mybutton * closeBtn;
    mybutton * moreBtn;
    mybutton * useBtn;
    mybutton * downArrowBtn;
    mybutton * runBtn;
    mybutton * addBtn;

    listpage * list1;

private:

    void paintEvent(QPaintEvent *);

    /* For dragging */
    QPoint m_lastPos;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    int cornerRadius=60;

    bool slideFlag =true;
    bool slideFlag2 =true;
    int onShown = 0;
    SlidePage *codePage = nullptr;
    SlidePage *infoPage = nullptr;

    int choice=0;

};

#endif // DETAILPAGE_H
