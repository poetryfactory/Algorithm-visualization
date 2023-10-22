#include<QDebug>
#include <math.h>
#include "linklist.h"
#include "myarrowitem.h"
void sleep(unsigned int msec);
const QBrush LinkList::normalBursh=QBrush(Qt::GlobalColor::darkGray);
const QBrush LinkList::visitedBrush=QBrush(Qt::GlobalColor::yellow);
const QBrush LinkList::markBrush=QBrush(Qt::GlobalColor::green);
const QFont LinkList::headLabelFont=QFont("Consolas");
const QFont LinkList::dataFont=QFont("Consolas",8);
const QIntValidator LinkList::dataValidator(-999999999,999999999);
//构造函数
LinkList::LinkList(QWidget *parent)
    :QWidget(parent)
{
    //初始化数据
    initTextBrowser();
    initUI();
    countNode=0;
    head=NULL;
    headLabel=NULL;
    headArrow=NULL;
    scene=NULL;
    sleepTime=MAX_SLEEP_TIME>>1;
    horizontalSlider->setValue(MAX_SLIDER>>1);
    srand(time(NULL));
    this->setWindowTitle("单链表");
}
//析构函数
LinkList::~LinkList()
{
    destroySelf();
}
//初始设置文本显示区
void LinkList::initTextBrowser(){
    //加载html文件
    QFile file(":/html/html/LinkList.html");
    file.open(QIODevice::ReadOnly);
    QString htmlString=file.readAll();
    QTextBrowser * textBrowser = new QTextBrowser();
    textBrowser->setHtml(htmlString);
    textBrowser->setOpenLinks(true);
    textBrowser->setOpenExternalLinks(true);
    file.close();
}
//初始UI控件
void LinkList::initUI()
{
    //set background image;
    QPixmap background(":/ico/resource/background.png");
    QPalette palette;
    palette.setBrush(QPalette::Window,background);
    this->setPalette(palette);
    //未创建时，除创建按钮外，其余按键一律无效
    QPushButton * pushButtonClear = new QPushButton();
    pushButtonClear->setEnabled(false);
    QPushButton * pushButtonInsert = new QPushButton();
    pushButtonInsert->setEnabled(false);
    QPushButton * pushButtonRandomInsert5 = new QPushButton();
    pushButtonRandomInsert5->setEnabled(false);
    QComboBox * comboBoxInsert = new QComboBox();
    comboBoxInsert->setEnabled(false);
    QLineEdit * lineEditInsert = new QLineEdit();
    lineEditInsert->setEnabled(false);
    lineEditInsert->setFont(dataFont);
    lineEditInsert->setPlaceholderText("插入值：Int");
    lineEditInsert->setValidator(&LinkList::dataValidator);
    QPushButton * pushButtonDelete = new QPushButton();
    pushButtonDelete->setEnabled(false);
    QComboBox * comboBoxDelete = new QComboBox();
    comboBoxDelete->setEnabled(false);
    QLineEdit * lineEditDelete = new QLineEdit();
    lineEditDelete->setEnabled(false);
    lineEditDelete->setFont(dataFont);
    QPushButton * pushButtonLocate = new QPushButton();
    pushButtonLocate->setEnabled(false);
    QComboBox * comboBoxLocate = new QComboBox();
    comboBoxLocate->setEnabled(false);
    QLineEdit * lineEditLocate = new QLineEdit();
    lineEditLocate->setEnabled(false);
    lineEditLocate->setFont(dataFont);
    lineEditLocate->setPlaceholderText("查找值：Int");
    lineEditLocate->setValidator(&LinkList::dataValidator);
    QLineEdit * lineEditState = new QLineEdit();
    lineEditState->setEnabled(false);
    lineEditState->setFont(dataFont);
    lineEditState->setText("请选择操作");

    horizontalSlider->setMinimum(0);
    horizontalSlider->setMaximum(MAX_SLIDER);
    horizontalSlider->setTickPosition(QSlider::TicksBelow);
}
//初始化视图框架
void LinkList::initSceneView()
{
    //为 view 配置相应 scene
    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,SCENE_MAX_W,SCENE_MAX_H);
    QGraphicsView * graphicsView = new QGraphicsView();
    graphicsView->setScene(scene);
    //添加链表符号及指针箭头
    headLabel=scene->addText("L",headLabelFont);
    headLabel->setPos((VALUE_RECT_W-RECT_H)>>1,SPACING);
    sleep(sleepTime);
    headArrow=new MyArrowItem(ARROW_LEN);
    scene->addItem(headArrow);
    headArrow->setPos(ARROW_H_OFFSET,ARROW_V_OFFSET);
}
//操作之后调整右侧输入和显示控件
void LinkList::adjustController()
{
    //当经过插入或删除操作后，节点个数可能会改变，需考虑一些操作的合法性
    pushButtonDelete->setEnabled(countNode);
    comboBoxDelete->setEnabled(countNode);
    if(comboBoxDelete->count()!=countNode)
    {
        QStringList qStringList;
        for(int i=1;i<=countNode;++i)
            qStringList.push_back(QString::number(i));
        comboBoxInsert->clear();
        comboBoxInsert->addItems(qStringList);
        comboBoxDelete->clear();
        comboBoxDelete->addItems(qStringList);
    }
    if(comboBoxInsert->count()!=countNode+1)
        comboBoxInsert->addItem(QString::number(countNode+1));
    lineEditDelete->setText(" ");
    comboBoxLocate->clear();
}
//计算节点的Scene坐标
QPoint LinkList::getLNodePos(int nodeNumber)
{
    const static int rowN=SCENE_MAX_W/NODE_W;
    return QPoint((nodeNumber+1)%rowN*NODE_W,(nodeNumber+1)/rowN*NODE_H);
}
//添加节点的GraphicsItem
void LinkList::addLNodeGraphicsItem(LNode *pl, QPoint coord)
{
    int x=coord.x(), y=coord.y();
qDebug()<<"x="<<x<<" y="<<y<<"\n";
    pl->valueRect   =scene->addRect(x,y+SPACING,VALUE_RECT_W,RECT_H,QPen(),LinkList::markBrush);
    pl->pointerRect =scene->addRect(x+VALUE_RECT_W,y+SPACING,POINTER_RECT_W,RECT_H);
    pl->valueText   =scene->addText(pl->data,LinkList::dataFont);
    pl->valueText->setPos(x,y+SPACING+5);
    if(pl->next==NULL)
    {
        pl->pointerText=scene->addText(" ^",LinkList::dataFont);
        pl->pointerText->setPos(x+VALUE_RECT_W, y+SPACING+5);
    }
}
//调整节点的箭头
void LinkList::adjustLNodeArrow(LNode *pLNode, int nodeNumber)
{
    for(auto &a:pLNode->arrowVector)
        scene->removeItem(a);
    if(pLNode->next==NULL)
        return ;
    QPoint myCoord=getLNodePos(nodeNumber);
    QPoint nextCoord=getLNodePos(nodeNumber+1);
    MyArrowItem *pArrow;
    if(myCoord.y()==nextCoord.y())
    {
        //节点不是一行最后节点
        pArrow=new MyArrowItem(ARROW_LEN);
        scene->addItem(pArrow);
        pArrow->setPos(myCoord.x()+ARROW_H_OFFSET,myCoord.y()+ARROW_V_OFFSET);
        pLNode->arrowVector.push_back(pArrow);
    }
    else
    {
        //节点是一行中最后节点
        QPoint point1(myCoord.x()+ARROW_H_OFFSET,myCoord.y()+ARROW_V_OFFSET);
        QPoint point2(point1.x(),point1.y()+NODE_H/2);
        QPoint point3(VALUE_RECT_W>>1,point2.y());
        pArrow=new MyArrowItem(NODE_H>>1,2,0);
        scene->addItem(pArrow);
        pArrow->setPos(point1);
        pLNode->arrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(point2.x()-point3.x(),3,0);
        scene->addItem(pArrow);
        pArrow->setPos(point2);
        pLNode->arrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(SPACING,2);
        scene->addItem(pArrow);
        pArrow->setPos(point3);
        pLNode->arrowVector.push_back(pArrow);
    }
}
//调整节点Scene坐标
void LinkList::adjustLNodePos(LNode *pLNode, QPoint coord)
{
    int x=coord.x(), y=coord.y();
    pLNode->valueRect->setRect(x,y+SPACING,VALUE_RECT_W,RECT_H);
    pLNode->pointerRect->setRect(x+VALUE_RECT_W,y+SPACING,POINTER_RECT_W,RECT_H);
    pLNode->valueText->setPos(x,y+SPACING+5);
    if(pLNode->pointerText)
        pLNode->pointerText->setPos(x+VALUE_RECT_W, y+SPACING+5);
}
//设置链表所有节点显示模式
void LinkList::setLinkListNormalBrush()
{
    for(LNode *pLNode=head;pLNode;pLNode=pLNode->next)
        pLNode->setNodeStatus(LinkList::normalBursh);
}
//创建链表初始化
void LinkList::initLinkList()
{
    initSceneView();
sleep(sleepTime);
    head=new LNode("头结点", NULL);
    addLNodeGraphicsItem(head, getLNodePos(0));
}
//插入节点到链表
void LinkList::insertLNode(int pos, QString elem)
{
    LNode *pInsertNode=NULL;
    LNode *pLNode=head;
    head->setNodeStatus(LinkList::visitedBrush);
    //找到前驱节点指针
    for(int i=0;i<pos-1;++i)
    {
        sleep(sleepTime);
        pLNode=pLNode->next;
        pLNode->setNodeStatus(LinkList::visitedBrush);
    }
sleep(sleepTime);
    if(pLNode->next==NULL){
        scene->removeItem(pLNode->pointerText);
        pLNode->pointerText=NULL;
    }
    //新节点插入到链表中
    pInsertNode=new LNode(elem,pLNode->next);
    pLNode->next=pInsertNode;
    ++countNode;
    //添加图形Item
    addLNodeGraphicsItem(pInsertNode,getLNodePos(pos));
    for(--pos;pos<=countNode;++pos)
    {
        sleep(sleepTime);
        adjustLNodePos(pLNode,getLNodePos(pos));    //调整节点坐标位置
        adjustLNodeArrow(pLNode,pos);               //调整每个节点箭头
        pLNode=pLNode->next;
    }
}
//删除链表节点
void LinkList::deleteLNode(int pos, QString &elem)
{
    LNode *pDeleteNode=NULL;
    LNode *pLNode=head;
    head->setNodeStatus(LinkList::visitedBrush);
    //找到前驱节点指针
    for(int i=0;i<pos-1;++i)
    {
        sleep(sleepTime);
        pLNode=pLNode->next;
        pLNode->setNodeStatus(LinkList::visitedBrush);
    }
sleep(sleepTime);
    pDeleteNode=pLNode->next;
    pLNode->next=pDeleteNode->next;
    elem=pDeleteNode->data;
    //删除节点，移除图形Item
    pDeleteNode->removeAll(scene);
    delete pDeleteNode;
    --countNode;
    if(pLNode->next==NULL){
        QPoint coord=getLNodePos(pos-1);
        pLNode->pointerText=scene->addText(" ^",LinkList::dataFont);
        pLNode->pointerText->setPos(coord.x()+VALUE_RECT_W, coord.y()+SPACING+5);
    }
    for(--pos;pos<=countNode;++pos)
    {
        sleep(sleepTime);
        adjustLNodePos(pLNode,getLNodePos(pos));    //调整节点坐标位置
        adjustLNodeArrow(pLNode,pos);               //调整节点箭头
        pLNode=pLNode->next;
    }
}
//查找链表节点
bool LinkList::locateLNode(int &pos, QString elem)
{
    LNode *pLNode=head;
    head->setNodeStatus(LinkList::visitedBrush);
    for(pos=1;pLNode&&pLNode->next&&pLNode->next->data!=elem;++pos)
    {
        sleep(sleepTime);
        pLNode=pLNode->next;
        pLNode->setNodeStatus(LinkList::visitedBrush);
    }
sleep(sleepTime);
    //找到相应节点
    if(pLNode&&pLNode->next){
        pLNode->next->setNodeStatus(LinkList::markBrush);
        return true;
    }
    return false;
}
//释放申请的内存空间
void LinkList::destroySelf()
{
    if(scene==NULL)
        return ;
    LNode *pLNode=head, *qLNode;
    for(;pLNode;pLNode=qLNode)
    {
        sleep(sleepTime);
        qLNode=pLNode->next;
        pLNode->removeAll(scene);       //移除每个节点的图形Item
        delete pLNode;      //释放内存
    }
sleep(sleepTime);
    scene->removeItem(headLabel);   //移除链表符号Item
    scene->removeItem(headArrow);   //移除链表符号后的箭头Item
    delete headLabel;       //释放内存
    delete headArrow;       //释放内存
    scene=NULL;
    countNode=0;
}
//槽函数：点击创建
void LinkList::on_pushButtonInit_clicked()
{
    //若已经建立，需要清除重建
    destroySelf();
    initLinkList();
    pushButtonClear->setEnabled(true);
    pushButtonInsert->setEnabled(true);
    pushButtonRandomInsert5->setEnabled(true);
    comboBoxInsert->setEnabled(true);
    lineEditInsert->setEnabled(true);
    pushButtonLocate->setEnabled(true);
    lineEditLocate->setEnabled(true);
    adjustController();
    lineEditState->setPalette(Qt::GlobalColor::green);
    lineEditState->setText("Create Success!");
}
//槽函数：点击清空
void LinkList::on_pushButtonClear_clicked()
{
    destroySelf();
    initUI();
}
//槽函数：点击插入
void LinkList::on_pushButtonInsert_clicked()
{
    setLinkListNormalBrush();
    sleep(sleepTime);
    QString edit=lineEditInsert->text();
    //若输入无效或未输入
    if(edit.isEmpty())
    {
        lineEditState->setPalette(Qt::GlobalColor::red);
        lineEditState->setText("Please Input!");
        return ;
    }
    insertLNode(comboBoxInsert->currentText().toInt(),edit);
    //调整右侧控件状态及值
    adjustController();
    lineEditState->setPalette(Qt::GlobalColor::green);
    lineEditState->setText("Insert Success!");
}
//随机插入五个节点到链表末尾
void LinkList::on_pushButtonRandomInsert5_clicked()
{
    for(int i=0;i<5;++i)
    {
        setLinkListNormalBrush();
        sleep(sleepTime);
        insertLNode(countNode+1,QString::number(rand()%999999999));
        adjustController();
        lineEditState->setPalette(Qt::GlobalColor::green);
        lineEditState->setText("Insert Success!");
    }
}
//槽函数：点击删除
void LinkList::on_pushButtonDelete_clicked()
{
    setLinkListNormalBrush();
    sleep(sleepTime);
    QString deleteData;
    deleteLNode(comboBoxDelete->currentText().toInt(),deleteData);
    //调整右侧控件状态及值
    adjustController();
    lineEditDelete->setText(deleteData);
    lineEditState->setPalette(Qt::GlobalColor::green);
    lineEditState->setText("Delete Success!");
}
//槽函数：点击查找
void LinkList::on_pushButtonLocate_clicked()
{
    setLinkListNormalBrush();
    sleep(sleepTime);
    QString edit=lineEditLocate->text();
    //若输入无效或未输入
    if(edit.isEmpty())
    {
        adjustController();
        lineEditState->setPalette(Qt::GlobalColor::red);
        lineEditState->setText("Please Input!");
        return;
    }
    //根据查找结果给出结果输出
    int pos;
    if(locateLNode(pos,edit))
    {
        comboBoxLocate->addItem(QString::number(pos));
        comboBoxLocate->setCurrentText(QString::number(pos));
        lineEditState->setPalette(Qt::GlobalColor::green);
        lineEditState->setText("Locate Success!");
    }
    else
    {
        adjustController();
        lineEditState->setPalette(Qt::GlobalColor::red);
        lineEditState->setText("Locate Fail!");
    }
}
//调整演示的速度快慢
void LinkList::on_horizontalSlider_valueChanged(int value)
{
    sleepTime=MAX_SLEEP_TIME/(value+1);
}
