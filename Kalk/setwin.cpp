#include "setwin.h"
#include "ui_setwin.h"

setWin::setWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setWin)
{
    ui->setupUi(this);
    i3=0;
    ui->spinBox_3->hide();
    ui->spinBox_4->hide();
}

setWin::~setWin()
{
    delete ui;
}

void setWin::on_unione_clicked()
{
    QString qs=ui->plainTextEdit->toPlainText();
    QString qs2=ui->plainTextEdit_2->toPlainText();
    if(Insieme::checkparserI(qs) && Insieme::checkparserI(qs2)){
        Insieme i1(qs);
        ui->plainTextEdit->setPlainText(QString::fromStdString(i1.toString()));
        Insieme i2(qs2);
        ui->plainTextEdit_2->setPlainText(QString::fromStdString(i2.toString()));
        if(i3 !=0){
            delete i3;
            i3=0;
        }
        i3=i1.unione(i2);
        ui->plainTextEdit_3->setPlainText(QString::fromStdString(i3->toString()));
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Verificare la sintassi degli insiemi e la presenza di elementi ripetuti"));
        mB.exec();
    }
}

void setWin::on_intersezione_clicked()
{
    QString qs=ui->plainTextEdit->toPlainText();
    QString qs2=ui->plainTextEdit_2->toPlainText();
    if(Insieme::checkparserI(qs) && Insieme::checkparserI(qs2)){
        Insieme i1(qs);
        ui->plainTextEdit->setPlainText(QString::fromStdString(i1.toString()));
        Insieme i2(qs2);
        ui->plainTextEdit_2->setPlainText(QString::fromStdString(i2.toString()));
        if(i3 !=0){
            delete i3;
            i3=0;
        }
        i3=i1.intersezione(i2);
        ui->plainTextEdit_3->setPlainText(QString::fromStdString(i3->toString()));
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Verificare la sintassi degli insiemi e la presenza di elementi ripetuti"));
        mB.exec();
    }
}

void setWin::on_diff_clicked()
{
    QString qs=ui->plainTextEdit->toPlainText();
    QString qs2=ui->plainTextEdit_2->toPlainText();
    if(Insieme::checkparserI(qs) && Insieme::checkparserI(qs2)){
        Insieme i1(qs);
        ui->plainTextEdit->setPlainText(QString::fromStdString(i1.toString()));
        Insieme i2(qs2);
        ui->plainTextEdit_2->setPlainText(QString::fromStdString(i2.toString()));
        if(i3 !=0){
            delete i3;
            i3=0;
        }
        i3=i1-(i2);
        ui->plainTextEdit_3->setPlainText(QString::fromStdString(i3->toString()));
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Verificare la sintassi degli insiemi e la presenza di elementi ripetuti"));
        mB.exec();
    }
}

//min e max
void setWin::on_molt_clicked()
{
    QString qs=ui->plainTextEdit->toPlainText();
    if(Insieme::checkparserI(qs)){
        Insieme i1(qs);
        try {
            int min=i1.getMin();
            int max=i1.getMax();
            QString qsmb= QString("Il valore minimo e': ")+QString::number(min)+ QString(" il valore massimo e': ")+QString::number(max);
            QMessageBox mB;
            mB.setWindowTitle("Min-Max");
            mB.setText(QString(qsmb));
            mB.exec();
        } catch (erroriOp e) {
            QMessageBox mB;
            mB.setWindowTitle("Si e' verificato un errore");
            mB.setText(QString("L' insieme è vuoto"));
            mB.exec();
        }
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Verificare la sintassi degli insiemi e la presenza di elementi ripetuti"));
        mB.exec();
    }
}
//min e max
void setWin::on_molt_2_clicked()
{
    QString qs=ui->plainTextEdit_2->toPlainText();
    if(Insieme::checkparserI(qs)){
        Insieme i2(qs);
        try {
            int min=i2.getMin();
            int max=i2.getMax();
            QString qsmb= QString("Il valore minimo e': ")+QString::number(min)+ QString(" il valore massimo e': ")+QString::number(max);
            QMessageBox mB;
            mB.setWindowTitle("Min-Max");
            mB.setText(QString(qsmb));
            mB.exec();
        } catch (erroriOp e) {
            QMessageBox mB;
            mB.setWindowTitle("Si e' verificato un errore");
            mB.setText(QString("L' insieme è vuoto"));
            mB.exec();
        }
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Verificare la sintassi degli insiemi e la presenza di elementi ripetuti"));
        mB.exec();
    }
}

void setWin::on_back_clicked()
{
    hide();
    ui->plainTextEdit->setPlainText(QString(""));
    ui->plainTextEdit_2->setPlainText(QString(""));
    ui->plainTextEdit_3->setPlainText(QString(""));
}
