#include "index_mainwindow.h"
#include "./ui_index_mainwindow.h"

index_mainWindow::index_mainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::index_mainWindow) {
  ui->setupUi(this);
  this->setFixedSize(1280, 760);
  this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint |
                       Qt::WindowMaximizeButtonHint);
  this->setAttribute(Qt::WA_TranslucentBackground);
  this->setWindowIcon(QIcon(":/img/img/circle.ico"));
  this->setStyleSheet("background: rgba(195,231,253,1); border-radius: 60px");

  closeBtn = new mybutton(":/img/img/close.png");
  closeBtn->setParent(this);
  closeBtn->move(1180, 40);
  connect(closeBtn, &mybutton::clicked, this, &index_mainWindow::close);

  QLineEdit *h1 = new QLineEdit();
  h1->setText("算法可视化");
  h1->setFont(QFont("STKaiti", 36, QFont::Bold));
  h1->setParent(this);
  h1->setStyleSheet("padding:0px; border:0px;");
  h1->move(560, 30);
  h1->resize(300, 90);
  h1->setFocusPolicy(Qt::NoFocus);

  QLineEdit *h2 = new QLineEdit();
  h2->setText("Algorithm visualization");
  h2->setFont(QFont("Segoe Print", 28, QFont::Bold));
  h2->setParent(this);
  h2->setStyleSheet("padding:0px; border:0px;");
  h2->move(502, 94);
  h2->resize(350, 40);
  h2->setFocusPolicy(Qt::NoFocus);

  QScrollArea *scrollArea = new QScrollArea(this);
  QWidget *scrollWidget = new QWidget(this);
  scrollArea->setParent(this);
  QVBoxLayout *layout_scrollWidget = new QVBoxLayout(scrollWidget);
  layout_scrollWidget->setSpacing(0);
  layout_scrollWidget->addWidget(0);
  scrollArea->setWidget(scrollWidget);
  scrollArea->setGeometry(QRect(0, 160, 1280, 760));
  scrollWidget->setGeometry(QRect(0, 160, 1280, 1200));
  scrollArea->setWidgetResizable(false);
  scrollArea->setStyleSheet(
      "background: rgba(163,198,236,1); border-radius: 0px");

  jumptoBtn = new mybutton(":/img2/img/array.png");
  jumptoBtn->setIconSize(QSize(360,360));
  jumptoBtn->setParent(scrollWidget);
  jumptoBtn->move(150, 50);
  jumptoBtn->setFixedSize(400, 400);
  jumptoBtn->setStyleSheet(
      "border-style: solid; border-width: 2px; border-radius: 20px; "
      "border-color: rgb(169,169,169)");
  connect(jumptoBtn, &mybutton::clicked, this, [=]() {
    this->hide();
    detailpage *d = new detailpage("array");
    d->show();
    connect(d->returnBtn, &mybutton::clicked, this, [=]() {
      this->show();
      d->hide();
    });
  });

  QLineEdit *h3 = new QLineEdit();
  h3->setText("array");
  h3->setFont(QFont("Segoe Print", 28, QFont::Bold));
  h3->setParent(jumptoBtn);
  h3->move(0, 360);
  h3->resize(400, 40);
  h3->setFocusPolicy(Qt::NoFocus);
  h3->setStyleSheet(
      "border: 2px groove gray; border-radius: 10px; padding-bottom:5px");

  jumptoBtn2 = new mybutton(":/img2/img/list.jpg");
  jumptoBtn2->setIconSize(QSize(360,360));
  jumptoBtn2->setParent(scrollWidget);
  jumptoBtn2->move(750, 50);
  jumptoBtn2->setFixedSize(400, 400);
  jumptoBtn2->setStyleSheet(
      "border-style: solid; border-width: 2px; border-radius: 20px; "
      "border-color: rgb(169,169,169)");
  connect(jumptoBtn2, &mybutton::clicked, this, [=]() {
    this->hide();
    list_mainwindow * l = new list_mainwindow();
    l->show();
    connect(l->returnBtn, &mybutton::clicked, this, [=]() {
      this->show();
      l->hide();
    });
  });

  QLineEdit *h4 = new QLineEdit();
  h4->setText("list");
  h4->setFont(QFont("Segoe Print", 28, QFont::Bold));
  h4->setParent(jumptoBtn2);
  h4->move(0, 360);
  h4->resize(400, 40);
  h4->setFocusPolicy(Qt::NoFocus);
  h4->setStyleSheet(
      "border: 2px groove gray; border-radius: 10px; padding-bottom:5px");

  jumptoBtn3 = new mybutton(":/img3/img/tree.jpg");
  jumptoBtn3->setIconSize(QSize(360,360));
  jumptoBtn3->setParent(scrollWidget);
  jumptoBtn3->move(150, 550);
  jumptoBtn3->setFixedSize(400, 400);
  jumptoBtn3->setStyleSheet(
      "border-style: solid; border-width: 2px; border-radius: 20px; "
      "border-color: rgb(169,169,169)");
  connect(jumptoBtn3, &mybutton::clicked, this, [=]() {
    this->hide();
    TreePage* tp = new TreePage();
    tp->show();
    connect(tp->returnBtn, &mybutton::clicked, this, [=]() {
      this->show();
      tp->hide();
    });
  });

  QLineEdit *h5 = new QLineEdit();
  h5->setText("tree");
  h5->setFont(QFont("Segoe Print", 28, QFont::Bold));
  h5->setParent(jumptoBtn3);
  h5->move(0, 360);
  h5->resize(400, 40);
  h5->setFocusPolicy(Qt::NoFocus);
  h5->setStyleSheet(
      "border: 2px groove gray; border-radius: 10px; padding-bottom:5px");

  jumptoBtn4 = new mybutton(":/img3/img/graph.jpg");
  jumptoBtn4->setIconSize(QSize(360,360));
  jumptoBtn4->setParent(scrollWidget);
  jumptoBtn4->move(750, 550);
  jumptoBtn4->setFixedSize(400, 400);
  jumptoBtn4->setStyleSheet(
      "border-style: solid; border-width: 2px; border-radius: 20px; "
      "border-color: rgb(169,169,169)");
  connect(jumptoBtn4, &mybutton::clicked, this, [=]() {
    this->hide();
      GraphPage *gp = new GraphPage();
      gp->show();
    connect(gp->returnBtn, &mybutton::clicked, this, [=]() {
      this->show();
      gp->hide();
    });
  });

  QLineEdit *h6 = new QLineEdit();
  h6->setText("graph");
  h6->setFont(QFont("Segoe Print", 28, QFont::Bold));
  h6->setParent(jumptoBtn4);
  h6->move(0, 360);
  h6->resize(400, 40);
  h6->setFocusPolicy(Qt::NoFocus);
  h6->setStyleSheet(
      "border: 2px groove gray; border-radius: 10px; padding-bottom:5px");
}

void index_mainWindow::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  QPen pen(QColor(100, 100, 100, 50));
  pen.setWidth(3);
  painter.setPen(pen);

  QBrush brush(QColor(255, 255, 255));
  painter.setBrush(brush);

  /* set the rounded border */
  QRect rect = this->rect();
  rect.setWidth((rect.width() - 1));
  rect.setHeight(rect.height() - 1);
  painter.drawRoundedRect(rect, cornerRadius, cornerRadius);

  QBrush brush2(QColor(0, 0, 0));
  painter.setBrush(brush2);
  painter.drawPixmap(1520, 320, QPixmap(":/new/prefix1/img/downArrow.png"));
}

void index_mainWindow::mousePressEvent(QMouseEvent *event) {
  m_lastPos = event->globalPos();
}

void index_mainWindow::mouseMoveEvent(QMouseEvent *event) {
  this->move(this->x() + (event->globalX() - m_lastPos.x()),
             this->y() + (event->globalY() - m_lastPos.y()));
  m_lastPos = event->globalPos();
}

index_mainWindow::~index_mainWindow() { delete ui; }
