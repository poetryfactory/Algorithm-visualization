#include "list_mainwindow.h"

list_mainwindow::list_mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(1280,760);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowIcon(QIcon(":/img/img/circle.ico"));

    QLineEdit * h1 = new QLineEdit();
    h1->setText("名称");
    h1->setFont(QFont("STKaiti", 36, QFont::Bold));
    h1->setParent(this);
    h1->setStyleSheet("padding:0px; border:0px");
    h1->move(900,120);
    h1->resize(120,50);
    h1->setFocusPolicy(Qt::NoFocus);
    h1->setStyleSheet("border-width: 0px; border-style:outset; background: rgba(255,0,0,0);");

    QLineEdit * h2 = new QLineEdit();
    h2->setText("模式");
    h2->setFont(QFont("STKaiti", 28, QFont::Bold));
    h2->setParent(this);
    h2->setStyleSheet("padding:0px; border:0px");
    h2->move(910,180);
    h2->resize(120,50);
    h2->setFocusPolicy(Qt::NoFocus);
    h2->setStyleSheet("border-width: 0px; border-style:outset; background: rgba(255,0,0,0);");

    returnBtn = new mybutton(":/img/img/leftArrow.png");
    returnBtn->move(1120,40);
    returnBtn->setParent(this);

    closeBtn = new mybutton(":/img/img/close.png");
    closeBtn->move(1180,40);
    closeBtn->setParent(this);
    connect(closeBtn, &mybutton::clicked, this, &detailpage::close);

    moreBtn = new mybutton(":/img/img/more.png");
    moreBtn->move(1110, 670);
    moreBtn->setParent(this);

    useBtn = new mybutton(":/img/img/use.png");
    useBtn->setParent(this);
    useBtn->move(1180,670);

    downArrowBtn = new mybutton(":/img/img/downArrow.png");
    downArrowBtn->setParent(this);
    downArrowBtn->move(1080, 180);

    QLineEdit * h3 = new QLineEdit();
    h3->move(910,480);
    h3->setText("您选择的模式为：未选择");
    h3->setFont(QFont("", 20));
    h3->setParent(this);
    h3->resize(300,50);
    h3->setFocusPolicy(Qt::NoFocus);
    h3->setStyleSheet("border-width: 0px; border-style:outset; background: rgba(255,0,0,0);");

    QPushButton * btn1 = new QPushButton();
    btn1->setText("单向链表");
    btn1->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 28px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn1->move(910,260);
    btn1->setParent(this);
    btn1->resize(160,50);
    connect(btn1, &QPushButton::clicked, this, [=](){
        h3->setText("您选择的模式为：单向链表");
    });

    QPushButton * btn2 = new QPushButton();
    btn2->setText("循环链表");
    btn2->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 28px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn2->move(910,340);
    btn2->setParent(this);
    btn2->resize(160,50);
    connect(btn2, &QPushButton::clicked, this, [=](){
        h3->setText("您选择的模式为：循环链表");
    });

    QPushButton * btn3 = new QPushButton();
    btn3->setText("");
    btn3->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 28px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn3->move(1090,260);
    btn3->setParent(this);
    btn3->resize(160,50);
    connect(btn3, &QPushButton::clicked, this, [=](){
        h3->setText("您选择的模式为：");
    });

    QPushButton * btn4 = new QPushButton();
    btn4->setText("");
    btn4->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 28px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn4->move(1090,340);
    btn4->setParent(this);
    btn4->resize(160,50);
    connect(btn4, &QPushButton::clicked, this, [=](){
        h3->setText("您选择的模式为：");
    });

    QPushButton * btn5 = new QPushButton();
    btn5->setText("双向链表");
    btn5->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 28px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn5->move(910,420);
    btn5->setParent(this);
    btn5->resize(160,50);
    connect(btn5, &QPushButton::clicked, this, [=](){
        h3->setText("您选择的模式为：双向链表");
    });

    QPushButton * btn6 = new QPushButton();
    btn6->setText("");
    btn6->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 28px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn6->move(1090,420);
    btn6->setParent(this);
    btn6->resize(160,50);
    connect(btn6, &QPushButton::clicked, this, [=](){
        h3->setText("您选择的模式为：");
    });

    runBtn = new mybutton(":/img/img/rightArrow.png");
    runBtn->setParent(this);
    runBtn->move(900,530);

    QLineEdit * h4 = new QLineEdit();
    h4->setParent(this);
    h4->setText("开始");
    h4->move(960,530);
    h4->resize(300,50);
    h4->setFont(QFont("", 20));
    h4->setFocusPolicy(Qt::NoFocus);
    h4->setStyleSheet("border-width: 0px; border-style:outset; background: rgba(255,0,0,0);");

    addBtn = new mybutton(":/img/img/add.png");
    addBtn->setParent(this);
    addBtn->move(900,590);

    QLineEdit * h5 = new QLineEdit();
    h5->setParent(this);
    h5->setText("新建");
    h5->move(960,590);
    h5->resize(300,50);
    h5->setFont(QFont("", 20));
    h5->setFocusPolicy(Qt::NoFocus);
    h5->setStyleSheet("border-width: 0px; border-style:outset; background: rgba(255,0,0,0);");

    QLineEdit * h11 = new QLineEdit();
    h11->setParent(this);
    h11->setFixedSize(800,570);
    h11->setStyleSheet("border: 2px solid grey; border-radius: 20px");
    h11->move(60,100);
    h11->setFocusPolicy(Qt::NoFocus);

    list1 = new listpage(this);
    list1->setParent(h11);
    //list1->move(60,100);

    codePage = new SlidePage(cornerRadius, "相关代码一览", this);
    connect(moreBtn,&QPushButton::clicked,this,[=](){
        if(slideFlag && !onShown){
            codePage->slideIn();
            onShown=1;
            slideFlag =false;
        }else if(onShown==1){
            codePage->slideOut();
            onShown=0;
            slideFlag =true;
        }
    });

    connect(codePage->leftArrow,&QPushButton::clicked,this,[=](){
        this->codePage->slideOut();
        onShown=0;
        slideFlag =true;
    });

    QTextEdit * text=new QTextEdit(codePage);
    text->setText("(cpp)");
    text->setFont(QFont("Calibri",13));
    text->setStyleSheet("padding:0px;border:0px");
    text->move(350,90);
    text->resize(60,70);
    text->setFocusPolicy(Qt::NoFocus);

    infoPage = new SlidePage(cornerRadius, "信息", this);
    connect(useBtn,&QPushButton::clicked,this,[=](){
        if(slideFlag2 && !onShown){
            infoPage->slideIn();
            onShown=2;
            slideFlag2 =false;
        }else if(onShown==2){
            infoPage->slideOut();
            onShown=0;
            slideFlag2 =true;
        }
    });

    connect(infoPage->leftArrow,&QPushButton::clicked,this,[=](){
        this->infoPage->slideOut();
        onShown=0;
        slideFlag2 =true;
    });

    QLineEdit * h6 = new QLineEdit();
    h6->setText("项目团队信息");
    h6->setFont(QFont("Calibri",28, QFont::Bold));
    h6->setParent(infoPage);
    h6->setStyleSheet("padding:0px;border:0px");
    h6->move(80,130);
    h6->resize(300,80);
    h6->setFocusPolicy(Qt::NoFocus);

    QLineEdit * h7 = new QLineEdit();
    h7->setText("团队负责人：单一凡");
    h7->setFont(QFont("Calibri",20));
    h7->setParent(infoPage);
    h7->setStyleSheet("padding:0px;border:0px");
    h7->move(80,190);
    h7->resize(200,50);
    h7->setFocusPolicy(Qt::NoFocus);

    QLineEdit * h8 = new QLineEdit();
    h8->setText("团队成员：陈舒健，杨嘉木，");
    h8->setFont(QFont("Calibri",20));
    h8->setParent(infoPage);
    h8->setStyleSheet("padding:0px;border:0px");
    h8->move(80,230);
    h8->resize(300,50);
    h8->setFocusPolicy(Qt::NoFocus);

    QLineEdit * h9 = new QLineEdit();
    h9->setText("刘辉，赵英凯，吴优");
    h9->setFont(QFont("Calibri",20));
    h9->setParent(infoPage);
    h9->setStyleSheet("padding:0px;border:0px");
    h9->move(80,270);
    h9->resize(300,50);
    h9->setFocusPolicy(Qt::NoFocus);

    QLineEdit * h10 = new QLineEdit();
    h10->setText("项目内容信息");
    h10->setFont(QFont("Calibri",28, QFont::Bold));
    h10->setParent(infoPage);
    h10->setStyleSheet("padding:0px;border:0px");
    h10->move(80,310);
    h10->resize(300,80);
    h10->setFocusPolicy(Qt::NoFocus);

    QTextEdit * t1 = new QTextEdit();
    t1->setParent(infoPage);
    t1->move(80,380);
    t1->resize(300,180);
    t1->setTextBackgroundColor(Qt::white);
    t1->setText("通过该数据结构实现某种功能\n"
        "详细内容请点击下方按钮");
    t1->setTextColor(Qt::black);
    t1->setFocusPolicy(Qt::NoFocus);
    t1->setStyleSheet("border-radius: 20px; border: 3px solid skyblue;");

    QPushButton * moreInfo=new QPushButton();
    moreInfo->setText("更多信息");
    moreInfo->setStyleSheet("QPushButton{background-color: rgba(241,246,250,1); border-radius: 15px; font: bold 32px; font-family: Calibri;}"
                            "QPushButton:hover{background-color: rgba(58,143,192,20);}");
    moreInfo->setParent(infoPage);
    moreInfo->move(110,580);
    moreInfo->resize(210,70);
    connect(moreInfo,&QPushButton::clicked,this,[=](){
              MyDialog * dlg=new MyDialog(500,700);

              QTextEdit * text1=new QTextEdit(dlg);
              text1->setText("具体实现功能:");
              text1->setFont(QFont("Franklin Gothic Demi",20));
              text1->setStyleSheet("padding:0px;border:0px");
              text1->move(40,100);
              text1->resize(450,50);
              text1->setFocusPolicy(Qt::NoFocus);

              QTextEdit * t2 = new QTextEdit();
              t2->setParent(dlg);
              t2->move(40,180);
              t2->resize(300,140);
              t2->setTextBackgroundColor(Qt::white);
              t2->setText("...");
              t2->setTextColor(Qt::black);
              t2->setFocusPolicy(Qt::NoFocus);
              t2->setStyleSheet("border-radius: 20px; border: 3px solid skyblue;");

              QTextEdit * text2=new QTextEdit(dlg);
              text2->setText("如何使用:");
              text2->setFont(QFont("Franklin Gothic Demi",20));
              text2->setStyleSheet("padding:0px;border:0px");
              text2->move(40,340);
              text2->resize(450,50);
              text2->setFocusPolicy(Qt::NoFocus);

              QTextEdit * t3 = new QTextEdit();
              t3->setParent(dlg);
              t3->move(40,380);
              t3->resize(300,180);
              t3->setTextBackgroundColor(Qt::white);
              t3->setText("...");
              t3->setTextColor(Qt::black);
              t3->setFocusPolicy(Qt::NoFocus);
              t3->setStyleSheet("border-radius: 20px; border: 3px solid skyblue;");

              dlg->show();
    });

    QPushButton * btn7=new QPushButton();
    btn7->setText("模式一");
    btn7->setStyleSheet("QPushButton{background-color: rgba(241,246,250,1); border-radius: 15px; font: bold 24px; font-family: Calibri;}"
                        "QPushButton:hover{background-color: rgba(58,143,192,20);}");
    btn7->setParent(codePage);
    btn7->move(80,160);
    btn7->resize(150,50);
    //connect(btn1,&QPushButton::clicked,son,&SonWindow::build);
    connect(btn7,&QPushButton::clicked,this,[=](){
        MyDialog * dlg1=new MyDialog(500,440);
        QTextEdit * code1=new QTextEdit(dlg1);
        code1->setText("模式一代码\n");
        code1->setFont(QFont("Calibri",10));
        code1->setStyleSheet("padding:0px;border:0px");
        code1->move(30,60);
        code1->resize(400,340);
        code1->setFocusPolicy(Qt::NoFocus);
        dlg1->show();
    });

    QPushButton * btn8=new QPushButton();
    btn8->setText("模式二");
    btn8->setStyleSheet("QPushButton{background-color: rgba(241,246,250,1); border-radius: 15px; font: bold 24px; font-family: Calibri;}"
                        "QPushButton:hover{background-color: rgba(58,143,192,20);}");
    btn8->setParent(codePage);
    btn8->move(80,240);
    btn8->resize(150,50);
    //connect(btn1,&QPushButton::clicked,son,&SonWindow::build);
    connect(btn8,&QPushButton::clicked,this,[=](){
        MyDialog * dlg2=new MyDialog(500,440);
        QTextEdit * code2=new QTextEdit(dlg2);
        code2->setText("模式二代码\n");
        code2->setFont(QFont("Calibri",10));
        code2->setStyleSheet("padding:0px;border:0px");
        code2->move(30,60);
        code2->resize(400,340);
        code2->setFocusPolicy(Qt::NoFocus);
        dlg2->show();
    });

    QPushButton * btn9=new QPushButton();
    btn9->setText("模式三");
    btn9->setStyleSheet("QPushButton{background-color: rgba(241,246,250,1); border-radius: 15px; font: bold 24px; font-family: Calibri;}"
                        "QPushButton:hover{background-color: rgba(58,143,192,20);}");
    btn9->setParent(codePage);
    btn9->move(80,320);
    btn9->resize(150,50);
    //connect(btn1,&QPushButton::clicked,son,&SonWindow::build);
    connect(btn9,&QPushButton::clicked,this,[=](){
        MyDialog * dlg3=new MyDialog(500,440);
        QTextEdit * code3=new QTextEdit(dlg3);
        code3->setText("模式三代码\n");
        code3->setFont(QFont("Calibri",10));
        code3->setStyleSheet("padding:0px;border:0px");
        code3->move(30,60);
        code3->resize(400,340);
        code3->setFocusPolicy(Qt::NoFocus);
        dlg3->show();
    });

    QPushButton * btn10=new QPushButton();
    btn10->setText("模式四");
    btn10->setStyleSheet("QPushButton{background-color: rgba(241,246,250,1); border-radius: 15px; font: bold 24px; font-family: Calibri;}"
                        "QPushButton:hover{background-color: rgba(58,143,192,20);}");
    btn10->setParent(codePage);
    btn10->move(80,400);
    btn10->resize(150,50);
    //connect(btn1,&QPushButton::clicked,son,&SonWindow::build);
    connect(btn10,&QPushButton::clicked,this,[=](){
        MyDialog * dlg4=new MyDialog(500,440);
        QTextEdit * code4=new QTextEdit(dlg4);
        code4->setText("模式四代码\n");
        code4->setFont(QFont("Calibri",10));
        code4->setStyleSheet("padding:0px;border:0px");
        code4->move(20,60);
        code4->resize(400,340);
        code4->setFocusPolicy(Qt::NoFocus);
        dlg4->show();
    });

    QPushButton * btn11=new QPushButton();
    btn11->setText("模式五");
    btn11->setStyleSheet("QPushButton{background-color: rgba(241,246,250,1); border-radius: 15px; font: bold 24px; font-family: Calibri;}"
                         "QPushButton:hover{background-color: rgba(58,143,192,20);}");
    btn11->setParent(codePage);
    btn11->move(80,480);
    btn11->resize(150,50);
    //connect(btn1,&QPushButton::clicked,son,&SonWindow::build);
    connect(btn11,&QPushButton::clicked,this,[=](){
        MyDialog * dlg5=new MyDialog(500,440);
        QTextEdit * code5=new QTextEdit(dlg5);
        code5->setText("模式五代码\n");
        code5->setFont(QFont("Calibri",10));
        code5->setStyleSheet("padding:0px;border:0px");
        code5->move(20,60);
        code5->resize(400,340);
        code5->setFocusPolicy(Qt::NoFocus);
        dlg5->show();
    });

    QPushButton * btn12=new QPushButton();
    btn12->setText("模式六");
    btn12->setStyleSheet("QPushButton{background-color: rgba(241,246,250,1); border-radius: 15px; font: bold 24px; font-family: Calibri;}"
                         "QPushButton:hover{background-color: rgba(58,143,192,20);}");
    btn12->setParent(codePage);
    btn12->move(80,560);
    btn12->resize(150,50);
    //connect(btn1,&QPushButton::clicked,son,&SonWindow::build);
    connect(btn12,&QPushButton::clicked,this,[=](){
        MyDialog * dlg6=new MyDialog(500,440);
        QTextEdit * code6=new QTextEdit(dlg6);
        code6->setText("模式六代码\n");
        code6->setFont(QFont("Calibri",10));
        code6->setStyleSheet("padding:0px;border:0px");
        code6->move(20,60);
        code6->resize(400,340);
        code6->setFocusPolicy(Qt::NoFocus);
        dlg6->show();
    });
}

void list_mainwindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(QColor(100,100,100,50));
    pen.setWidth(3);
    painter.setPen(pen);

    QBrush brush(QColor(255,255,255));
    painter.setBrush(brush);

    /* set the rounded border */
    QRect rect=this->rect();
    rect.setWidth((rect.width()-1));
    rect.setHeight(rect.height()-1);
    painter.drawRoundedRect(rect,cornerRadius,cornerRadius);

    QBrush brush2(QColor(0,0,0));
    painter.setBrush(brush2);
    painter.drawPixmap(1520,320,QPixmap(":/new/prefix1/img/downArrow.png"));
}

void list_mainwindow::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
}

void list_mainwindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(this->x() + (event->globalX() - m_lastPos.x()),
               this->y() + (event->globalY() - m_lastPos.y()));
    m_lastPos = event->globalPos();
}
