#include "mainwindow.h"
#include <QApplication>
#include "mysql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySql MS;
    MS.initsql();
    MainWindow* w = MainWindow::getIntance();
    w->setWindowTitle("学生信息管理系统");
    w->show();

    return a.exec();
}
