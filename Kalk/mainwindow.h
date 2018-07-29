#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"matrixwin.h"
#include"setwin.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(MatrixWin *, setWin* , QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startMatrici_clicked();

    void on_startInsimi_clicked();

private:
    MatrixWin* pm;
    setWin* pi;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
