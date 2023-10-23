#ifndef TreeSonWindow_H
#define TreeSonWindow_H

#include <QWidget>
#include <QObject>
#include <QRect>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QLineEdit>
#include "graphview.h"

class TreeSonWindow : public QWidget
{
    Q_OBJECT

private:
    void paintEvent(QPaintEvent *);

public:
    TreeSonWindow();
    MyGraphicsView *gv;


public slots:
    void createNew();

    void build();
    void build2();

    void pre();
    void in();
    void pos();
    void morris();
    void BFS();
    void SolveMaximizeStepByDFS();
};


#endif // TreeSonWindow_H
