#ifndef MATRIXWIN_H
#define MATRIXWIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "matriceq.h"

namespace Ui {
class MatrixWin;
}

class MatrixWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MatrixWin(QWidget *parent = 0);
    ~MatrixWin();

private slots:
    void on_Trans1_clicked();

    void on_trans2_clicked();

    void on_AC1_clicked();

    void on_AC2_clicked();

    void on_moltS1_clicked();

    void on_moltS2_clicked();

    void on_traccia1_clicked();

    void on_traccia2_clicked();

    void on_simm1_clicked();

    void on_simm2_clicked();

    void on_exp1_clicked();

    void on_exp2_clicked();

    void on_diff_clicked();

    void on_add_clicked();

    void on_moltM_clicked();

    void on_back_2_clicked();

private:
    Ui::MatrixWin *ui;
    MatriceR* m1;
    MatriceR* m2;
    MatriceR* m3;
};

#endif // MATRIXWIN_H
