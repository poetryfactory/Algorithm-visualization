#include "listpage.h"

listpage::listpage()
{
    this->setFixedSize(800,570);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->setMouseTracking(true);
    this->setCursor(Qt::CrossCursor);

    initUI();
}

void listpage::initUI()
{
    //set mainWindow's title and ico
    this->setWindowTitle("LinkListVisualizer");
    QIcon exeIcon(":/ico/resource/exe.ico");
    this->setWindowIcon(exeIcon);
    //set background image
    QPixmap background(":/ico/resource/background.png");
    QPalette palette;
    palette.setBrush(QPalette::Window,background);
    this->setPalette(palette);
    //set tool tip

    QLineEdit * h1 = new QLineEdit();
    h1->setParent(this);
    h1->setText("请选择:");
    h1->setFont(QFont("", 24, QFont::Bold));
    h1->move(210,110);
    h1->resize(100,50);
    h1->setStyleSheet("background: rgba(225,0,0,0); border-width: 0px");
    h1->setFocusPolicy(Qt::NoFocus);

    QPushButton * pushButton1 = new QPushButton();
    pushButton1->setText("单项链表");
    pushButton1->setFont(QFont("", 24, QFont::Bold));
    //pushButton1->setToolTip("<img src=':/tip/resource/linklist.png' /> ");
    pushButton1->setParent(this);
    pushButton1->move(290,170);
    pushButton1->resize(200,70);
    pushButton1->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 28px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    connect(pushButton1, &QPushButton::clicked, this, [=](){
        this->hide();
        LinkList * l = new LinkList();
        l->show();
    });
    QPushButton * pushButton2 = new QPushButton();
    pushButton2->setText("循环链表");
    pushButton2->setFont(QFont("", 24, QFont::Bold));
    //pushButton2->setToolTip("<img src=':/tip/resource/clinklist.png' />");
    pushButton2->setParent(this);
    pushButton2->move(290,290);
    pushButton2->resize(200,70);
    pushButton2->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 28px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    QPushButton * pushButton3 = new QPushButton();
    pushButton3->setText("双项链表");
    pushButton3->setFont(QFont("", 24, QFont::Bold));
    //pushButton3->setToolTip("<img src=':/tip/resource/dlinklist.png' />");
    pushButton3->setParent(this);
    pushButton3->move(290,410);
    pushButton3->resize(200,70);
    pushButton3->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 28px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
}

/*void listpage::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(QColor(180,180,180));
    pen.setWidth(3);
    painter.setPen(pen);

    QBrush brush(QColor(255,255,255));
    painter.setBrush(brush);

    /* set the rounded border */
    /*QRect rect=this->rect();
    rect.setWidth((rect.width()-1));
    rect.setHeight(rect.height()-1);
    painter.drawRoundedRect(rect,30,30);
}*/
