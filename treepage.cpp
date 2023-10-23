#include "treepage.h"

TreePage::TreePage(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(1800,1200);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowIcon(QIcon(":/img/img/circle.ico"));

    QLineEdit * modeLE = new QLineEdit();
    modeLE->setText("未选择");
    modeLE->setFont(QFont("Franklin Gothic Demi",24));
    modeLE->setParent(this);
    modeLE->setStyleSheet("padding:0px;border:0px");
    modeLE->move(1550,740);
    modeLE->resize(250,100);
    modeLE->setFocusPolicy(Qt::NoFocus);

    closeBtn=new mybutton(":/img/img/close.png");
    closeBtn->setParent(this);//让closeBtn对象依赖在MainWindow窗口中
    closeBtn->move(1700,50);//设置按钮在窗口中的位置
    connect(closeBtn,&mybutton::clicked,this,&TreePage::close);

    returnBtn = new mybutton(":/img/img/leftArrow.png");
    returnBtn->setParent(this);
    returnBtn->move(100,5);

    runBtn=new mybutton(":/img/img/rightArrow.png");
    runBtn->setParent(this);
    runBtn->move(1300,850);
    connect(runBtn,&mybutton::clicked,this,[=](){
        if(choice==1){
            this->son->pre();
        }else if(choice==2){
            this->son->in();
        }else if(choice==3){
            this->son->pos();
        }else if(choice==4){
            this->son->morris();
        }else if(choice==5){
            this->son->BFS();
        }else if(choice==6){
            this->son->SolveMaximizeStepByDFS();
        }else{
            MyDialog * hintDlg=new MyDialog(500,300);
            QTextEdit * hint=new QTextEdit(hintDlg);
            hint->setText("You haven't chosen the traversal mode yet.");
            hint->setFont(QFont("Calibri",15));
            hint->setStyleSheet("padding:0px;border:0px");
            hint->move(30,90);
            hint->resize(400,180);
            hint->setFocusPolicy(Qt::NoFocus);
            hintDlg->show();
        }
    });

    addBtn=new mybutton(":/img/img/add.png");
    addBtn->setParent(this);
    addBtn->move(1300,920);
    connect(addBtn,&mybutton::clicked,this,[=](){
        this->son->createNew();
        choice=0;
        modeText = "未选择";
        modeLE->setText(modeText);
    });

    moreBtn=new mybutton(":/img/img/more.png");
    moreBtn->setParent(this);
    moreBtn->move(1630,1100);

    useBtn=new mybutton(":/img/img/use.png");
    useBtn->setParent(this);
    useBtn->move(1700,1100);

    son=new TreeSonWindow();
    son->setParent(this);
    son->move(60,100);

    QLineEdit * le1 = new QLineEdit();
    le1->setText("树可视化");
    le1->setFont(QFont("Segoe Print",36,QFont::Bold));
    le1->setParent(this);
    le1->setStyleSheet("padding:0px;border:0px");
    le1->move(1300,200);
    le1->resize(450,90);
    le1->setFocusPolicy(Qt::NoFocus);

    QLineEdit * le2 = new QLineEdit();
    le2->setText("模式");
    le2->setFont(QFont("Segoe Print",28,QFont::Bold));
    le2->setParent(this);
    le2->setStyleSheet("padding:0px;border:0px");
    le2->move(1300,310);
    le2->resize(220,70);
    le2->setFocusPolicy(Qt::NoFocus);

    QLineEdit * le3 = new QLineEdit();
    le3->setText("开始遍历");
    le3->setFont(QFont("Calibri",13,QFont::Bold));
    le3->setParent(this);
    le3->setStyleSheet("padding:0px;border:0px");
    le3->move(1360,850);
    le3->resize(100,70);
    le3->setFocusPolicy(Qt::NoFocus);

    QLineEdit * le4 = new QLineEdit();
    le4->setText("新建一个树");
    le4->setFont(QFont("Calibri",13,QFont::Bold));
    le4->setParent(this);
    le4->setStyleSheet("padding:0px;border:0px");
    le4->move(1360,920);
    le4->resize(300,70);
    le4->setFocusPolicy(Qt::NoFocus);

    QLineEdit * le5 = new QLineEdit();
    le5->setText("树的可视化");
    le5->setFont(QFont("Franklin Gothic Demi",18));
    le5->setParent(this);
    le5->setStyleSheet("padding:0px;border:0px");
    le5->move(100,1030);
    le5->resize(400,100);
    le5->setFocusPolicy(Qt::NoFocus);

    QLineEdit * le6 = new QLineEdit();
    le6->setText("你选择的模式为:");
    le6->setFont(QFont("Franklin Gothic Demi",24));
    le6->setParent(this);
    le6->setStyleSheet("padding:0px;border:0px");
    le6->move(1300,740);
    le6->resize(250,100);
    le6->setFocusPolicy(Qt::NoFocus);

    QPushButton * btn1=new QPushButton();
    btn1->setText("前序");
    btn1->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                                 "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn1->setParent(this);
    btn1->move(1300,440);
    btn1->resize(210,70);
    connect(btn1,&QPushButton::clicked,son,&TreeSonWindow::build);
    connect(btn1,&QPushButton::clicked,this,[=](){
        this->son->build();
        choice=1;
        modeText = "前序遍历";
        modeLE->setText(modeText);
    });

    QPushButton * btn2=new QPushButton();
    btn2->setText("中序");
    btn2->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                                 "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn2->setParent(this);
    btn2->move(1540,440);
    btn2->resize(210,70);
    connect(btn2,&QPushButton::clicked,this,[=](){
        this->son->build();
        choice=2;
        modeText = "中序遍历";
        modeLE->setText(modeText);
    });

    QPushButton * btn3=new QPushButton();
    btn3->setText("后序");
    btn3->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                                 "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn3->setParent(this);
    btn3->move(1300,540);
    btn3->resize(210,70);
    connect(btn3,&QPushButton::clicked,this,[=](){
        this->son->build();
        choice=3;
        modeText = "后序遍历";
        modeLE->setText(modeText);
    });

    QPushButton * btn4=new QPushButton();
    btn4->setText("morris中序");
    btn4->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                                 "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn4->setParent(this);
    btn4->move(1540,540);
    btn4->resize(210,70);
    connect(btn4,&QPushButton::clicked,this,[=](){
        this->son->build2();
        choice=4;
        modeText = "morris中序遍历";
        modeLE->setText(modeText);
    });

    QPushButton * btn5=new QPushButton();
    btn5->setText("BFS层序");
    btn5->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn5->setParent(this);
    btn5->move(1300,640);
    btn5->resize(210,70);
    connect(btn5,&QPushButton::clicked,this,[=](){
        this->son->build();
        choice=5;
        modeText = "层序遍历";
        modeLE->setText(modeText);
    });

    QPushButton * btn6=new QPushButton();
    btn6->setText("DFS求最大深度");
    btn6->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 30px; font-family: Calibri;}"
                        "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    btn6->setParent(this);
    btn6->move(1540,640);
    btn6->resize(210,70);
    connect(btn6,&QPushButton::clicked,this,[=](){
        this->son->build2();
        choice=6;
        modeText = "求解最大层数";
        modeLE->setText(modeText);
    });

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

    QPushButton * slideBtn1=new QPushButton();
    slideBtn1->setText("前序遍历");
    slideBtn1->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                             "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    slideBtn1->setParent(codePage);
    slideBtn1->move(150,250);
    slideBtn1->resize(210,70);
    connect(btn1,&QPushButton::clicked,son,&TreeSonWindow::build);
    connect(slideBtn1,&QPushButton::clicked,this,[=](){
        MyDialog * dlg1=new MyDialog(500,440);
        QTextEdit * code1=new QTextEdit(dlg1);
        code1->setText("void f(TreeNode * head)\n"
                       "{\n"
                       "    if(head==nullptr){\n"
                       "        return;\n"
                       "    }\n"
                       "    cout << head->val << \" \";\n"
                       "    f(head->left);\n"
                       "    f(head->right);\n"
                       "}\n");
        code1->setFont(QFont("Calibri",20));
        code1->setStyleSheet("padding:0px;border:0px");
        code1->move(30,60);
        code1->resize(400,340);
        code1->setFocusPolicy(Qt::NoFocus);
        dlg1->show();
    });

    QPushButton * slideBtn2=new QPushButton();
    slideBtn2->setText("中序遍历");
    slideBtn2->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                             "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    slideBtn2->setParent(codePage);
    slideBtn2->move(150,390);
    slideBtn2->resize(210,70);
    connect(btn1,&QPushButton::clicked,son,&TreeSonWindow::build);
    connect(slideBtn2,&QPushButton::clicked,this,[=](){
        MyDialog * dlg2=new MyDialog(500,440);
        QTextEdit * code2=new QTextEdit(dlg2);
        code2->setText("void f(TreeNode * head)\n"
                       "{\n"
                       "    if(head==nullptr){\n"
                       "        return;\n"
                       "    }\n"
                       "    cout << head->val << \" \";\n"
                       "    f(head->left);\n"
                       "    f(head->right);\n"
                       "}\n");
        code2->setFont(QFont("Calibri",20));
        code2->setStyleSheet("padding:0px;border:0px");
        code2->move(30,60);
        code2->resize(400,340);
        code2->setFocusPolicy(Qt::NoFocus);
        dlg2->show();
    });

    QPushButton * slideBtn3=new QPushButton();
    slideBtn3->setText("后序遍历");
    slideBtn3->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                             "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    slideBtn3->setParent(codePage);
    slideBtn3->move(150,530);
    slideBtn3->resize(210,70);
    connect(btn1,&QPushButton::clicked,son,&TreeSonWindow::build);
    connect(slideBtn3,&QPushButton::clicked,this,[=](){
        MyDialog * dlg3=new MyDialog(500,440);
        QTextEdit * code3=new QTextEdit(dlg3);
        code3->setText("void f(TreeNode * head)\n"
                       "{\n"
                       "    if(head==nullptr){\n"
                       "        return;\n"
                       "    }\n"
                       "    f(head->left);\n"
                       "    f(head->right);\n"
                       "    cout << head->val << \" \";\n"
                       "}\n");
        code3->setFont(QFont("Calibri",20));
        code3->setStyleSheet("padding:0px;border:0px");
        code3->move(30,60);
        code3->resize(400,340);
        code3->setFocusPolicy(Qt::NoFocus);
        dlg3->show();
    });

    QPushButton * slideBtn4=new QPushButton();
    slideBtn4->setText("morris");
    slideBtn4->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                             "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    slideBtn4->setParent(codePage);
    slideBtn4->move(150,670);
    slideBtn4->resize(210,70);
    connect(btn1,&QPushButton::clicked,son,&TreeSonWindow::build);
    connect(slideBtn4,&QPushButton::clicked,this,[=](){
        MyDialog * dlg4=new MyDialog(900,1000);
        QTextEdit * code4=new QTextEdit(dlg4);
        code4->setText("void morris(TreeNode * head)\n"
                       "{\n"
                       "    if (head == nullptr) {\n"
                       "        return;\n"
                       "    }\n"
                       "    TreeNode * cur = head;\n"
                       "    TreeNode * mostRight = nullptr;\n"
                       "    while (cur != nullptr)\n"
                       "    {\n"
                       "        mostRight = cur->left;\n"
                       "        if (mostRight != nullptr) {\n"
                       "            while (mostRight->right != nullptr && mostRight->right != cur)\n"
                       "            {\n"
                       "                mostRight = mostRight->right;\n"
                       "            }\n"
                       "            if (mostRight->right == nullptr) {\n"
                       "                mostRight->right = cur;\n"
                       "                cur = cur->left;\n"
                       "                continue;\n"
                       "            } else {\n"
                       "                mostRight->right = nullptr;\n"
                       "            }\n"
                       "        }\n"
                       "        cur = cur->right;\n"
                       "    }\n"
                       "}");
        code4->setFont(QFont("Calibri",20));
        code4->setStyleSheet("padding:0px;border:0px");
        code4->move(30,60);
        code4->resize(770,900);
        code4->setFocusPolicy(Qt::NoFocus);
        dlg4->show();
    });

    QPushButton * slideBtn5=new QPushButton();
    slideBtn5->setText("BFS");
    slideBtn5->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                             "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    slideBtn5->setParent(codePage);
    slideBtn5->move(150,810);
    slideBtn5->resize(210,70);
    connect(slideBtn5,&QPushButton::clicked,this,[=](){
        MyDialog * dlg5=new MyDialog(500,440);
        QTextEdit * code5=new QTextEdit(dlg5);
        code5->setText("void BFS(TreeNode * head)\n"
                       "{\n"
                       "    if (head == nullptr) {\n"
                       "        return;\n"
                       "    }\n"
                       "    queue<TreeNode*> q;\n"
                       "    q.push(head);\n"
                       "    while (!q.empty())\n"
                       "    {\n"
                       "        auto Node = q.front();\n"
                       "        q.pop();\n"
                       "        cout<<Node->val<<\" \";\n"
                       "        if(Node->left)  q.push(Node->left);\n"
                       "        if(Node->right)  q.push(Node->left);\n"
                       "    }\n"
                       "    return\n"
                       "}");
        code5->setFont(QFont("Calibri",20));
        code5->setStyleSheet("padding:0px;border:0px");
        code5->move(30,60);
        code5->resize(400,340);
        code5->setFocusPolicy(Qt::NoFocus);
        dlg5->show();
    });

    QPushButton * slideBtn6=new QPushButton();
    slideBtn6->setText("DFS求最大深度");
    slideBtn6->setStyleSheet("QPushButton{background-color: rgba(58,143,192,20); border-radius: 15px; font: bold 30px; font-family: Calibri;}"
                             "QPushButton:pressed{background-color: rgba(84,255,159,20);}");
    slideBtn6->setParent(codePage);
    slideBtn6->move(150,950);
    slideBtn6->resize(210,70);
    connect(slideBtn6,&QPushButton::clicked,this,[=](){
        MyDialog * dlg6=new MyDialog(500,440);
        QTextEdit * code6=new QTextEdit(dlg6);
        code6->setText("int DFS(TreeNode * head)\n"
                       "{\n"
                       "    if (head == nullptr) {\n"
                       "        return 0;\n"
                       "    }\n"
                       "    return std::max(dfs(head->left),dfs(head->right))+1\n"
                       "}");
        code6->setFont(QFont("Calibri",20));
        code6->setStyleSheet("padding:0px;border:0px");
        code6->move(30,60);
        code6->resize(400,340);
        code6->setFocusPolicy(Qt::NoFocus);
        dlg6->show();
    });

    QTextEdit * text=new QTextEdit(codePage);
    text->setText("(cpp)");
    text->setFont(QFont("Calibri",13));
    text->setStyleSheet("padding:0px;border:0px");
    text->move(450,105);
    text->resize(100,70);
    text->setFocusPolicy(Qt::NoFocus);

    infoPage = new SlidePage(cornerRadius, "INFO", this);
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

    QLineEdit * slideLE1 = new QLineEdit();
    slideLE1->setText("version:                 1.0.0");
    slideLE1->setFont(QFont("Calibri",13));
    slideLE1->setParent(infoPage);
    slideLE1->setStyleSheet("padding:0px;border:0px");
    slideLE1->move(60,200);
    slideLE1->resize(400,100);
    slideLE1->setFocusPolicy(Qt::NoFocus);

    QLineEdit * slideLE2 = new QLineEdit();
    slideLE2->setText("last-upd:             2022.9.16");
    slideLE2->setFont(QFont("Calibri",13));
    slideLE2->setParent(infoPage);
    slideLE2->setStyleSheet("padding:0px;border:0px");
    slideLE2->move(60,300);
    slideLE2->resize(400,100);
    slideLE2->setFocusPolicy(Qt::NoFocus);

    QLineEdit * slideLE3 = new QLineEdit();
    slideLE3->setText("author:                   cc");
    slideLE3->setFont(QFont("Calibri",13));
    slideLE3->setParent(infoPage);
    slideLE3->setStyleSheet("padding:0px;border:0px");
    slideLE3->move(60,400);
    slideLE3->resize(400,100);
    slideLE3->setFocusPolicy(Qt::NoFocus);

    QLineEdit * slideLE4 = new QLineEdit();
    slideLE4->setText("https:github.com/troublemkerrr");
    slideLE4->setFont(QFont("Calibri",10));
    slideLE4->setParent(infoPage);
    slideLE4->setStyleSheet("padding:0px;border:0px");
    slideLE4->move(60,1020);
    slideLE4->resize(400,100);
    slideLE4->setFocusPolicy(Qt::NoFocus);

    //just an icon
    mybutton * github=new mybutton(":/img/img/github.png");
    github->setParent(infoPage);
    github->move(220,990);

    QPushButton * moreInfo=new QPushButton();
    moreInfo->setText("more info");
    moreInfo->setStyleSheet("QPushButton{background-color: rgba(255,255,255); border-radius: 15px; font: bold 43px; font-family: Calibri;}"
                                 "QPushButton:hover{background-color: rgba(58,143,192,20);}");
    moreInfo->setParent(infoPage);
    moreInfo->move(150,600);
    moreInfo->resize(210,70);
    connect(moreInfo,&QPushButton::clicked,this,[=](){
              MyDialog * dlg=new MyDialog(1000,1000);

              QTextEdit * text1=new QTextEdit(dlg);
              text1->setText("What is VisualTree used for?");
              text1->setFont(QFont("Franklin Gothic Demi",13));
              text1->setStyleSheet("padding:0px;border:0px");
              text1->move(40,60);
              text1->resize(450,50);
              text1->setFocusPolicy(Qt::NoFocus);

              QTextEdit * text2=new QTextEdit(dlg);
              text2->setText("It is used to construct a binary tree and demonstrate the traversal process"
                             " of the binary tree.");
              text2->setFont(QFont("Calibri",13));
              text2->setStyleSheet("padding:0px;border:0px");
              text2->move(40,120);
              text2->resize(780,100);
              text2->setEnabled(false);

              QTextEdit * text3=new QTextEdit(dlg);
              text3->setText("How to use VisualTree?");
              text3->setFont(QFont("Franklin Gothic Demi",13));
              text3->setStyleSheet("padding:0px;border:0px");
              text3->move(40,240);
              text3->resize(500,50);
              text3->setFocusPolicy(Qt::NoFocus);

              QTextEdit * text4=new QTextEdit(dlg);
              text4->setText("First of all,you can build a binary tree in the box on the left side of the home page."
                             "Did you just see that blue dot named \"V0\"?It's the root node that exists by default."
                             "Click on it once to select,then move your cursor untill it reaches a suitable position "
                             "and click again.By doing this you can create a child node.");
              text4->setFont(QFont("Calibri",13));
              text4->setStyleSheet("padding:0px;border:0px");
              text4->move(40,295);
              text4->resize(930,250);
              text4->setEnabled(false);

              QTextEdit * text5=new QTextEdit(dlg);
              text5->setText("Once you've created the entire tree,you can select a traversal method and click the"
                             " RUN button to start the traversal process.");
              text5->setFont(QFont("Calibri",13));
              text5->setStyleSheet("padding:0px;border:0px");
              text5->move(40,520);
              text5->resize(930,100);
              text5->setEnabled(false);

              QTextEdit * text6=new QTextEdit(dlg);
              text6->setText("If you want to change the shape of the binary tree,click the CREATE A NEW TREE button to build a "
                             "new binary tree.You can't just delete some of the nodes because...cc is too lazy to implement this.");
              text6->setFont(QFont("Calibri",13));
              text6->setStyleSheet("padding:0px;border:0px");
              text6->move(40,620);
              text6->resize(930,220);
              text6->setEnabled(false);

              QTextEdit * text7=new QTextEdit(dlg);
              text7->setText("You can click on another button in the lower right corner to see the algorithm code for binary "
                             "tree traversal.");
              text7->setFont(QFont("Calibri",13));
              text7->setStyleSheet("padding:0px;border:0px");
              text7->move(40,805);
              text7->resize(930,100);
              text7->setEnabled(false);

              dlg->show();
    });
};

void TreePage::paintEvent(QPaintEvent *)
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
    painter.drawPixmap(1520,320,QPixmap(":/img/img/downArrow.png"));
}

void TreePage::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
}

void TreePage::mouseMoveEvent(QMouseEvent *event)
{
    this->move(this->x() + (event->globalX() - m_lastPos.x()),
               this->y() + (event->globalY() - m_lastPos.y()));
    m_lastPos = event->globalPos();
}
