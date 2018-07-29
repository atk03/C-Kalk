#include "matricer.h"
#include "matriceq.h"

MatriceR::MatriceR(unsigned int r,unsigned int c, std::vector<int> e): righe(r), colonne(c), CollezioneDati::CollezioneDati(r*c,e){
    if(e.size() != r*c){
        throw new erroriInput("I dati non sono coerenti");
    }
}

MatriceR::MatriceR(unsigned int r,unsigned int c): righe(r), colonne(c), CollezioneDati::CollezioneDati(r*c,std::vector<int>(r*c,0)){}

MatriceR::MatriceR(const MatriceR& c): righe(c.getRighe()), colonne(c.getColonne()), CollezioneDati::CollezioneDati(c){}
MatriceR:: ~MatriceR(){}

MatriceR::MatriceR(QString all): CollezioneDati::CollezioneDati(0){
    if(!checkparserR(all)){
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

//get
unsigned int MatriceR::getRighe() const{    return righe;}
unsigned  int MatriceR::getColonne() const{   return colonne;}
//accesso agli elementi
const int& MatriceR::getElemento(const unsigned int& r,const unsigned int& c) const{
    if(r>= righe || c>= colonne){
        throw erroriOp(3);
     }
     return elementi.at(r*colonne+c);
}

int& MatriceR::goElemento(const unsigned int & r, const unsigned int & c){
    if(r>= righe || c>= colonne){
        throw erroriOp(3);
    }
    return elementi.at(r*colonne+c);
}

MatriceR* MatriceR::operator*(const int& s) const{
        MatriceR* moltScalare= this->clone();
        for(unsigned int i=0;i<this->elementi.size();i++){
            moltScalare->elementi.at(i) = this->elementi.at(i) * s;
        }
        return moltScalare;
    }

MatriceR& MatriceR::operator=(const CollezioneDati& cd){
    const MatriceR* mc=dynamic_cast<const MatriceR*>(&cd);
    MatriceR* m=const_cast<MatriceR*>(mc);
    if(m==0){
        throw new erroriInput("Operazione con tipo non compatibile");
    }
    if(this != m){
         righe=m->getRighe();
         colonne=m->getColonne();
         elementi.resize(righe*colonne);
         for(unsigned int r=0;r<righe;r++){
             for(unsigned int c=0;c<colonne;c++){
                 elementi.at(r*colonne +c)=m->getElemento(r,c);
             }//end colonne
         }//end righe
     }//end if
     return *this;
}

MatriceR* MatriceR::clone() const{
    return new MatriceR(*this);
}
bool MatriceR::operator==(const CollezioneDati& cd) const{
    const MatriceR* mc=dynamic_cast<const MatriceR*>(&cd);
    MatriceR* m=const_cast<MatriceR*>(mc);
    if(m==0){
        return false;
    }
    if(righe==m->getRighe() && colonne==m->getColonne()){
            for(unsigned int r=0;r<righe;r++){
                for(unsigned int c=0;c<colonne;c++){
                    if((*this).getElemento(r,c)!= m->getElemento(r,c)){
                        return false;
                    }//end if
                }//end colonne
            }//end righe
            return true;
        }//end if dimensione matrice
        return false;
}

MatriceR*  MatriceR::operator-(const CollezioneDati& cd) const{
    const MatriceR* mc=dynamic_cast<const MatriceR*>(&cd);
    MatriceR* m=const_cast<MatriceR*>(mc);
    if(m==0){
        throw new erroriInput("Operazione con tipo non compatibile");
    }
    if(this->righe==m->getRighe() && this->colonne==m->getColonne()){
        MatriceR* opDiff = this->clone();
        for(unsigned int r=0;r<this->getRighe();r++){
            for(unsigned int c=0;c<this->getColonne();c++){
                (*opDiff).goElemento(r,c)=(*this).getElemento(r,c)-m->getElemento(r,c);
            }//end colonne
        }//end righe
        return opDiff;
    }else{//end if dimensione
        throw erroriOp(1);
    }
}

MatriceR*  MatriceR::operator+(const MatriceR& m) const{
    if(this->righe==m.getRighe() && this->colonne==m.getColonne()){
        MatriceR* opAdd = this->clone();
        //garbage?
        for(unsigned int r=0;r<this->getRighe();r++){
            for(unsigned int c=0;c<this->getColonne();c++){
                (*opAdd).goElemento(r,c)=(*this).getElemento(r,c)+m.getElemento(r,c);
            }//end colonne
        }//end righe
        return opAdd;
    }else{//end if dimensione
        throw erroriOp(1);
    }
}

MatriceR* MatriceR::operator*(const MatriceR& m) const{
    if(this->colonne==m.getRighe()){
        unsigned int pr=this->getRighe();
        unsigned int pc=m.getColonne();
        unsigned int cc=this->getColonne();
        MatriceR* moltMatrici;
        if(pr==pc){//righe m1 = colonne m2
            moltMatrici= dynamic_cast<MatriceR*>(new MatriceQ(pr));
        }else{
            moltMatrici= new MatriceR(pr,pc);
        }
        for(unsigned int r=0;r<pr;r++){
            for(unsigned int c=0;c<pc;c++){
                for(unsigned int i=0;i<cc;i++){
                    (*moltMatrici).goElemento(r,c)+=(*this).getElemento(r,i)*m.getElemento(i,c);
                }// colonne seconda matrice
            }//end for colonne
        } //end for righe
        return moltMatrici;
    }else{//if verifica condizioni per fare la moltiplicazioni
    throw erroriOp(1);
    }
}
MatriceR* MatriceR::trasposta() const{
    MatriceR* trans;
    if(this->colonne==this->getRighe()){
        MatriceQ* pmq=new MatriceQ(this->getColonne());
        trans=dynamic_cast<MatriceR*>(pmq);
    }else{
        trans= new MatriceR(this->getColonne(),this->getRighe());
    }
    for(unsigned int r=0;r<this->getRighe();r++){
        for(unsigned int c=0;c<this->getColonne();c++){
            (*trans).goElemento(c,r)=(*this).getElemento(r,c);
        }
    }
    return trans;
}

std::string MatriceR::toString() const{
    std::string s="";
    unsigned int c=colonne;
    std::string supp;
    for(typename std::vector<int>::const_iterator i=elementi.begin();i!=elementi.end();i++){
        if(std::to_string( *i ).find(",") != -1){
            supp =std::to_string( *i ).replace(std::to_string( *i ).find(","),1,".");
        }else{
            supp = std::to_string( *i );
        }
        s=s+supp;
        c--;
        if(c==0){
            s=s+";";
            c=colonne;
        }else{
            s=s+",";

        }
    }
    return s;
}

bool MatriceR::checkparserR(QString all){
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
           all.replace(";",",");
           std::vector<int> v;
           for(unsigned int j=0;j<nrighe*ncolonne;j++){
               QString supp = all.section(",",0,0);
               all = all.section(",",1);
               v.push_back(supp.toInt());
           }
           return true;
       }
}
