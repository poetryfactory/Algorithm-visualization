#include "index_mainwindow.h"

#include <QApplication>
//#include <windows.h>
int main(int argc, char *argv[]) {
  // AllocConsole(); //打开控制台
  // freopen("CON", "w", stdout);
  QApplication a(argc, argv);
  index_mainWindow w;
  w.show();
  return a.exec();
}
