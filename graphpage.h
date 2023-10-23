#ifndef GRAPHPAGE_H
#define GRAPHPAGE_H
#define Inf 100;
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
#include <QIntValidator>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>
#include <QLabel>
#include <QTimeLine>
#include <QQueue>
#include "mybutton.h"

class MainWindow;
class GraphicsView;
class GraphicsVexItem;
class GraphicsLineItem;

class GraphicsView: QGraphicsView
{
private:
    QGraphicsScene * GraphicsScene;
public:
    GraphicsView(QWidget *parent = nullptr);
    QVector<GraphicsVexItem*> vexes;
    QVector<GraphicsLineItem*> lines;
    GraphicsVexItem * v0;
    GraphicsVexItem * v1;
    GraphicsVexItem * v2;
    GraphicsVexItem * v3;
    GraphicsVexItem * v4;
    GraphicsVexItem * v5;
    GraphicsVexItem * v6;
    GraphicsLineItem* l1;
    GraphicsLineItem* l2;
    GraphicsLineItem* l3;
    GraphicsLineItem* l4;
    GraphicsLineItem* l5;
    GraphicsLineItem* l6;
    GraphicsLineItem* l7;
    GraphicsLineItem* l8;
    GraphicsLineItem* l9;

    QQueue<QTimeLine*> aniQueue;
    bool onAni = false;
    QTimeLine *curAni = nullptr;
    qreal speedRate = 1;
    void addAnimation(QTimeLine* ani);
    void nextAni();
};

class GraphicsVexItem : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

private:
    QBrush regBrush = QBrush(QColor(108,166,205));
    QBrush visitedBrush = QBrush(QColor(162,205,90));
public:
    QPointF center;
    qreal radius;
    QGraphicsSimpleTextItem *nameTag = nullptr;
    GraphicsVexItem(QPointF _center, qreal _r,QGraphicsItem *parent = nullptr);

    QTimeLine* visit();
    QTimeLine* curAnimation = nullptr;
};

class GraphicsLineItem : public QObject, public QGraphicsLineItem{
    Q_OBJECT

public:
    /* detail of the line */
    qreal lineWidth = 3;
    Qt::PenStyle lineStyle = Qt::SolidLine;
    Qt::PenCapStyle capStyle = Qt::RoundCap;
    QColor defaultColor = QColor(159,182,205);
    QColor visitedColor = QColor(162,205,90);
    QPen defaultPen;
    QPen visitPen;
    QGraphicsSimpleTextItem *valTag = nullptr;

    /* basic data */
    GraphicsVexItem *startVex;
    GraphicsVexItem *endVex;

    QTimeLine* visit();

public:
    GraphicsLineItem(GraphicsVexItem *start, GraphicsVexItem *end, int val, QGraphicsItem *parent = nullptr);
};


class GraphPage: public QWidget
{
    Q_OBJECT

public:
    explicit GraphPage(QWidget *parent = 0);
    GraphicsView * gv;
    int dis[7][7];
    void dijkstra(int *c,int m,int a,int b);  //dijkstra核心算法
    QPushButton * btn1;
    QLineEdit * lineEdit_2;
    QLineEdit * lineEdit_4;
    QLineEdit * lineEdit_8;
    mybutton * returnBtn;

public slots:
    void show_dijkstra(int i,int j);  //dijkstr槽函数，在槽函数中调用核心算法
signals:
    void get_number(int i,int j);  //定义信号，传递起始结点和目的结点
private slots:
    void on_pushButton_clicked();
};


#endif // GRAPHPAGE_H

