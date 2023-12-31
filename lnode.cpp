#include "lnode.h"

LNode::LNode(QString dt, LNode *nt)
{
    data=dt;
    next=nt;
    pointerRect=valueRect=NULL;
    valueText=pointerText=NULL;
}
LNode::~LNode()
{
}
void LNode::setValueRect(QGraphicsRectItem* vRect)
{
    valueRect=vRect;
}
void LNode::setPointerRect(QGraphicsRectItem* pRect)
{
    pointerRect=pRect;
}
void LNode::setTextRect(QGraphicsTextItem* vText)
{
    valueText=vText;
}
void LNode::setArrowVector(std::vector<MyArrowItem*> aVector)
{
    arrowVector=aVector;
}
void LNode::setNodeStatus(QBrush brush)
{
    valueRect->setBrush(brush);
}
void LNode::removeAll(QGraphicsScene *scene)
{
    if(valueRect)
    {
        scene->removeItem(valueRect);
        delete valueRect;
        valueRect=NULL;
    }
    if(pointerRect)
    {
        scene->removeItem(pointerRect);
        delete pointerRect;
        pointerRect=NULL;
    }
    if(valueText)
    {
        scene->removeItem(valueText);
        delete valueText;
        valueText=NULL;
    }
    if(pointerText)
    {
        scene->removeItem(pointerText);
        delete pointerText;
        pointerText=NULL;
    }
    for(auto &a:arrowVector)
        scene->removeItem(a);
    arrowVector.clear();
}
