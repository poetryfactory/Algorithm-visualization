#ifndef LINKLIST_H
#define LINKLIST_H

#include <QWidget>
#include <QFile>
#include <QTextBrowser>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QIntValidator>
#include <QTextBrowser>
#include <QPushButton>
#include <QComboBox>
#include <QAbstractSlider>
#include <QLineEdit>
#include <QSlider>
#include <QVBoxLayout>
#include <QIODevice>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include "uidefine.h"
#include "lnode.h"
#include "myarrowitem.h"
#include "mybutton.h"
#include "listpage.h"

class LinkList : public QWidget
{
    Q_OBJECT
public:
    explicit LinkList(QWidget *parent = 0);			//构造函数

    QGraphicsView *graphicsView = new QGraphicsView(this);
    QTextBrowser *textBrowser = new QTextBrowser(this);
    QPushButton *pushButtonDelete = new QPushButton(this);
    QLabel *labelDeleteValue = new QLabel(this);
    QLineEdit *lineEditDelete = new QLineEdit(this);
    QComboBox *comboBoxDelete = new QComboBox(this);
    QLabel *labelDeletePos = new QLabel(this);
    QPushButton *pushButtonLocate = new QPushButton(this);
    QLineEdit *lineEditLocate = new QLineEdit(this);
    QComboBox *comboBoxLocate = new QComboBox(this);
    QLabel *labelLocateValue = new QLabel(this);
    QLabel *labelResultPos = new QLabel(this);
    QLabel *labelTimeControl = new QLabel(this);
    QPushButton *pushButtonInit = new QPushButton(this);
    QLabel *labelInsertValue = new QLabel(this);
    QLineEdit *lineEditInsert = new QLineEdit(this);
    QPushButton *pushButtonInsert = new QPushButton(this);
    QComboBox *comboBoxInsert = new QComboBox(this);
    QLabel *labelInsert = new QLabel(this);
    QLabel *labelState = new QLabel(this);
    QLineEdit *lineEditState = new QLineEdit(this);
    QSlider *horizontalSlider = new QSlider(this);
    QPushButton *pushButtonRandomInsert5 = new QPushButton(this);
    QPushButton *pushButtonClear = new QPushButton(this);

    mybutton * returnBtn;

    ~LinkList();									//析构函数
private slots:
    void on_pushButtonInit_clicked();					//槽函数：点击创建
    void on_pushButtonClear_clicked();                  //槽函数：点击清空
    void on_pushButtonInsert_clicked();					//槽函数：点击插入
    void on_pushButtonRandomInsert5_clicked();			//随机插入五个节点到链表末尾
    void on_pushButtonDelete_clicked();					//槽函数：点击删除
    void on_pushButtonLocate_clicked();					//槽函数：点击查找
    void on_horizontalSlider_valueChanged(int value);	//调整演示的速度快慢
protected:
    QGraphicsScene *scene;          //视图场景指针
    QGraphicsTextItem *headLabel;   //链表符号指针
    MyArrowItem *headArrow;         //符号箭头指针
    LNode *head;                    //头结点指针
    int countNode;                  //节点个数计数（不包括头结点）
    int sleepTime;                  //演示延时时间（ms）
    void initTextBrowser();			//初始设置文本显示区
    void initUI();					//初始UI控件
    void initSceneView();			//初始化视图框架
    void adjustController();		//操作之后调整右侧输入和显示控件
    QPoint getLNodePos(int nodeNumber);						//计算节点的Scene坐标
    void addLNodeGraphicsItem(LNode *pl, QPoint coord);		//添加节点的GraphicsItem
    void adjustLNodeArrow(LNode *pLNode, int nodeNumber);	//调整节点的箭头
    void adjustLNodePos(LNode *pLNode, QPoint coord);		//调整节点Scene坐标
    void setLinkListNormalBrush();							//设置链表所有节点显示模式
    void initLinkList();						//创建链表初始化
    void insertLNode(int pos, QString elem);	//插入节点到链表
    void deleteLNode(int pos, QString &elem);	//删除链表节点
    bool locateLNode(int &pos,QString elem);	//查找链表节点
    void destroySelf();							//释放申请的内存空间
private:
    //静态常数据，类似于宏
    const static QBrush normalBursh, visitedBrush, markBrush;
    const static QFont headLabelFont, dataFont;
    const static QIntValidator dataValidator;

    /*QPushButton * pushButtonDelete1 = new QPushButton();
    QComboBox * comboBoxDelete1 = new QComboBox();
    QComboBox * comboBoxInsert1 = new QComboBox();
    QComboBox * comboBoxLocate1 = new QComboBox();
    QLineEdit * lineEditDelete1 = new QLineEdit();
    QLineEdit * lineEditState1 = new QLineEdit();
    QLineEdit * lineEditInsert1 = new QLineEdit();
    QPushButton * pushButtonClear1 = new QPushButton();
    QPushButton * pushButtonInsert1 = new QPushButton();
    QPushButton * pushButtonRandomInsert51 = new QPushButton();
    QPushButton * pushButtonLocate1 = new QPushButton();
    QLineEdit * lineEditLocate1 = new QLineEdit();*/
    //QSlider * horizontalSlider = new QSlider();

};
#endif // LINKLIST_H
