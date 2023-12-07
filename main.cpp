#include "mainwindow.h"
#include "yonghu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    yonghu kk;
    kk.show();

    return a.exec();
}
