#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>
#include <QMouseEvent>

//for visualizing binary tree
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>
#include <QScrollArea>
#include <QTextEdit>
#include <QLineEdit>

#include <QTimeLine>

#include <QVector>
#include <QStack>
#include <QQueue>
#include "stackvisualizationwidget.h"

class MyGraphicsView;
class MyGraphicsVexItem;
class MyGraphicsLineItem;

//Summary:
//    MyGraphicsView class is customized for visualizing binary tree,
//    and it provides interfaces for traversal methods.
class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene* myGraphicsScene;
    QBrush regBrush = QBrush(QColor(108,166,205));

    /* For creating a binary tree */
    int vexID = 0;
    bool isCreating = false;
    MyGraphicsVexItem *strtVex = nullptr;
    QGraphicsItem *sketchItem = nullptr;

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    MyGraphicsVexItem* addVex(QPointF center, qreal radius = 10);
    MyGraphicsLineItem* addLine(MyGraphicsVexItem *start, MyGraphicsVexItem *end);
    void clearSketch();
    void sketchLine(QPointF start, QPointF end);

    int cauculateStep(MyGraphicsVexItem * node);

    /* Animation loop */
    QQueue<QTimeLine*> aniQueue;
    bool onAni = false;
    QTimeLine *curAni = nullptr;
    qreal speedRate = 1;
    void nextAni();
    void addAnimation(QTimeLine *ani);

    //For morris
    QTimeLine* changeName(QString s,MyGraphicsVexItem * head);

    QVector<MyGraphicsVexItem*> vexes;//storing all nodes
    QVector<MyGraphicsVexItem*> preVexes;//node that has child
    QVector<MyGraphicsVexItem*> leaves;
    QVector<MyGraphicsVexItem*> halfLeaves;//node that only has one child
    QVector<MyGraphicsVexItem*> nullVexes;//nullptr
    QVector<MyGraphicsLineItem*> leafLines;//between a leaf node and a nullptr

public:
    MyGraphicsView();

    MyGraphicsVexItem * root;
    QScrollArea * scrollArea;
    QWidget * scrollAreaWidget;
    QTextEdit * resultOutput;
    QLineEdit * hint;
    QTextDocument* tc;

    /* For traversing */
    void buildTree();
    void buildTree2();    
    void pre(MyGraphicsVexItem * head);
    void in(MyGraphicsVexItem * head);
    void pos(MyGraphicsVexItem * head);
    void morris(MyGraphicsVexItem * head);
    void BFS(MyGraphicsVexItem* head);
    void SolveMaximizeStepsByDFS(MyGraphicsVexItem* head);

    void init();
};

//Summary:
//    MyGraphicsVexItem realizes the interactions with node
class MyGraphicsVexItem : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

private:
    QBrush regBrush = QBrush(QColor(108,166,205));
    QBrush visitedBrush = QBrush(QColor(162,205,90));
    QBrush cauculateBrush = QBrush(QColor(255,255,102));
    QFont nameFont = QFont("Corbel", 13, QFont::Bold, true);

    QTimeLine* curAnimation = nullptr;
    void startAnimation();

public:
    QPointF center;
    qreal radius;

    QVector<MyGraphicsVexItem*> nexts;
    MyGraphicsVexItem *left = nullptr;
    MyGraphicsVexItem *right = nullptr;

    /* For display tag */
    QGraphicsSimpleTextItem *nameTag = nullptr;
    QGraphicsSimpleTextItem *valTag = nullptr;
    QString nameText = "";
    void setName(QString s);

    MyGraphicsVexItem(QPointF _center, qreal _r, int nameID = 0, QGraphicsItem *parent = nullptr);
    MyGraphicsVexItem(QPointF _center, qreal _r=10, QGraphicsItem *parent = nullptr);

    void showAnimation();

    QTimeLine* visit();
    QTimeLine* cauculate();
};

//Summary:
//    MyGraphicsLineItem realizes the connection of nodes
class MyGraphicsLineItem : public QObject, public QGraphicsLineItem{
    Q_OBJECT

private:
    /* detail of the line */
    qreal lineWidth = 3;
    Qt::PenStyle lineStyle = Qt::SolidLine;
    Qt::PenCapStyle capStyle = Qt::RoundCap;
    QColor defaultColor = QColor(159,182,205);
    QPen defaultPen;


    /* basic data */
    MyGraphicsVexItem *startVex;
    MyGraphicsVexItem *endVex;

public:
    MyGraphicsLineItem(MyGraphicsVexItem *start, MyGraphicsVexItem *end, QGraphicsItem *parent = nullptr);
};
#endif // GRAPHVIEW_H
