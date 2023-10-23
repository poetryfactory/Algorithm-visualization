#include "sonwindow.h"
#include "./ui_sonwindow.h"
#include "wy_vector.h"
#include <QVBoxLayout>
sonwindow::sonwindow(){};
sonwindow::sonwindow(std::string name) : ui(new Ui::sonwindow) {
  this->setFixedSize(800, 570);
  this->setWindowFlags(Qt::FramelessWindowHint);
  this->setMouseTracking(true);
  this->setCursor(Qt::CrossCursor);
  ui->setupUi(this);
  myname = name;
  if (name == "array") {
    ui->graphicsview->resize(800, 570);
    ui->graphicsview->setParent(this);
    ui->graphicsview->show();
    myscene = new SceneHolder(this);
    connect(this, &sonwindow::bt1, myscene, &SceneHolder::addarray);
    connect(this, &sonwindow::bt2, myscene, &SceneHolder::addstack);
    connect(this, &sonwindow::bt3, myscene, &SceneHolder::pushelem);
    connect(this, &sonwindow::bt4, myscene, &SceneHolder::sort);
    connect(this, &sonwindow::bt5, myscene, &SceneHolder::pushtostack);
    connect(this, &sonwindow::bt6, myscene, &SceneHolder::speedup);
    this->show();
  }
}

void sonwindow::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  QPen pen(QColor(180, 180, 180));
  pen.setWidth(3);
  painter.setPen(pen);

  QBrush brush(QColor(255, 255, 255));
  painter.setBrush(brush);

  /* set the rounded border */
  QRect rect = this->rect();
  rect.setWidth((rect.width() - 1));
  rect.setHeight(rect.height() - 1);
  painter.drawRoundedRect(rect, 30, 30);
}
