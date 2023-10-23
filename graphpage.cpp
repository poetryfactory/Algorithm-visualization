#include "graphpage.h"
#include "qdebug.h"
#include <iostream>

#define Inf 100  //Inf表示两结点之间没有连通的路径

GraphicsView::GraphicsView(QWidget* parent)
{
    GraphicsScene = new QGraphicsScene();
    GraphicsScene->setBackgroundBrush(Qt::transparent);
    GraphicsScene->setSceneRect(100,10,1100,400);
    this->setParent(parent);
    this->setScene(GraphicsScene);
    this->setFixedSize(1180,410);
    this->move(50,310);
    this->show();

    v0=new GraphicsVexItem(QPointF(230,225),10);
    v0->nameTag->setText("v0");
    GraphicsScene->addItem(v0);
    GraphicsScene->addItem(v0->nameTag);
    vexes.push_back(v0);

    v1=new GraphicsVexItem(QPointF(430,40),10);
    v1->nameTag->setText("v1");
    GraphicsScene->addItem(v1);
    GraphicsScene->addItem(v1->nameTag);
    vexes.push_back(v1);

    v2=new GraphicsVexItem(QPointF(630,225),10);
    v2->nameTag->setText("v2");
    GraphicsScene->addItem(v2);
    GraphicsScene->addItem(v2->nameTag);
    vexes.push_back(v2);

    v3=new GraphicsVexItem(QPointF(430,370),10);
    v3->nameTag->setText("v3");
    GraphicsScene->addItem(v3);
    GraphicsScene->addItem(v3->nameTag);
    vexes.push_back(v3);

    v4=new GraphicsVexItem(QPointF(830,370),10);
    v4->nameTag->setText("v4");
    GraphicsScene->addItem(v4);
    GraphicsScene->addItem(v4->nameTag);
    vexes.push_back(v4);

    v5=new GraphicsVexItem(QPointF(830,40),10);
    v5->nameTag->setText("v5");
    GraphicsScene->addItem(v5);
    GraphicsScene->addItem(v5->nameTag);
    vexes.push_back(v5);

    v6=new GraphicsVexItem(QPointF(1030,225),10);
    v6->nameTag->setText("v6");
    GraphicsScene->addItem(v6);
    GraphicsScene->addItem(v6->nameTag);
    vexes.push_back(v6);

    l1 = new GraphicsLineItem(v0,v1,1);
    GraphicsScene->addItem(l1);
    GraphicsScene->addItem(l1->valTag);
    lines.push_back(l1);

    l2 = new GraphicsLineItem(v1,v5,6);
    GraphicsScene->addItem(l2);
    GraphicsScene->addItem(l2->valTag);
    lines.push_back(l2);

    l3 = new GraphicsLineItem(v0,v2,2);
    GraphicsScene->addItem(l3);
    GraphicsScene->addItem(l3->valTag);
    lines.push_back(l3);

    l4 = new GraphicsLineItem(v2,v5,4);
    GraphicsScene->addItem(l4);
    GraphicsScene->addItem(l4->valTag);
    lines.push_back(l4);

    l5 = new GraphicsLineItem(v0,v3,3);
    GraphicsScene->addItem(l5);
    GraphicsScene->addItem(l5->valTag);
    lines.push_back(l5);

    l6 = new GraphicsLineItem(v3,v4,4);
    GraphicsScene->addItem(l6);
    GraphicsScene->addItem(l6->valTag);
    lines.push_back(l6);

    l7 = new GraphicsLineItem(v2,v4,5);
    GraphicsScene->addItem(l7);
    GraphicsScene->addItem(l7->valTag);
    lines.push_back(l7);

    l8 = new GraphicsLineItem(v4,v6,7);
    GraphicsScene->addItem(l8);
    GraphicsScene->addItem(l8->valTag);
    lines.push_back(l8);

    l9 = new GraphicsLineItem(v5,v6,8);
    GraphicsScene->addItem(l9);
    GraphicsScene->addItem(l9->valTag);
    lines.push_back(l9);
};

void GraphicsView::addAnimation(QTimeLine *ani)
{
    aniQueue.push_back(ani);
    if(!onAni){
        onAni = true;
        nextAni();
    }
}

void GraphicsView::nextAni(){
    if(aniQueue.size() > 0){
        QTimeLine *next = aniQueue.front();
        curAni = next;
        aniQueue.pop_front();
        connect(next, &QTimeLine::finished, [=](){nextAni(); next->deleteLater();});
        next->setDuration(next->duration() / speedRate);
        next->start();
    }
    else{
        onAni = false;
        curAni = nullptr;
    }
}

GraphPage::GraphPage(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(1280,760);
    QLabel* le1 = new QLabel(this);
    QLabel* le2 = new QLabel(this);
    QLabel* le3 = new QLabel(this);
    QLabel* le4 = new QLabel(this);
    le1->setText("起始节点:");
    le1->move(250,100);
    le2->setText("目的节点:");
    le2->move(500,100);
    le3->setText("路径:");
    le3->move(250,150);
    le4->setText("距离：");
    //le4->setStyleSheet("background: rgba(225,0,0,0)");
    le4->move(250,200);
    gv = new GraphicsView(this);
    returnBtn = new mybutton(":/img/img/leftArrow.png");
    returnBtn->setParent(this);
    returnBtn->move(780,5);

    lineEdit_2 = new QLineEdit();
    lineEdit_4 = new QLineEdit();
    lineEdit_2->setParent(this);
    lineEdit_2->setValidator(new QIntValidator(0,6,this));  //限制目的结点的输入范围为0~6
    lineEdit_2->move(560,100);
    lineEdit_2->resize(100,20);
    //lineEdit_2->setStyleSheet("background: rgb(225,0,0)");
    lineEdit_4->setParent(this);
    lineEdit_4->setValidator(new QIntValidator(0,6,this));  //限制起始结点的输入范围为0~6
    lineEdit_4->move(310,100);
    lineEdit_4->resize(100,20);
    btn1 = new QPushButton();
    btn1->setParent(this);
    btn1->setText("计算");
    btn1->resize(200,50);
    btn1->move(1000,200);
    int c[7][7]=    //设置结点间路径长度数组，由于数组不能在类声明的时候初始化，所以用c[][]来初始化dis数组
        {
         {0,1,2,3,Inf,Inf,Inf},
         {1,0,Inf,Inf,Inf,6,Inf},
         {2,Inf,0,Inf,5,4,Inf},
         {3,Inf,Inf,0,4,Inf,Inf},
         {Inf,Inf,5,4,0,Inf,7},
         {Inf,6,4,Inf,Inf,0,8},
         {Inf,Inf,Inf,Inf,7,8,0},
         };
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
            dis[i][j]=c[i][j];  //用c[][]来初始化dis数组
    connect(btn1,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(this,SIGNAL(get_number(int,int)),this,SLOT(show_dijkstra(int,int)));
}

void GraphPage::dijkstra(int *c, int m, int a, int b)
{
    int size = m;
    int min = 0;
    int u;
    int next = a;
    int *dis = (int*)malloc(sizeof(int)*size);  //为dis数组申请int*size大小的空间
    int *book = (int*)malloc(sizeof(int)*size);  //为book数组申请int*size大小的空间
    int *road = (int*)malloc(sizeof(int)*size);  //为road数组申请int*size大小的空间
    //road数组初始化
    for (int i = 0; i < size - 1; i++)
        road[i] = 100;

    //dis数组初始化
    for (int i = 0; i <= size-1; i++)  //保存a点到每个点的距离，0~6，共7个点
    {
        dis[i] = *(c + a*m + i);
    }

    //book数组初始化
    for (int i = 0; i <= size - 1; i++)
    {
        book[i] = 0;
    }
    book[a] = 1;

    //dijkstra算法
    for (int i = 0; i <= size - 2; i++)
    {
        min = Inf;

        for (int j = 0; j <= size - 1; j++)
        {
            if (book[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for (int v = 0; v <= size - 1; v++)
        {
            if (*(c + u*m + v) < Inf)
            {
                if (dis[v] > dis[u] + *(c + u*m + v))
                {
                    dis[v] = dis[u] + *(c + u*m + v);
                    road[v] = u;
                }
            }
        }
    }


    //输出结果
    int outroad = b;


    //GUI中显示路径
    QString show=QString::number(b,10);
    lineEdit_8 = new QLineEdit(this);
    lineEdit_8->setParent(this);
    lineEdit_8->setText(show);
    while (6 >= road[outroad] && road[outroad] >= 0)
    {
        show=QString::number(road[outroad],10)+"-->"+show;
        outroad = road[outroad];

    }
    show = QString::number(a,10)+"-->"+show;
    lineEdit_8->setText(show);
    lineEdit_8->move(310,150);
    lineEdit_8->setFocusPolicy(Qt::NoFocus);
    lineEdit_8->show();
    QLineEdit * lineEdit_9 = new QLineEdit(this);
    lineEdit_9->setText(QString::number(dis[b],10));
    lineEdit_9->move(310,200);
    lineEdit_9->show();
    //回收空间
    free(dis);
    free(book);
    free(road);
}

GraphicsVexItem::GraphicsVexItem(QPointF _center, qreal _r, QGraphicsItem *parent) :
    QGraphicsEllipseItem(_center.x()-20, _center.y()-20, 40, 40, parent),
    center(_center),
    radius(_r){
    nameTag = new QGraphicsSimpleTextItem();
    nameTag->setPos(this->center + QPointF(10, - 29));
    nameTag->setText("");
    nameTag->setZValue(this->zValue());
    nameTag->setBrush(Qt::black);
    this->setPen(Qt::NoPen);
    this->setBrush(regBrush);

}



void GraphPage::show_dijkstra(int i, int j)
{
    dijkstra((int *)dis,7,i,j);
}

void GraphPage::on_pushButton_clicked()
{
    emit get_number(lineEdit_4->text().toInt(),lineEdit_2->text().toInt()); //字符串Qstring转化为数int
}

GraphicsLineItem::GraphicsLineItem(GraphicsVexItem *start, GraphicsVexItem *end, int val, QGraphicsItem *parent) :
    QGraphicsLineItem(parent),
    startVex(start),
    endVex(end){
    //Set display effect
    defaultPen.setWidth(lineWidth);
    defaultPen.setStyle(lineStyle);
    defaultPen.setCapStyle(capStyle);
    defaultPen.setColor(defaultColor);
    visitPen.setWidth(lineWidth);
    visitPen.setStyle(lineStyle);
    visitPen.setCapStyle(capStyle);
    visitPen.setColor(visitedColor);
    this->setPen(defaultPen);
    this->setLine(startVex->center.rx(),startVex->center.ry(),endVex->center.rx(),endVex->center.ry());
    this->setZValue(-2);
    valTag = new QGraphicsSimpleTextItem();
    valTag->setPos(0.5*(endVex->center.rx()+startVex->center.rx()),0.5*(endVex->center.ry()+startVex->center.ry()));
    valTag->setText(QString::number(val,10));
    valTag->setZValue(this->zValue());
    valTag->setBrush(Qt::black);
}

QTimeLine* GraphicsVexItem::visit()
{
    QTimeLine *timeLine = new QTimeLine(500, this);
    timeLine->setFrameRange(0, 200);
    QEasingCurve curve = QEasingCurve::OutBounce;
    qreal baseRadius = 26;
    qreal difRadius = -6;
    connect(timeLine, &QTimeLine::frameChanged, timeLine, [=](int frame){
        this->setBrush(visitedBrush);
        qreal curProgress = curve.valueForProgress(frame / 200.0);
        qreal curRadius = baseRadius + difRadius * curProgress;//20
        this->setRect(QRectF(center.x() - curRadius, center.y() - curRadius, curRadius * 2, curRadius * 2));
    });
    return timeLine;
}

QTimeLine* GraphicsLineItem::visit()
{
    QTimeLine *timeLine = new QTimeLine(500, this);
    timeLine->setFrameRange(0, 200);
    QEasingCurve curve = QEasingCurve::OutBounce;
    connect(timeLine, &QTimeLine::frameChanged, timeLine, [=](int frame){
        this->setPen(visitPen);
        this->setLine(startVex->center.rx(),startVex->center.ry(),endVex->center.rx(),endVex->center.ry());
        this->setZValue(-2);
    });
    return timeLine;
}
