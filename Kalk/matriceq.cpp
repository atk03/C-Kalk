#include "matriceq.h"

MatriceQ::MatriceQ(unsigned int n): MatriceR::MatriceR(n,n,std::vector<int>(n*n,0)){}
MatriceQ::MatriceQ(unsigned int n,std::vector<int> e): MatriceR::MatriceR(n,n,e) {
    if(e.size() != n*n){
        throw new erroriInput("I dati non sono coerenti");
    }
}
MatriceQ::MatriceQ(const MatriceQ& m): MatriceR::MatriceR(m) {}
MatriceQ::~MatriceQ(){}
MatriceQ::MatriceQ(QString all): MatriceR::MatriceR(0){
    if(!checkparserQ(all)){
        throw new erroriInput("I dati non sono coerenti");
    }
        bool b=true;
            QString q=all;
            unsigned int nrighe=all.count(QString(";"));
            unsigned int ncolonne=all.left(all.indexOf(QString(";"))).count(QString(","))+1;
            for(unsigned int j=0;j<nrighe && b;++j){
                unsigned int ii=q.left(q.indexOf(QString(";"))).count(QString(","))+1;
                if(ii!=ncolonne){
                    b=false;
                }else{
                    q=q.section(";",1);
                }
            }
            all.replace(";",",");
            std::vector<int> v;
            for(unsigned int j=0;j<nrighe*ncolonne;j++){
                QString supp = all.section(",",0,0);
                all = all.section(",",1);
                v.push_back(supp.toInt());
            }
            righe=nrighe;
            colonne=ncolonne;
            this->num=righe*colonne;
            this->elementi=v;
}

MatriceQ* MatriceQ::clone() const{
  return new MatriceQ(*this);
}
//operazioni esclusive
int MatriceQ::traccia() const {
    int t=0;
    unsigned int n=this->getColonne();
    for (unsigned int i=0; i<n*n; i+=n+1)
        t+=this->elementi.at(i);
    return t;

}
bool MatriceQ::isSimmetrica() const{
    unsigned int n = this->getRighe();
    bool b=true;
    for(unsigned int r=0;r<n && b;r++){
        for(unsigned int c=0;c<n &&b;c++){
            if((*this).getElemento(c,r) != (*this).getElemento(r,c)){
               b= false;
            }
        }
    }
    return b;
}
MatriceQ* MatriceQ::esponenziale(const unsigned int& x) const{
        MatriceR *mExp = new MatriceQ(*this);
        for(unsigned int i=1;i<x;i++){
            MatriceR *mExp2= (*mExp)*(*(const_cast<MatriceQ*>(this)));
            delete mExp;
            mExp=mExp2;

        }
        return dynamic_cast<MatriceQ*>(mExp);
}

bool MatriceQ::checkparserQ(QString all){
    bool b=true;
    QString q=all;
    unsigned int nrighe=all.count(QString(";"));
    unsigned int ncolonne=all.left(all.indexOf(QString(";"))).count(QString(","))+1;
    for(unsigned int j=0;j<nrighe && b;++j){
        unsigned int ii=q.left(q.indexOf(QString(";"))).count(QString(","))+1;
        if(ii!=ncolonne){
            b=false;
        }else{
            q=q.section(";",1);
        }
    }
    if(!b || q.section(";",0,0)!=QString("")){
        return false;
    }else{
        if(nrighe==ncolonne){
            return true;
        }else{
            return false;
        }
    }
}
