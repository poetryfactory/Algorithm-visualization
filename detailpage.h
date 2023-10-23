#ifndef DETAILPAGE_H
#define DETAILPAGE_H

#include "graphview.h"
#include "index_mainwindow.h"
#include "mybutton.h"
#include "mydialog.h"
#include "slidepage.h"
#include "sonwindow.h"
#include <QLineEdit>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QRect>
#include <QScrollArea>
#include <QTextEdit>
#include <QVBoxLayout>
#include <string>
class detailpage : public QMainWindow {
  Q_OBJECT
public:
  detailpage(std::string dsname, QWidget *parent = nullptr);

  mybutton *returnBtn;
  mybutton *closeBtn;
  mybutton *moreBtn;
  mybutton *useBtn;
  mybutton *downArrowBtn;
  mybutton *runBtn;
  mybutton *addBtn;

  sonwindow *son;

private:
  void paintEvent(QPaintEvent *);

  /* For dragging */
  QPoint m_lastPos;
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);

  int cornerRadius = 60;

  bool slideFlag = true;
  bool slideFlag2 = true;
  int onShown = 0;
  SlidePage *codePage = nullptr;
  SlidePage *infoPage = nullptr;

  int choice = 0;
};

#endif // DETAILPAGE_H
