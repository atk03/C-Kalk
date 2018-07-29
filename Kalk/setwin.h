#ifndef SETWIN_H
#define SETWIN_H

#include <QMainWindow>
#include "insieme.h"
#include <QMessageBox>

namespace Ui {
class setWin;
}

class setWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit setWin(QWidget *parent = 0);
    ~setWin();

private slots:
    void on_unione_clicked();

    void on_intersezione_clicked();

    void on_diff_clicked();

    void on_molt_clicked();

    void on_molt_2_clicked();

    void on_back_clicked();

private:
    Ui::setWin *ui;
    Insieme* i3;
};

#endif // SETWIN_H
