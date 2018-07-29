#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MatrixWin *m, setWin *i,QWidget *parent) :
    QMainWindow(parent), pm(m), pi(i),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startMatrici_clicked()
{
    pm->show();;
}

void MainWindow::on_startInsimi_clicked()
{
    pi->show();
}
