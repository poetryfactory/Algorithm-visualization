#include "mybutton.h"

mybutton::mybutton(QString imgsrc)
{
    QPixmap pic1(imgsrc);

    this->setFixedSize(50,50);
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pic1);
    this->setIconSize(QSize(50,50));
}
