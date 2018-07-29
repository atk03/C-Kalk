#include "matrixwin.h"
#include "ui_matrixwin.h"

MatrixWin::MatrixWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MatrixWin)
{
    ui->setupUi(this);
    m1=0;
    m2=0;
    m3=0;
}

MatrixWin::~MatrixWin()
{
    delete ui;
}

void MatrixWin::on_Trans1_clicked()
{
    QString qs=ui->plainTextEdit->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        MatriceR* mtemp=new MatriceQ(qs);
        m1=mtemp->trasposta();
        delete mtemp;
        ui->plainTextEdit->setPlainText(QString::fromStdString(m1->toString()));
    }else if(MatriceR::checkparserR(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        MatriceR* mtemp=new MatriceR(qs);
        m1=mtemp->trasposta();
        delete mtemp;
        ui->plainTextEdit->setPlainText(QString::fromStdString(m1->toString()));
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Sintassi matrice errata"));
        mB.exec();
    }
}

void MatrixWin::on_trans2_clicked()
{
    QString qs=ui->plainTextEdit_2->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        MatriceR* mtemp=new MatriceQ(qs);
        m2=mtemp->trasposta();
        delete mtemp;
        ui->plainTextEdit_2->setPlainText(QString::fromStdString(m2->toString()));
    }else if(MatriceR::checkparserR(qs)){
        if(m2!=0){
            delete m2;
        }
        MatriceR* mtemp=new MatriceR(qs);
        m2=mtemp->trasposta();
        delete mtemp;
        ui->plainTextEdit_2->setPlainText(QString::fromStdString(m2->toString()));
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Sintassi matrice errata"));
        mB.exec();
    }
}

void MatrixWin::on_AC1_clicked()
{
    ui->plainTextEdit->setPlainText(QString(""));
}

void MatrixWin::on_AC2_clicked()
{
    ui->plainTextEdit_2->setPlainText(QString(""));
}

void MatrixWin::on_moltS1_clicked()
{
    int n= ui->spinBox_2->value();
    QString qs=ui->plainTextEdit->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        MatriceR* mtemp=new MatriceQ(qs);
        m1=(*mtemp)*n;
        delete mtemp;
        ui->plainTextEdit->setPlainText(QString::fromStdString(m1->toString()));
    }else if(MatriceR::checkparserR(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        MatriceR* mtemp=new MatriceR(qs);
        m1=(*mtemp)*n;
        delete mtemp;
        ui->plainTextEdit->setPlainText(QString::fromStdString(m1->toString()));
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Sintassi matrice errata"));
        mB.exec();
    }

}

void MatrixWin::on_moltS2_clicked()
{
    int n= ui->spinBox_3->value();
    QString qs=ui->plainTextEdit_2->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        MatriceR* mtemp=new MatriceQ(qs);
        m2=(*mtemp)*n;
        delete mtemp;
        ui->plainTextEdit_2->setPlainText(QString::fromStdString(m2->toString()));
    }else if(MatriceR::checkparserR(qs)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        MatriceR* mtemp=new MatriceR(qs);
        m2=(*mtemp)*n;
        delete mtemp;
        ui->plainTextEdit_2->setPlainText(QString::fromStdString(m2->toString()));
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Sintassi matrice errata"));
        mB.exec();
    }
}

void MatrixWin::on_traccia1_clicked()
{
    QString qs=ui->plainTextEdit->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        m1=new MatriceQ(qs);
        int t= dynamic_cast<MatriceQ*>(m1)->traccia();
        QMessageBox mB;
        mB.setWindowTitle("Traccia");
        mB.setText(QString("La traccia della matrice e' :") + QString::number(t));
        mB.exec();
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("La matrice inserita non è una matrice quadrata o non e' scritta correttamente"));
        mB.exec();
    }
}

void MatrixWin::on_traccia2_clicked()
{
    QString qs=ui->plainTextEdit_2->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        m2=new MatriceQ(qs);
        int t= dynamic_cast<MatriceQ*>(m2)->traccia();
        QMessageBox mB;
        mB.setWindowTitle("Traccia");
        mB.setText(QString("La traccia della matrice e' :") + QString::number(t));
        mB.exec();
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("La matrice inserita non è una matrice quadrata o non e' scritta correttamente"));
        mB.exec();
    }
}

void MatrixWin::on_simm1_clicked()
{
    QString qs=ui->plainTextEdit->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        m1=new MatriceQ(qs);
        bool s= dynamic_cast<MatriceQ*>(m1)->isSimmetrica();
        QString qsmb;
        if(s){
            qsmb="La matrice e' simmetrica";
        }else{
            qsmb="La matrice NON e' simmetrica";
        }
        QMessageBox mB;
        mB.setWindowTitle("Simmetrica");
        mB.setText(qsmb);
        mB.exec();
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("La matrice inserita non è una matrice quadrata o non e' scritta correttamente"));
        mB.exec();
    }
}

void MatrixWin::on_simm2_clicked()
{
    QString qs=ui->plainTextEdit_2->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        m2=new MatriceQ(qs);
        bool s= dynamic_cast<MatriceQ*>(m2)->isSimmetrica();
        QString qsmb;
        if(s){
            qsmb="La matrice e' simmetrica";
        }else{
            qsmb="La matrice NON e' simmetrica";
        }
        QMessageBox mB;
        mB.setWindowTitle("Simmetrica");
        mB.setText(qsmb);
        mB.exec();
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("La matrice inserita non è una matrice quadrata o non e' scritta correttamente"));
        mB.exec();
    }
}

void MatrixWin::on_exp1_clicked()
{
    QString qs=ui->plainTextEdit->toPlainText();
    unsigned int esp= ui->spinBox_4->value();
    if(MatriceQ::checkparserQ(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        MatriceQ* mtemp=new MatriceQ(qs);
        m1=mtemp->esponenziale(esp);
        delete mtemp;
        ui->plainTextEdit->setPlainText(QString::fromStdString(m1->toString()));
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("La matrice inserita non è una matrice quadrata o non e' scritta correttamente"));
        mB.exec();
    }
}

void MatrixWin::on_exp2_clicked()
{
    QString qs=ui->plainTextEdit_2->toPlainText();
    unsigned int esp= ui->spinBox_5->value();
    if(MatriceQ::checkparserQ(qs)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        MatriceQ* mtemp=new MatriceQ(qs);
        m2=mtemp->esponenziale(esp);
        delete mtemp;
        ui->plainTextEdit_2->setPlainText(QString::fromStdString(m2->toString()));
    }else{
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("La matrice inserita non è una matrice quadrata o non e' scritta correttamente"));
        mB.exec();
    }
}

void MatrixWin::on_diff_clicked()
{
    bool error=false;
    QString qs=ui->plainTextEdit->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        m1=new MatriceQ(qs);
    }else if(MatriceR::checkparserR(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        m1=new MatriceR(qs);
    }else{
        error=true;
    }

    QString qs2=ui->plainTextEdit_2->toPlainText();
    if(MatriceQ::checkparserQ(qs2)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        m2=new MatriceQ(qs2);
    }else if(MatriceR::checkparserR(qs2)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        m2=new MatriceR(qs2);
    }else{
        error=true;
    }

    if(error==true){
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Sintassi di una delle matrici o di entrambe e' errata"));
        mB.exec();
    }else{
        if(m3 !=0){
            delete m3;
            m3=0;
        }
        try {
            m3=(*m1)-(*m2);
            ui->plainTextEdit_3->setPlainText(QString::fromStdString(m3->toString()));
        } catch (erroriOp e) {
            QMessageBox mB;
            mB.setWindowTitle("Si e' verificato un errore");
            mB.setText(QString("Le due matrici non hanno dimensioni tra loro compatibili"));
            mB.exec();
        }

    }
}

void MatrixWin::on_add_clicked()
{
    bool error=false;
    QString qs=ui->plainTextEdit->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        m1=new MatriceQ(qs);
    }else if(MatriceR::checkparserR(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        m1=new MatriceR(qs);
    }else{
        error=true;
    }

    QString qs2=ui->plainTextEdit_2->toPlainText();
    if(MatriceQ::checkparserQ(qs2)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        m2=new MatriceQ(qs2);
    }else if(MatriceR::checkparserR(qs2)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        m2=new MatriceR(qs2);
    }else{
        error=true;
    }

    if(error==true){
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Sintassi di una delle matrici o di entrambe e' errata"));
        mB.exec();
    }else{
        if(m3 !=0){
            delete m3;
            m3=0;
        }
        try {
            m3=(*m1)+(*m2);
            ui->plainTextEdit_3->setPlainText(QString::fromStdString(m3->toString()));
        } catch (erroriOp e) {
            QMessageBox mB;
            mB.setWindowTitle("Si e' verificato un errore");
            mB.setText(QString("Le due matrici non hanno dimensioni tra loro compatibili"));
            mB.exec();
        }
    }
}

void MatrixWin::on_moltM_clicked()
{
    bool error=false;
    QString qs=ui->plainTextEdit->toPlainText();
    if(MatriceQ::checkparserQ(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        m1=new MatriceQ(qs);
    }else if(MatriceR::checkparserR(qs)){
        if(m1!=0){
            delete m1;
            m1=0;
        }
        m1=new MatriceR(qs);
    }else{
        error=true;
    }

    QString qs2=ui->plainTextEdit_2->toPlainText();
    if(MatriceQ::checkparserQ(qs2)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        m2=new MatriceQ(qs2);
    }else if(MatriceR::checkparserR(qs2)){
        if(m2!=0){
            delete m2;
            m2=0;
        }
        m2=new MatriceR(qs2);
    }else{
        error=true;
    }

    if(error==true){
        QMessageBox mB;
        mB.setWindowTitle("Si e' verificato un errore");
        mB.setText(QString("Sintassi di una delle matrici o di entrambe e' errata"));
        mB.exec();
    }else{
        if(m3 !=0){
            delete m3;
            m3=0;
        }
        try {
            m3=(*m1)*(*m2);
            ui->plainTextEdit_3->setPlainText(QString::fromStdString(m3->toString()));
        } catch (erroriOp e) {
            QMessageBox mB;
            mB.setWindowTitle("Si e' verificato un errore");
            mB.setText(QString("Le due matrici non hanno dimensioni tra loro compatibili"));
            mB.exec();
        }
    }
}

void MatrixWin::on_back_2_clicked()
{
    hide();
    ui->plainTextEdit->setPlainText(QString(""));
    ui->plainTextEdit_2->setPlainText(QString(""));
    ui->plainTextEdit_3->setPlainText(QString(""));
}
