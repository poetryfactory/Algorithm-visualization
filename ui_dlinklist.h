#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlinklist
{
public:
    QGraphicsView *graphicsView;
    QTextBrowser *textBrowser;
    QPushButton *pushButtonDelete;
    QLabel *labelDeleteValue;
    QLineEdit *lineEditDelete;
    QComboBox *comboBoxDelete;
    QLabel *labelDeletePos;
    QPushButton *pushButtonLocate;
    QLineEdit *lineEditLocate;
    QComboBox *comboBoxLocate;
    QLabel *labelLocateValue;
    QLabel *labelResultPos;
    QLabel *labelTimeControl;
    QPushButton *pushButtonInit;
    QLabel *labelInsertValue;
    QLineEdit *lineEditInsert;
    QPushButton *pushButtonInsert;
    QComboBox *comboBoxInsert;
    QLabel *labelInsert;
    QLabel *labelState;
    QLineEdit *lineEditState;
    QSlider *horizontalSlider;
    QPushButton *pushButtonRandomInsert5;
    QPushButton *pushButtonClear;

    void setupUi(QWidget *dlinklist)
    {
        if (dlinklist->objectName().isEmpty())
            dlinklist->setObjectName("dlinklist");
        dlinklist->resize(816, 619);
        graphicsView = new QGraphicsView(dlinklist);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 180, 570, 410));
        textBrowser = new QTextBrowser(dlinklist);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 10, 570, 160));
        pushButtonDelete = new QPushButton(dlinklist);
        pushButtonDelete->setObjectName("pushButtonDelete");
        pushButtonDelete->setGeometry(QRect(600, 240, 75, 40));
        pushButtonDelete->setMinimumSize(QSize(0, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(10);
        pushButtonDelete->setFont(font);
        labelDeleteValue = new QLabel(dlinklist);
        labelDeleteValue->setObjectName("labelDeleteValue");
        labelDeleteValue->setGeometry(QRect(600, 310, 66, 30));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelDeleteValue->sizePolicy().hasHeightForWidth());
        labelDeleteValue->setSizePolicy(sizePolicy);
        labelDeleteValue->setMinimumSize(QSize(60, 30));
        lineEditDelete = new QLineEdit(dlinklist);
        lineEditDelete->setObjectName("lineEditDelete");
        lineEditDelete->setGeometry(QRect(675, 310, 75, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditDelete->sizePolicy().hasHeightForWidth());
        lineEditDelete->setSizePolicy(sizePolicy1);
        lineEditDelete->setMinimumSize(QSize(60, 30));
        comboBoxDelete = new QComboBox(dlinklist);
        comboBoxDelete->setObjectName("comboBoxDelete");
        comboBoxDelete->setEnabled(true);
        comboBoxDelete->setGeometry(QRect(675, 285, 40, 20));
        labelDeletePos = new QLabel(dlinklist);
        labelDeletePos->setObjectName("labelDeletePos");
        labelDeletePos->setGeometry(QRect(600, 280, 75, 30));
        sizePolicy.setHeightForWidth(labelDeletePos->sizePolicy().hasHeightForWidth());
        labelDeletePos->setSizePolicy(sizePolicy);
        labelDeletePos->setMinimumSize(QSize(60, 30));
        pushButtonLocate = new QPushButton(dlinklist);
        pushButtonLocate->setObjectName("pushButtonLocate");
        pushButtonLocate->setGeometry(QRect(600, 380, 75, 40));
        pushButtonLocate->setMinimumSize(QSize(0, 20));
        pushButtonLocate->setFont(font);
        lineEditLocate = new QLineEdit(dlinklist);
        lineEditLocate->setObjectName("lineEditLocate");
        lineEditLocate->setGeometry(QRect(675, 450, 75, 30));
        sizePolicy1.setHeightForWidth(lineEditLocate->sizePolicy().hasHeightForWidth());
        lineEditLocate->setSizePolicy(sizePolicy1);
        lineEditLocate->setMinimumSize(QSize(60, 30));
        comboBoxLocate = new QComboBox(dlinklist);
        comboBoxLocate->setObjectName("comboBoxLocate");
        comboBoxLocate->setEnabled(true);
        comboBoxLocate->setGeometry(QRect(675, 425, 40, 20));
        labelLocateValue = new QLabel(dlinklist);
        labelLocateValue->setObjectName("labelLocateValue");
        labelLocateValue->setGeometry(QRect(600, 450, 66, 30));
        sizePolicy.setHeightForWidth(labelLocateValue->sizePolicy().hasHeightForWidth());
        labelLocateValue->setSizePolicy(sizePolicy);
        labelLocateValue->setMinimumSize(QSize(60, 30));
        labelResultPos = new QLabel(dlinklist);
        labelResultPos->setObjectName("labelResultPos");
        labelResultPos->setGeometry(QRect(600, 420, 75, 30));
        sizePolicy.setHeightForWidth(labelResultPos->sizePolicy().hasHeightForWidth());
        labelResultPos->setSizePolicy(sizePolicy);
        labelResultPos->setMinimumSize(QSize(60, 30));
        labelTimeControl = new QLabel(dlinklist);
        labelTimeControl->setObjectName("labelTimeControl");
        labelTimeControl->setGeometry(QRect(600, 550, 75, 30));
        sizePolicy.setHeightForWidth(labelTimeControl->sizePolicy().hasHeightForWidth());
        labelTimeControl->setSizePolicy(sizePolicy);
        labelTimeControl->setMinimumSize(QSize(60, 30));
        pushButtonInit = new QPushButton(dlinklist);
        pushButtonInit->setObjectName("pushButtonInit");
        pushButtonInit->setGeometry(QRect(600, 20, 75, 40));
        pushButtonInit->setMinimumSize(QSize(0, 20));
        pushButtonInit->setFont(font);
        labelInsertValue = new QLabel(dlinklist);
        labelInsertValue->setObjectName("labelInsertValue");
        labelInsertValue->setGeometry(QRect(600, 170, 66, 30));
        sizePolicy.setHeightForWidth(labelInsertValue->sizePolicy().hasHeightForWidth());
        labelInsertValue->setSizePolicy(sizePolicy);
        labelInsertValue->setMinimumSize(QSize(60, 30));
        lineEditInsert = new QLineEdit(dlinklist);
        lineEditInsert->setObjectName("lineEditInsert");
        lineEditInsert->setGeometry(QRect(675, 170, 75, 30));
        sizePolicy1.setHeightForWidth(lineEditInsert->sizePolicy().hasHeightForWidth());
        lineEditInsert->setSizePolicy(sizePolicy1);
        lineEditInsert->setMinimumSize(QSize(60, 30));
        pushButtonInsert = new QPushButton(dlinklist);
        pushButtonInsert->setObjectName("pushButtonInsert");
        pushButtonInsert->setGeometry(QRect(600, 100, 75, 40));
        pushButtonInsert->setMinimumSize(QSize(0, 20));
        pushButtonInsert->setFont(font);
        comboBoxInsert = new QComboBox(dlinklist);
        comboBoxInsert->setObjectName("comboBoxInsert");
        comboBoxInsert->setEnabled(true);
        comboBoxInsert->setGeometry(QRect(675, 145, 40, 20));
        labelInsert = new QLabel(dlinklist);
        labelInsert->setObjectName("labelInsert");
        labelInsert->setGeometry(QRect(600, 140, 75, 30));
        sizePolicy.setHeightForWidth(labelInsert->sizePolicy().hasHeightForWidth());
        labelInsert->setSizePolicy(sizePolicy);
        labelInsert->setMinimumSize(QSize(60, 30));
        labelState = new QLabel(dlinklist);
        labelState->setObjectName("labelState");
        labelState->setGeometry(QRect(600, 520, 60, 30));
        sizePolicy.setHeightForWidth(labelState->sizePolicy().hasHeightForWidth());
        labelState->setSizePolicy(sizePolicy);
        labelState->setMinimumSize(QSize(60, 30));
        lineEditState = new QLineEdit(dlinklist);
        lineEditState->setObjectName("lineEditState");
        lineEditState->setGeometry(QRect(675, 520, 100, 30));
        sizePolicy1.setHeightForWidth(lineEditState->sizePolicy().hasHeightForWidth());
        lineEditState->setSizePolicy(sizePolicy1);
        lineEditState->setMinimumSize(QSize(60, 30));
        horizontalSlider = new QSlider(dlinklist);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(675, 555, 100, 20));
        horizontalSlider->setMouseTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButtonRandomInsert5 = new QPushButton(dlinklist);
        pushButtonRandomInsert5->setObjectName("pushButtonRandomInsert5");
        pushButtonRandomInsert5->setGeometry(QRect(680, 110, 70, 30));
        pushButtonRandomInsert5->setMinimumSize(QSize(0, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(8);
        pushButtonRandomInsert5->setFont(font1);
        pushButtonClear = new QPushButton(dlinklist);
        pushButtonClear->setObjectName("pushButtonClear");
        pushButtonClear->setGeometry(QRect(680, 20, 75, 40));
        pushButtonClear->setMinimumSize(QSize(0, 20));
        pushButtonClear->setFont(font);

        retranslateUi(dlinklist);

        QMetaObject::connectSlotsByName(dlinklist);
    } // setupUi

    void retranslateUi(QWidget *dlinklist)
    {
        dlinklist->setWindowTitle(QCoreApplication::translate("dlinklist", "Form", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("dlinklist", "\345\210\240\351\231\244", nullptr));
        labelDeleteValue->setText(QCoreApplication::translate("dlinklist", "\345\200\274\357\274\210int\357\274\211\357\274\232", nullptr));
        labelDeletePos->setText(QCoreApplication::translate("dlinklist", "\345\210\240\351\231\244\344\275\215\347\275\256 \357\274\232", nullptr));
        pushButtonLocate->setText(QCoreApplication::translate("dlinklist", "\346\237\245\346\211\276", nullptr));
        labelLocateValue->setText(QCoreApplication::translate("dlinklist", "\345\200\274\357\274\210int\357\274\211\357\274\232", nullptr));
        labelResultPos->setText(QCoreApplication::translate("dlinklist", "\347\273\223\346\236\234\344\275\215\347\275\256 \357\274\232", nullptr));
        labelTimeControl->setText(QCoreApplication::translate("dlinklist", "\351\200\237\345\272\246\350\260\203\350\212\202 \357\274\232", nullptr));
        pushButtonInit->setText(QCoreApplication::translate("dlinklist", "\345\210\233\345\273\272", nullptr));
        labelInsertValue->setText(QCoreApplication::translate("dlinklist", "\345\200\274\357\274\210int\357\274\211\357\274\232", nullptr));
        pushButtonInsert->setText(QCoreApplication::translate("dlinklist", "\346\217\222\345\205\245", nullptr));
        labelInsert->setText(QCoreApplication::translate("dlinklist", "\346\217\222\345\205\245\344\275\215\347\275\256 \357\274\232", nullptr));
        labelState->setText(QCoreApplication::translate("dlinklist", "\347\212\266\346\200\201\346\217\220\347\244\272 \357\274\232", nullptr));
        pushButtonRandomInsert5->setText(QCoreApplication::translate("dlinklist", "\345\260\276\347\253\257\351\232\217\346\234\2725\344\270\252", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("dlinklist", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
class DLinkList: public Ui_dlinklist {};
} // namespace Ui

QT_END_NAMESPACE

