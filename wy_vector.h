#ifndef WIDGET_H
#define WIDGET_H
#include "sonwindow.h"
#include <QAction>
#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QInputDialog>
#include <QMenu>
#include <QMutex>
#include <QPen>
#include <QRandomGenerator>
#include <QScrollBar>
#include <QThread>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <Qstring>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
//#include <linux.h>
//#include <winsock.h>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {} // namespace Ui
QT_END_NAMESPACE

class MyVector;
class SceneHolder;
class MyStack;
class MyRectItem : public QObject, public QGraphicsRectItem {
  Q_OBJECT
private:
  int arrayindex;
  SceneHolder *parent;

public:
  MyRectItem(QGraphicsRectItem *parent = 0) : QGraphicsRectItem(parent) {
    setAcceptHoverEvents(true);
  }
  MyRectItem(qreal x, qreal y, qreal width, qreal height,
             SceneHolder *myparent = 0);

  int getindex();
  int getdata();

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
  void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
public slots:
  void addelem(); //添加操作

  void modifyelem(); // 修改操作
  void deleteelem(); // 删除操作
};
class MyDataStructure : public QObject {
  Q_OBJECT
};

class SceneHolder : public sonwindow {
  Q_OBJECT

public:
  sonwindow *mywidget;
  SceneHolder(sonwindow *parent = nullptr);
  ~SceneHolder();
  QGraphicsScene vec;
  vector<vector<MyRectItem *>> items;
  vector<MyVector *> array;
  vector<MyStack *> stack;

private:
signals:
public slots:
  void vec_add(int item_index, int num, int loc);
  void update();
  void vec_remove(int item_index, int loc);
  void vec_modify(int item_index, int loc, int num);
  void vec_hilight(int item_index, int loc, QColor color);
  void vec_lolight(int item_index, int loc);
  int new_item(MyVector *);
  int new_item(MyStack *);
public slots:
  void addarray();
  void addstack();
  void pushelem();
  void sort();
  void speedup();
  void pushtostack();
};

class MyVector : public MyDataStructure {
  Q_OBJECT
public:
  SceneHolder *myscene;
  vector<int> a;
  int item_index;
  int mysize;

public:
  MyVector() {}
  MyVector(SceneHolder *parent);
  ~MyVector();

  void resize(int size);
  void modify(int loc, int num);

  void highlight(int loc, QColor color);
  void lowlight(int loc);
  // void toBarChart();
  void erase(int loc);
  void insert(int loc, int num);
  int size();
  void qsort(int l, int r);
  void test();
  int &operator[](int index);
  void push_back(int num);
  void pop_back();
  void clear();
signals:
  void getindex();
  void sigupdate();
  void workDone();
  void add(int item_index, int num, int mysize);
  void remove(int item_index, int loc);
  void hilight(int item_index, int loc, QColor color);
  void lolight(int item_index, int loc);
  void modifi(int item_index, int loc, int num);
public slots:
  void acceptindex(int index);
  // void slotupdate();
};
class MyStack : public MyVector {
  Q_OBJECT
public:
  MyStack(SceneHolder *parent);
  using MyVector::clear;
  void highlight(QColor color);
  void lowlight();
  int top();
  using MyVector::moveToThread;
  using MyVector::pop_back;
  using MyVector::push_back;
  using MyVector::size;
  using MyVector::test;

protected:
  using MyVector::erase;
  using MyVector::insert;
  using MyVector::modify;
  using MyVector::qsort;
  using MyVector::resize;
  using MyVector::operator[];
};
void delay(int msec);
#endif // WIDGET_H
