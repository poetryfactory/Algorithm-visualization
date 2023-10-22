/********************************************************************************
** Form generated from reading UI file 'sonwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONWINDOW_H
#define UI_SONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sonwindow
{
public:
    QGraphicsView *graphicsview;

    void setupUi(QWidget *sonwindow)
    {
        if (sonwindow->objectName().isEmpty())
            sonwindow->setObjectName("sonwindow");
        sonwindow->resize(800, 570);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sonwindow->sizePolicy().hasHeightForWidth());
        sonwindow->setSizePolicy(sizePolicy);
        sonwindow->setMouseTracking(false);
        graphicsview = new QGraphicsView(sonwindow);
        graphicsview->setObjectName("graphicsview");
        graphicsview->setGeometry(QRect(0, 0, 800, 570));
        sizePolicy.setHeightForWidth(graphicsview->sizePolicy().hasHeightForWidth());
        graphicsview->setSizePolicy(sizePolicy);
        graphicsview->setFrameShape(QFrame::NoFrame);

        retranslateUi(sonwindow);

        QMetaObject::connectSlotsByName(sonwindow);
    } // setupUi

    void retranslateUi(QWidget *sonwindow)
    {
        sonwindow->setWindowTitle(QCoreApplication::translate("sonwindow", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sonwindow: public Ui_sonwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONWINDOW_H
