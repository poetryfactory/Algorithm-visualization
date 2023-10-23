#ifndef LISTPAGE_H
#define LISTPAGE_H

#include <QMainWindow>
#include <QWidget>
#include <QIcon>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>
#include <QLineEdit>
#include "linklist.h"
#include "clinklist.h"
#include "dlinklist.h"

class listpage : public QWidget
{
    Q_OBJECT
public:
    //explicit listpage(QWidget *parent = 0);

    listpage(QWidget* parent);

private slots:
               //void on_pushButton1_clicked();
               //void on_pushButton2_clicked();
               //void on_pushButton3_clicked();
private:

    LinkList* linkList;
    CLinkList* clinklist;
    DLinkList* dlinklist;

    void initUI();
};
#endif // MAINWINDOW_H
