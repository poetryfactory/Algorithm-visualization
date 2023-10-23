#include "wy_vector.h"
#include "./ui_sonwindow.h"
#include "qeventloop.h"
#include "sonwindow.h"

// extern MyVector *vecto;
// extern SceneHolder *myscene;
QMutex mymutex;
double k = 1;

void delay(int msec) {
  QEventLoop loop;
  QTimer::singleShot(msec, &loop, SLOT(quit()));
  loop.exec();
}

void SceneHolder::update() {
  vec.update();
  // ui->graphicsView->show();
};

SceneHolder::SceneHolder(sonwindow *parent) {
  mywidget = parent;
  parent->ui->graphicsview->setScene(&vec);
  parent->ui->graphicsview->show();
  vec.update();
  items.clear();
  vec.setItemIndexMethod(QGraphicsScene::NoIndex);
}
SceneHolder::~SceneHolder() {}

int SceneHolder::new_item(MyVector *x) {
  array.push_back(x);
  int k = (int)items.size();
  items.push_back(vector<MyRectItem *>());
  return k;
}
int SceneHolder::new_item(MyStack *x) {
  stack.push_back(x);
  int k = (int)items.size();
  items.push_back(vector<MyRectItem *>());
  return k;
}
MyVector::MyVector(SceneHolder *parent) {
  this->myscene = parent;
  a.clear();
  mysize = 0;
  connect(this, &MyVector::sigupdate, myscene, &SceneHolder::update);
  connect(this, &MyVector::add, myscene, &SceneHolder::vec_add);
  connect(this, &MyVector::remove, myscene, &SceneHolder::vec_remove);
  connect(this, &MyVector::hilight, myscene, &SceneHolder::vec_hilight);
  connect(this, &MyVector::lolight, myscene, &SceneHolder::vec_lolight);
  connect(this, &MyVector::modifi, myscene, &SceneHolder::vec_modify);
  item_index = myscene->new_item(static_cast<MyVector *>(this));
  QThread *mythread = new QThread;
  this->moveToThread(mythread);
}
MyStack::MyStack(SceneHolder *parent) {
  this->myscene = parent;
  a.clear();
  mysize = 0;
  connect(this, &MyVector::sigupdate, myscene, &SceneHolder::update);
  connect(this, &MyVector::add, myscene, &SceneHolder::vec_add);
  connect(this, &MyVector::remove, myscene, &SceneHolder::vec_remove);
  connect(this, &MyVector::hilight, myscene, &SceneHolder::vec_hilight);
  connect(this, &MyVector::lolight, myscene, &SceneHolder::vec_lolight);
  connect(this, &MyVector::modifi, myscene, &SceneHolder::vec_modify);
  item_index = myscene->new_item(static_cast<MyStack *>(this));
  QThread *mythread = new QThread;
  this->moveToThread(mythread);
}
void MyVector::acceptindex(int index) { item_index = index; }
void SceneHolder::vec_add(int item_index, int num, int loc) {

  MyRectItem *rect = new MyRectItem(30 * items[item_index].size(),
                                    50 * item_index, 30, 30, this);
  items[item_index].push_back(rect);
  QGraphicsTextItem *data = //值文本图元
      new QGraphicsTextItem(QString::fromStdString(to_string(0)),
                            items[item_index][items[item_index].size() - 1]);
  data->setPos(rect->boundingRect().center() - data->boundingRect().center());
  data->setData(0, "data"); //相当于间接给图元命名

  //加入到items[item_index]
  QGraphicsTextItem *index = //下标文本图元
      new QGraphicsTextItem(
          QString::fromStdString(to_string(items[item_index].size() - 1)),
          items[item_index][items[item_index].size() - 1]);
  index->setPos(rect->boundingRect().center() - data->boundingRect().center() +
                QPointF(0, 30));
  index->setData(0, "index");
  for (int i = (int)items[item_index].size() - 1; i > loc + 1; i--) {
    int tmp = 0;
    for (QGraphicsItem *x :
         items[item_index][i - 1]->childItems()) { //改显示的文本
      QGraphicsTextItem *TextItem = dynamic_cast<QGraphicsTextItem *>(x);
      if (TextItem && TextItem->data(0).toString() == "data") { //定位到数据图元
        tmp = TextItem->toPlainText().toInt(); //存下tmp的值,
      }
      for (QGraphicsItem *x :
           items[item_index][i]->childItems()) { //改显示的文本
        QGraphicsTextItem *TextItem = dynamic_cast<QGraphicsTextItem *>(x);
        if (TextItem && TextItem->data(0).toString() == "data") //定位到数据图元
          TextItem->setPlainText(QString::fromStdString(to_string(tmp)));
      }
    }
  }
  for (QGraphicsItem *x :
       items[item_index][loc + 1]->childItems()) { //改显示的文本
    QGraphicsTextItem *TextItem = dynamic_cast<QGraphicsTextItem *>(x);
    if (TextItem && TextItem->data(0).toString() == "data") //定位到数据图元
      TextItem->setPlainText(QString::fromStdString(to_string(num)));
  }
  vec.addItem(rect);
}
void SceneHolder::vec_remove(int item_index, int loc) {
  //把后面图元的数据全部左移一个 然后去掉最后一个图元

  for (int i = loc; i <= (int)items[item_index].size() - 2; i++) {
    int tmp = 0;
    for (QGraphicsItem *x :
         items[item_index][i + 1]->childItems()) { //改显示的文本
      QGraphicsTextItem *TextItem = dynamic_cast<QGraphicsTextItem *>(x);
      if (TextItem && TextItem->data(0).toString() == "data") //定位到数据图元
        tmp = TextItem->toPlainText().toInt();                //存下tmp的值
    }
    for (QGraphicsItem *x : items[item_index][i]->childItems()) { //改显示的文本
      QGraphicsTextItem *TextItem = dynamic_cast<QGraphicsTextItem *>(x);
      if (TextItem && TextItem->data(0).toString() == "data") //定位到数据图元
        TextItem->setPlainText(QString::fromStdString(to_string(tmp)));
    }
  }
  if (!items[item_index].empty()) {
    vec.removeItem(items[item_index][(int)items[item_index].size() - 1]);
    auto *p = items[item_index][(int)items[item_index].size() - 1]; //释放资源
    items[item_index].pop_back();
    delete p;
  }
}
void SceneHolder::vec_modify(int item_index, int loc, int num) {
  for (QGraphicsItem *x : items[item_index][loc]->childItems()) { //改显示的文本
    QGraphicsTextItem *TextItem = dynamic_cast<QGraphicsTextItem *>(x);
    if (TextItem && TextItem->data(0).toString() == "data") //定位到数据图元
      TextItem->setPlainText(QString::fromStdString(to_string(num)));
  }
}
void SceneHolder::vec_hilight(int item_index, int loc, QColor color) {
  QPen pen = items[item_index][loc]->pen();
  pen.setColor(Qt::red);
  items[item_index][loc]->setPen(pen);
  items[item_index][loc]->setBrush(color);
}
void SceneHolder::vec_lolight(int item_index, int loc) {
  QPen pen = items[item_index][loc]->pen();
  pen.setColor(Qt::black);
  items[item_index][loc]->setPen(pen);
  items[item_index][loc]->setBrush(Qt::transparent);
}
void MyVector::push_back(int num) {
  a.push_back(num);
  emit add(item_index, num, mysize - 1);
  mysize++;
  emit sigupdate();
}
void MyVector::pop_back() {
  a.pop_back();
  emit remove(item_index, mysize - 1);
  mysize--;
}
void MyVector::erase(int loc) {
  a.erase(a.begin() + loc);
  emit remove(item_index, loc);
  mysize--;
}
void MyVector::insert(int loc, int num) {
  a.insert(a.begin() + loc, num);
  emit add(item_index, num, loc);
  mysize++;
  emit sigupdate();
}
void MyVector::resize(int n) {
  if (n < mysize) {
    for (int i = a.size(); i >= n; i--) {
      a.pop_back();
    }
  } else if (n > mysize) {
    while (a.size() < n) {
      a.push_back(0);
    }
  }
}
void MyVector::clear() {
  while (a.size())
    a.pop_back();
}
void MyVector::modify(int loc, int num) {
  a[loc] = num; //改值
  emit modifi(item_index, loc, num);
}
int MyVector::size() { return a.size(); }
void MyVector::highlight(int loc, QColor color) {
  emit hilight(item_index, loc, color);
  emit sigupdate();
}
void MyVector::lowlight(int loc) {
  emit lolight(item_index, loc);
  emit sigupdate();
}
int &MyVector::operator[](int index) { return a[index]; }
void MyVector::test() {

  // for (int i = 0; i < 10; i++) {
  //  push_back(10 - i);
  //}
  // qsort(0, 9);
}
int MyRectItem::getdata() {
  for (QGraphicsItem *x : this->childItems()) {
    QGraphicsTextItem *TextItem = dynamic_cast<QGraphicsTextItem *>(x);
    if (TextItem && TextItem->data(0).toString() == "data") //定位到
      return TextItem->toPlainText().toInt();
  }
}
int MyRectItem::getindex() {
  for (QGraphicsItem *x : this->childItems()) {
    QGraphicsTextItem *TextItem = dynamic_cast<QGraphicsTextItem *>(x);
    if (TextItem && TextItem->data(0).toString() == "index") //定位到
      return TextItem->toPlainText().toInt();
  }
}
void MyVector::qsort(int l, int r) {

  if (l >= r)
    return;

  int i = l - 1, j = r + 1, x = a[l + r >> 1];
  highlight(l + r >> 1, Qt::green); //高亮分割边界
  delay(200 * k);
  while (i < j) {

    do {
      // if (i >= l && i <= r)
      // lowlight(i);
      i++;
      highlight(i, Qt::blue);
      delay(100 * k);

    } while (a[i] < x);
    do {
      // if (j >= l && j <= r)
      // lowlight(j);
      j--;
      highlight(j, Qt::red);
      delay(100 * k);
    } while (a[j] > x);
    if (i < j) {
      swap(a[i], a[j]);
      highlight(i, Qt::red);
      highlight(j, Qt::blue);
      modify(i, a[i]);
      modify(j, a[j]);
      delay(100 * k);
      // lowlight(i);
      // lowlight(j);
    } else {
      delay(100 * k);
      // lowlight(i);
      // lowlight(j);
    }
  }
  for (int i = l; i <= r; i++)
    lowlight(i);
  qsort(l, j);
  qsort(j + 1, r);
}
void MyRectItem::addelem() {
  bool ok;
  int i = QInputDialog::getInt(parent->mywidget, "标题", "请输入数值:", 25, 0,
                               100, 1, &ok);
  if (ok) {
    int k = getindex();
    parent->array[arrayindex]->insert(k, i);
  }
}
void MyRectItem::modifyelem() {
  bool ok;
  int i = QInputDialog::getInt(parent->mywidget, "标题", "请输入数值:", 25, 0,
                               100, 1, &ok);
  if (ok) {
    int k = getindex();
    parent->array[arrayindex]->modify(k, i);
  }
}

void MyRectItem::deleteelem() {
  k = getindex();
  parent->array[arrayindex]->erase(k);
}
void MyRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (event->button() == Qt::LeftButton && contains(event->pos())) {
    QMenu menu;

    QAction *addAction = menu.addAction("添加");
    QAction *modifyAction = menu.addAction("修改");
    QAction *deleteAction = menu.addAction("删除");

    connect(addAction, &QAction::triggered, this, &MyRectItem::addelem);
    connect(modifyAction, &QAction::triggered, this, &MyRectItem::modifyelem);
    connect(deleteAction, &QAction::triggered, this, &MyRectItem::deleteelem);
    menu.exec(event->screenPos());
  }
}
MyRectItem::MyRectItem(qreal x, qreal y, qreal width, qreal height,
                       SceneHolder *myparent)
    : QGraphicsRectItem(x, y, width, height) {
  // 在这里添加你的代码
  setAcceptHoverEvents(true);
  arrayindex = y / 50;
  parent = myparent;
}
void MyRectItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
  setBrush(QColor("#6495ED"));
  QGraphicsRectItem::hoverEnterEvent(event);
}

void MyRectItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
  setBrush(Qt::transparent);
  QGraphicsRectItem::hoverLeaveEvent(event);
}
void MyStack::highlight(QColor color) {
  MyVector::highlight(mysize - 1, color);
}
void MyStack::lowlight() { MyVector::lowlight(mysize - 1); }
MyVector::~MyVector(){};
int MyStack::top() {
  if (a.size())
    return a[a.size() - 1];
}
void SceneHolder::pushelem() {
  for (int i = 0; i < 10; i++) {
    this->array[0]->push_back(QRandomGenerator::global()->bounded(100));
  }
}

void SceneHolder::sort() {
  this->array[0]->qsort(0, this->array[0]->size() - 1);
}

void SceneHolder::pushtostack() {

  int arraysize = this->array[0]->size();
  for (int i = 0; i < arraysize; i++) {
    int tmp = this->array[0]->a[0];
    this->array[0]->erase(0);
    this->stack[0]->push_back(tmp);
    delay(500 * k);
  }
  for (int i = 0; i < arraysize; i++) {
    int tmp = this->stack[0]->top();
    this->stack[0]->pop_back();
    this->array[0]->push_back(tmp);

    delay(500 * k);
  }
}

void SceneHolder::addarray() {
  MyVector *b = new MyVector(this);
  b->push_back(1);
}
void SceneHolder::addstack() {
  MyStack *b = new MyStack(this);
  b->push_back(0);
}

void SceneHolder::speedup() { k /= 2.0; }
