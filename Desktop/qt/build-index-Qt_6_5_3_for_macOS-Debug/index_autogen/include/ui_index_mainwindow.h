/********************************************************************************
** Form generated from reading UI file 'index_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEX_MAINWINDOW_H
#define UI_INDEX_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_index_mainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuAlgorithm_visualization;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *index_mainWindow)
    {
        if (index_mainWindow->objectName().isEmpty())
            index_mainWindow->setObjectName("index_mainWindow");
        index_mainWindow->resize(800, 600);
        centralwidget = new QWidget(index_mainWindow);
        centralwidget->setObjectName("centralwidget");
        index_mainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(index_mainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuAlgorithm_visualization = new QMenu(menubar);
        menuAlgorithm_visualization->setObjectName("menuAlgorithm_visualization");
        index_mainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(index_mainWindow);
        statusbar->setObjectName("statusbar");
        index_mainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAlgorithm_visualization->menuAction());

        retranslateUi(index_mainWindow);

        QMetaObject::connectSlotsByName(index_mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *index_mainWindow)
    {
        index_mainWindow->setWindowTitle(QCoreApplication::translate("index_mainWindow", "index_mainWindow", nullptr));
        menuAlgorithm_visualization->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class index_mainWindow: public Ui_index_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEX_MAINWINDOW_H
