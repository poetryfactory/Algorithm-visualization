#ifndef SONWINDOW_H
#define SONWINDOW_H
//#include "myvec_widget.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QWidget>
class SceneHolder;
QT_BEGIN_NAMESPACE
namespace Ui {
class sonwindow;
class QWidget;
} // namespace Ui
QT_END_NAMESPACE
class sonwindow : public QWidget {
  Q_OBJECT
public:
  sonwindow();
  sonwindow(std::string name);
  std::string myname;
  SceneHolder *myscene;
  //*gv;
public:
  Ui::sonwindow *ui;

private:
  void paintEvent(QPaintEvent *);
signals:
  void bt1();
  void bt2();
  void bt3();
  void bt4();
  void bt5();
  void bt6();
};

#endif // SONWINDOW_H
