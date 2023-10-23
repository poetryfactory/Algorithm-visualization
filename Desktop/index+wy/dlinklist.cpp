#include<QDebug>
#include <math.h>
#include "dlinklist.h"
//#include "ui_dlinklist.h"
#include "myarrowitem.h"
void sleep(unsigned int msec);
const QBrush DLinkList::normalBursh=QBrush(Qt::GlobalColor::darkGray);
const QBrush DLinkList::visitedBrush=QBrush(Qt::GlobalColor::yellow);
const QBrush DLinkList::markBrush=QBrush(Qt::GlobalColor::green);
const QFont DLinkList::headLabelFont=QFont("Consolas");
const QFont DLinkList::dataFont=QFont("Consolas",8);
const QIntValidator DLinkList::dataValidator(-999999999,999999999);
//构造函数
DLinkList::DLinkList(QWidget *parent) :
    QWidget(parent)//,
    //ui(new Ui::DLinkList)
{
    //初始化数据
    //setupUi(this);
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
    this->setWindowTitle("双向循环链表");
}
//析构函数
DLinkList::~DLinkList()
{
    destroySelf();
    //delete ui;
}
//初始设置文本显示区
void DLinkList::initTextBrowser(){
    //加载html文件
    QFile file(":/html/html/DLinkList.html");
    file.open(QIODevice::ReadOnly);
    QString htmlString=file.readAll();
    textBrowser->setHtml(htmlString);
    textBrowser->setOpenLinks(true);
    textBrowser->setOpenExternalLinks(true);
    file.close();
}
//初始UI控件
void DLinkList::initUI()
{
    //set background image
    QPixmap background(":/ico/resource/background.png");
    QPalette palette;
    palette.setBrush(QPalette::Window,background);
    this->setPalette(palette);
    //未创建时，除创建按钮外，其余按键一律无效
    pushButtonClear->setEnabled(false);
    pushButtonInsert->setEnabled(false);
    pushButtonRandomInsert5->setEnabled(false);
    comboBoxInsert->setEnabled(false);
    lineEditInsert->setEnabled(false);
    pushButtonDelete->setEnabled(false);
    comboBoxDelete->setEnabled(false);
    lineEditDelete->setEnabled(false);
    pushButtonLocate->setEnabled(false);
    comboBoxLocate->setEnabled(false);
    lineEditLocate->setEnabled(false);
    lineEditState->setEnabled(false);
    lineEditInsert->setFont(dataFont);
    lineEditDelete->setFont(dataFont);
    lineEditLocate->setFont(dataFont);
    lineEditState->setFont(dataFont);
    lineEditInsert->setPlaceholderText("插入值：Int");
    lineEditLocate->setPlaceholderText("查找值：Int");
    lineEditInsert->setValidator(&DLinkList::dataValidator);
    lineEditLocate->setValidator(&DLinkList::dataValidator);
    lineEditState->setText("请选择操作");
    horizontalSlider->setMinimum(0);
    horizontalSlider->setMaximum(MAX_SLIDER);
    horizontalSlider->setTickPosition(QSlider::TicksBelow);
}
//初始化视图框架
void DLinkList::initSceneView()
{
    //为 view 配置相应 scene
    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,SCENE_MAX_W,SCENE_MAX_H);
    graphicsView->setScene(scene);
    //添加链表符号及指针箭头
    headLabel=scene->addText("DL",headLabelFont);
    headLabel->setPos(DVALUE_RECT_W/2+DPOINTER_RECT_W,DSPACING-5);

    headArrow=new MyArrowItem(DARROW_LEN);
    scene->addItem(headArrow);
    headArrow->setPos(DLEFT_SPACING+DARROW_H_OFFSET1,DARROW_V_OFFSET1);
}
//操作之后调整右侧输入和显示控件
void DLinkList::adjustController()
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
QPoint DLinkList::getDLNodePos(int nodeNumber)
{
    const static int rowN=(SCENE_MAX_W-DLEFT_SPACING-DRIGHT_SPAXING)/DNODE_W;
    return QPoint((nodeNumber+1)%rowN*DNODE_W+DLEFT_SPACING,(nodeNumber+1)/rowN*DNODE_H);
}
//添加节点的GraphicsItem
void DLinkList::addDLNodeGraphicsItem(DLNode *pDLNode, QPoint coord)
{
    int x=coord.x()+DPOINTER_RECT_W, y=coord.y();
    pDLNode->valueRect   =scene->addRect(x,y+DSPACING,DVALUE_RECT_W,DRECT_H,QPen(),DLinkList::markBrush);
    pDLNode->pointerRect =scene->addRect(x+DVALUE_RECT_W,y+DSPACING,DPOINTER_RECT_W,DRECT_H);
    pDLNode->valueText   =scene->addText(pDLNode->data,DLinkList::dataFont);
    pDLNode->valueText->setPos(x,y+DSPACING+5);
    pDLNode->prePointerRect=scene->addRect(coord.x(),y+DSPACING,DPOINTER_RECT_W,DRECT_H);
//    if(pDLNode->next==NULL)
//    {
//        pDLNode->pointerText=scene->addText(" ^",DLinkList::dataFont);
//        pDLNode->pointerText->setPos(x+VALUE_RECT_W, y+SPACING+5);
//    }
}
//调整节点的箭头
void DLinkList::adjustDLNodeArrow(DLNode *pDLNode, int nodeNumber)
{
    //调整后继指针箭头
    for(auto &a:pDLNode->arrowVector)
        scene->removeItem(a);
    QPoint myCoord=getDLNodePos(nodeNumber);
    QPoint nextCoord=getDLNodePos(nodeNumber+1);
    MyArrowItem *pArrow;
    //若是指向头结点
    if(pDLNode->next==head)
    {
        QPoint point1(myCoord.x()+DARROW_H_OFFSET1,myCoord.y()+DARROW_V_OFFSET1);
        QPoint point2(SCENE_MAX_W-DRIGHT_SPAXING+10, point1.y());
        QPoint point3(point2.x(), 1);
        QPoint point4(DLEFT_SPACING+DNODE_W+DPOINTER_RECT_W+(DVALUE_RECT_W>>1), point3.y());
        pArrow=new MyArrowItem(point2.x()-point1.x(),1,0);
        scene->addItem(pArrow);
        pArrow->setPos(point1);
        pDLNode->arrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(point2.y()-point3.y(),0,0);
        scene->addItem(pArrow);
        pArrow->setPos(point2);
        pDLNode->arrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(point3.x()-point4.x(),3,0);
        scene->addItem(pArrow);
        pArrow->setPos(point3);
        pDLNode->arrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(DSPACING-point4.y(),2,1);
        scene->addItem(pArrow);
        pArrow->setPos(point4);
        pDLNode->arrowVector.push_back(pArrow);
    }
    else if(myCoord.y()==nextCoord.y())
    {
        //节点不是一行最后节点
        pArrow=new MyArrowItem(DARROW_LEN);
        scene->addItem(pArrow);
        pArrow->setPos(myCoord.x()+DARROW_H_OFFSET1,myCoord.y()+DARROW_V_OFFSET1);
        pDLNode->arrowVector.push_back(pArrow);
    }
    else
    {
        //节点是一行中最后节点
        QPoint point1(myCoord.x()+DARROW_H_OFFSET1,myCoord.y()+DARROW_V_OFFSET1);
        QPoint point2(point1.x(),myCoord.y()+DNODE_H+5);
        QPoint point3(DLEFT_SPACING+DPOINTER_RECT_W+DVALUE_RECT_W/2,point2.y());
        pArrow=new MyArrowItem(point2.y()-point1.y(),2,0);
        scene->addItem(pArrow);
        pArrow->setPos(point1);
        pDLNode->arrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(point2.x()-point3.x(),3,0);
        scene->addItem(pArrow);
        pArrow->setPos(point2);
        pDLNode->arrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(DSPACING-5,2);
        scene->addItem(pArrow);
        pArrow->setPos(point3);
        pDLNode->arrowVector.push_back(pArrow);
    }
    //调整前驱指针箭头
    for(auto &a:pDLNode->preArrowVector)
        scene->removeItem(a);
    QPoint preCoord=getDLNodePos(nodeNumber-1);
    QPoint lastCoord=getDLNodePos(countNode);
    if(pDLNode->prior==head)
    {
        QPoint point1(myCoord.x()+DARROW_H_OFFSET2,myCoord.y()+DARROW_V_OFFSET2);
        QPoint point2(DLEFT_SPACING-10,point1.y());
        QPoint point3(point2.x(),lastCoord.y()+DNODE_H-5);
        QPoint point4(lastCoord.x()+(DPOINTER_RECT_W+DVALUE_RECT_W/2),point3.y());
        pArrow=new MyArrowItem(point1.x()-point2.x(),3,0);
        scene->addItem(pArrow);
        pArrow->setPos(point1);
        pDLNode->preArrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(point3.y()-point2.y(),2,0);
        scene->addItem(pArrow);
        pArrow->setPos(point2);
        pDLNode->preArrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(point4.x()-point3.x(),1,0);
        scene->addItem(pArrow);
        pArrow->setPos(point3);
        pDLNode->preArrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(DSPACING-5,0,1);
        scene->addItem(pArrow);
        pArrow->setPos(point4);
        pDLNode->preArrowVector.push_back(pArrow);
    }
    else if(myCoord.y()==preCoord.y())
    {
        //节点不是一行第一节点
        pArrow=new MyArrowItem(DARROW_LEN,3);
        scene->addItem(pArrow);
        pArrow->setPos(myCoord.x()+DARROW_H_OFFSET2,myCoord.y()+DARROW_V_OFFSET2);
        pDLNode->preArrowVector.push_back(pArrow);
    }
    else
    {
        //节点是一行中第一节点
        QPoint point1(myCoord.x()+DARROW_H_OFFSET2,myCoord.y()+DARROW_V_OFFSET2);
        QPoint point2(point1.x(),myCoord.y()-5);
        QPoint point3(preCoord.x()+(DPOINTER_RECT_W+DVALUE_RECT_W/2),point2.y());
        pArrow=new MyArrowItem(point1.y()-point2.y(),0,0);
        scene->addItem(pArrow);
        pArrow->setPos(point1);
        pDLNode->preArrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(point3.x()-point2.x(),1,0);
        scene->addItem(pArrow);
        pArrow->setPos(point2);
        pDLNode->preArrowVector.push_back(pArrow);
        pArrow=new MyArrowItem(DSPACING-5,0);
        scene->addItem(pArrow);
        pArrow->setPos(point3);
        pDLNode->preArrowVector.push_back(pArrow);
    }
}
//调整节点Scene坐标
void DLinkList::adjustDLNodePos(DLNode *pDLNode, QPoint coord)
{
    int x=coord.x()+DPOINTER_RECT_W, y=coord.y();
    pDLNode->prePointerRect->setRect(coord.x(),y+DSPACING,DPOINTER_RECT_W,DRECT_H);
    pDLNode->valueRect->setRect(x,y+DSPACING,DVALUE_RECT_W,DRECT_H);
    pDLNode->pointerRect->setRect(x+DVALUE_RECT_W,y+DSPACING,DPOINTER_RECT_W,DRECT_H);
    pDLNode->valueText->setPos(x,y+DSPACING+5);
//    if(pDLNode->pointerText)
//        pDLNode->pointerText->setPos(x+VALUE_RECT_W, y+SPACING+5);
}
//设置链表所有节点显示模式
void DLinkList::setDLinkListNormalBrush()
{
    head->setNodeStatus(DLinkList::normalBursh);
    for(DLNode *pDLNode=head->next;pDLNode!=head;pDLNode=pDLNode->next)
        pDLNode->setNodeStatus(DLinkList::normalBursh);
}
//创建链表初始化
void DLinkList::initDLinkList()
{
    initSceneView();
    head=new DLNode("头结点", NULL);
    head->next=head;
    head->prior=head;

    addDLNodeGraphicsItem(head, getDLNodePos(0));
    adjustDLNodeArrow(head,0);
}
//插入节点到链表
void DLinkList::insertDLNode(int pos, QString elem)
{
    DLNode *pInsertNode=NULL;
    DLNode *pDLNode=head;
    head->setNodeStatus(DLinkList::visitedBrush);

    //找到前驱节点指针
    for(int i=0;i<pos-1;++i)
    {
        pDLNode=pDLNode->next;
        pDLNode->setNodeStatus(DLinkList::visitedBrush);

    }
    if(pDLNode->next==NULL){
        scene->removeItem(pDLNode->pointerText);
        pDLNode->pointerText=NULL;
    }
    //新节点插入到链表中
    pInsertNode=new DLNode(elem,pDLNode->next);
    pDLNode->next=pInsertNode;
    ++countNode;
    //添加图形Item
    addDLNodeGraphicsItem(pInsertNode,getDLNodePos(pos));
    for(--pos;pos<=countNode;++pos)
    {

        adjustDLNodePos(pDLNode,getDLNodePos(pos));   //调整节点坐标位置
        adjustDLNodeArrow(pDLNode,pos);               //调整每个节点箭头
        pDLNode=pDLNode->next;
    }
    adjustDLNodeArrow(head,0);                       //调整头节点箭头
}
//删除链表节点
void DLinkList::deleteDLNode(int pos, QString &elem)
{
    DLNode *pDeleteNode=NULL;
    DLNode *pDLNode=head;
    head->setNodeStatus(DLinkList::visitedBrush);
    //找到前驱节点指针
    for(int i=0;i<pos-1;++i)
    {

        pDLNode=pDLNode->next;
        pDLNode->setNodeStatus(DLinkList::visitedBrush);
    }

    pDeleteNode=pDLNode->next;
    pDLNode->next=pDeleteNode->next;
    elem=pDeleteNode->data;
    //删除节点，移除图形Item
    pDeleteNode->removeAll(scene);
    delete pDeleteNode;
    --countNode;
    if(pDLNode->next==NULL){
        QPoint coord=getDLNodePos(pos-1);
        pDLNode->pointerText=scene->addText(" ^",DLinkList::dataFont);
        pDLNode->pointerText->setPos(coord.x()+VALUE_RECT_W, coord.y()+SPACING+5);
    }
    for(--pos;pos<=countNode;++pos)
    {

        adjustDLNodePos(pDLNode,getDLNodePos(pos));    //调整节点坐标位置
        adjustDLNodeArrow(pDLNode,pos);               //调整节点箭头
        pDLNode=pDLNode->next;
    }
    adjustDLNodeArrow(head,0);                       //调整头节点箭头
}
//查找链表节点
bool DLinkList::locateDLNode(int &pos, QString elem)
{
    DLNode *pDLNode=head;
    head->setNodeStatus(DLinkList::visitedBrush);

    for(pos=1;pDLNode->next!=head&&pDLNode->next->data!=elem;++pos)
    {

        pDLNode=pDLNode->next;
        pDLNode->setNodeStatus(DLinkList::visitedBrush);
    }
    //找到相应节点
    if(pDLNode->next!=head){
        pDLNode->next->setNodeStatus(DLinkList::markBrush);
        return true;
    }
    return false;
}
//释放申请的内存空间
void DLinkList::destroySelf()
{
    if(scene==NULL)
        return ;
    DLNode *pDLNode=head->next, *qDLNode;
    for(;pDLNode!=head;pDLNode=qDLNode)
    {

        qDLNode=pDLNode->next;
        pDLNode->removeAll(scene);       //移除每个节点的图形Item
        delete pDLNode;      //释放内存
    }

    ////////////
    head->removeAll(scene);     //移除头结点图形Item
    delete head;                //释放内存
    ///////////////
    scene->removeItem(headLabel);   //移除链表符号Item
    scene->removeItem(headArrow);   //移除链表符号后的箭头Item
    delete headLabel;       //释放内存
    delete headArrow;       //释放内存
    scene=NULL;
    countNode=0;
}
//槽函数：点击创建
void DLinkList::on_pushButtonInit_clicked()
{
    //若已经建立，需要清除重建
    destroySelf();
    initDLinkList();
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
void DLinkList::on_pushButtonClear_clicked()
{
    destroySelf();
    initUI();
}
//槽函数：点击插入
void DLinkList::on_pushButtonInsert_clicked()
{
    setDLinkListNormalBrush();
    QString edit=lineEditInsert->text();
    //若输入无效或未输入
    if(edit.isEmpty())
    {
        lineEditState->setPalette(Qt::GlobalColor::red);
        lineEditState->setText("Please Input!");
        return ;
    }

    insertDLNode(comboBoxInsert->currentText().toInt(),edit);
    //调整右侧控件状态及值
    adjustController();
    lineEditState->setPalette(Qt::GlobalColor::green);
    lineEditState->setText("Insert Success!");
}
//随机插入五个节点到链表末尾
void DLinkList::on_pushButtonRandomInsert5_clicked()
{
    for(int i=0;i<5;++i)
    {
        setDLinkListNormalBrush();

        insertDLNode(countNode+1,QString::number(rand()%999999999));
        adjustController();
        lineEditState->setPalette(Qt::GlobalColor::green);
        lineEditState->setText("Insert Success!");
    }
}
//槽函数：点击删除
void DLinkList::on_pushButtonDelete_clicked()
{
    setDLinkListNormalBrush();

    QString deleteData;
    deleteDLNode(comboBoxDelete->currentText().toInt(),deleteData);
    //调整右侧控件状态及值
    adjustController();
    lineEditDelete->setText(deleteData);
    lineEditState->setPalette(Qt::GlobalColor::green);
    lineEditState->setText("Delete Success!");
}
//槽函数：点击查找
void DLinkList::on_pushButtonLocate_clicked()
{
    setDLinkListNormalBrush();

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
    if(locateDLNode(pos,edit))
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
void DLinkList::on_horizontalSlider_valueChanged(int value)
{
    sleepTime=MAX_SLEEP_TIME/(value+1);
}
