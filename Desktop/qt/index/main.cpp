#include "index_mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    index_mainWindow w;
    w.show();
    return a.exec();
}
