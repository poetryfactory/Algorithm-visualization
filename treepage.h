#ifndef TREEPAGE_H
#define TREEPAGE_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QPaintEvent>
#include <QRect>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include "mybutton.h"
#include "treesonwindow.h"
#include "slidepage.h"
#include "mydialog.h"

class TreePage : public QWidget
{
    Q_OBJECT
public:
    explicit TreePage(QWidget *parent=nullptr);
    void paintEvent(QPaintEvent *);

    /* For dragging */
    QPoint m_lastPos;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    int cornerRadius=60;

    TreeSonWindow * son;

    mybutton * closeBtn;
    mybutton * runBtn;
    mybutton * addBtn;
    mybutton * moreBtn;
    mybutton * useBtn;
    mybutton * returnBtn;

    /* For slidepage */
    bool slideFlag =true;
    bool slideFlag2 =true;
    int onShown = 0;
    SlidePage *codePage = nullptr;
    SlidePage *infoPage = nullptr;

    int choice=0;
    QString modeText = "";


signals:

};

#endif // TREEPAGE_H
