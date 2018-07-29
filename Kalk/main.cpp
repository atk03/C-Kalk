#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatrixWin m;
    setWin i;
    MainWindow w(&m,&i);
    w.show();
    return a.exec();
}
