#include "sonwindow.h"

SonWindow::SonWindow()
{
    this->setFixedSize(1200,900);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->setMouseTracking(true);
    this->setCursor(Qt::CrossCursor);

    gv=new MyGraphicsView();
    gv->setParent(this);
    gv->show();

    gv->scrollArea = new QScrollArea(this);
    gv->hint = new QLineEdit(this);
    gv->hint->setText("遍历结果：");
    gv->hint->setFont(QFont("Segoe Print",22,QFont::Bold));
    gv->hint->setStyleSheet("padding:0px;border:0px");
    gv->hint->move(20,840);
    gv->hint->resize(150,30);
    gv->hint->setFocusPolicy(Qt::NoFocus);
    gv->scrollAreaWidget = new QWidget(gv->scrollArea);
    gv->resultOutput = new QTextEdit(gv->scrollAreaWidget);
    gv->scrollArea->setWidget(gv->scrollAreaWidget);
    gv->scrollArea->setGeometry(QRect(170,820,1000,80));
    gv->scrollAreaWidget->setGeometry(QRect(100,0,1200,500));
    gv->resultOutput->setGeometry(QRect(0,0,1100,480));
    gv->resultOutput->setFocusPolicy(Qt::NoFocus);
    gv->tc = gv->resultOutput->document();
    gv->scrollArea->setWidgetResizable(false);
}

void SonWindow::paintEvent(QPaintEvent *)
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

void SonWindow::createNew()
{
    gv->init();
}

void SonWindow::build()
{
    gv->buildTree();
}

void SonWindow::build2()
{
    gv->buildTree2();
}

void SonWindow::pre()
{
    gv->resultOutput->clear();
    gv->pre(gv->root);
}

void SonWindow::in()
{
    gv->resultOutput->clear();
    gv->in(gv->root);
}

void SonWindow::pos()
{
    gv->resultOutput->clear();
    gv->pos(gv->root);
}

void SonWindow::morris()
{
    gv->resultOutput->clear();
    gv->morris(gv->root);
}

void SonWindow::BFS()
{
    gv->resultOutput->clear();
    gv->BFS(gv->root);
}

void SonWindow::SolveMaximizeStepByDFS()
{
    gv->buildTree2();
    gv->SolveMaximizeStepsByDFS(gv->root);
}
