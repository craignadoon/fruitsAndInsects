#include <QtGui/QApplication>
#include "include/MainWindow.h"

/* this code runs the basic main window and is created by the Qt Creator app */
int main(int argc, char *argv[])
{
  // make an instance of the QApplication
  QApplication a(argc, argv);
  //create a window for our game;
  MainWindow c;
  //display it
  c.show();
  // hand control over to Qt framework
  return a.exec();
}
