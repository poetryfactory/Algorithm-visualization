/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QLabel *label;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(798, 661);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setGeometry(QRect(180, 110, 320, 380));
        pushButton1 = new QPushButton(centralWidget);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(120, 60, 180, 60));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton1->sizePolicy().hasHeightForWidth());
        pushButton1->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(12);
        font.setBold(false);
        pushButton1->setFont(font);
        pushButton1->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #D4DCDF;\n"
"     border-radius: 5%;\n"
"}\n"
"QPushButton:pressed {\n"
"     background-color: #D4DCDF;\n"
"     border-radius: 5%;\n"
"	color: white;\n"
"	border: 5px solid white;\n"
"}"));
        pushButton2 = new QPushButton(centralWidget);
        pushButton2->setObjectName("pushButton2");
        pushButton2->setGeometry(QRect(120, 180, 180, 60));
        sizePolicy.setHeightForWidth(pushButton2->sizePolicy().hasHeightForWidth());
        pushButton2->setSizePolicy(sizePolicy);
        pushButton2->setFont(font);
        pushButton2->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #D4DCDF;\n"
"     border-radius: 5%;\n"
"}\n"
"QPushButton:pressed {\n"
"     background-color: #D4DCDF;\n"
"     border-radius: 5%;\n"
"	color: white;\n"
"	border: 5px solid white;\n"
"}"));
        pushButton3 = new QPushButton(centralWidget);
        pushButton3->setObjectName("pushButton3");
        pushButton3->setGeometry(QRect(120, 300, 180, 60));
        sizePolicy.setHeightForWidth(pushButton3->sizePolicy().hasHeightForWidth());
        pushButton3->setSizePolicy(sizePolicy);
        pushButton3->setFont(font);
        pushButton3->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #D4DCDF;\n"
"     border-radius: 5%;\n"
"}\n"
"QPushButton:pressed {\n"
"     background-color: #D4DCDF;\n"
"     border-radius: 5%;\n"
"	color: white;\n"
"	border: 5px solid white;\n"
"}"));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 100, 40));
        label->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(49, 49, 49);"));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "\345\215\225\351\223\276\350\241\250(LinkList)", nullptr));
        pushButton2->setText(QCoreApplication::translate("MainWindow", "\345\276\252\347\216\257\351\223\276\350\241\250(CLinkList)", nullptr));
        pushButton3->setText(QCoreApplication::translate("MainWindow", "\345\217\214\345\220\221\351\223\276\350\241\250(DLinkList)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
