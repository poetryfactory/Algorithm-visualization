#ifndef INDEX_MAINWINDOW_H
#define INDEX_MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QRect>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QScrollArea>
#include <QVBoxLayout>
#include "mybutton.h"
#include "detailpage.h"
#include "sonwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class index_mainWindow; }
QT_END_NAMESPACE

class index_mainWindow : public QMainWindow
{
    Q_OBJECT

public:

    index_mainWindow(QWidget *parent = nullptr);

    mybutton * closeBtn;
    mybutton * jumptoBtn;
    mybutton * jumptoBtn2;
    mybutton * jumptoBtn3;
    mybutton * jumptoBtn4;

    ~index_mainWindow();

private:

    Ui::index_mainWindow *ui;

    void paintEvent(QPaintEvent *);

    /* For dragging */
    QPoint m_lastPos;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    int cornerRadius=60;



};
#endif // INDEX_MAINWINDOW_H
