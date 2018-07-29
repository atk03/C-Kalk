
#include "insieme.h"


Insieme::Insieme(unsigned int n): CollezioneDati::CollezioneDati(n) {
    for(unsigned int i=0;i<n;i++){
        this->elementi.at(i)=i;
    }
}
Insieme::Insieme(unsigned int n, std::vector<int> e): CollezioneDati::CollezioneDati(n,e) {
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<n;j++){
            if((i != j && this->elementi.at(i)==this->elementi.at(j)) || n!=e.size()){
                throw new erroriInput("Sono presenti ripetizioni o le misure non coincidono");
            }
        }
    }
}

Insieme::Insieme(const Insieme& i) : CollezioneDati::CollezioneDati(i) {}

Insieme::Insieme(QString all): CollezioneDati::CollezioneDati(0){
    if(!checkparserI(all)){
        throw new erroriInput("Sono presenti ripetizioni o le misure non coincidono");
    }
    if(all!=QString(";")){
        unsigned int nelementi=all.count(QString(","))+1;
        std::vector<int> v;
        all.replace(";",",");
        for(unsigned int j=0;j<nelementi;j++){
            QString supp = all.section(",",0,0);
            all = all.section(",",1);
            v.push_back(supp.toInt());
         }
        this->num=nelementi;
        this->elementi=v;
    }
}
Insieme::~Insieme() {}
Insieme* Insieme::clone() const{
    return new Insieme(*this);
}


Insieme& Insieme::operator =(const CollezioneDati& i){
    const Insieme* mc=dynamic_cast<const Insieme*>(&i);
    Insieme* m=const_cast<Insieme*>(mc);
    if(m==0){
        throw new erroriInput("Operazione con tipo non compatibile");
    }
    if(this != &i){
         num=i.getNum();
         elementi.resize(num);
         for(unsigned int j=0;j<this->getNum();j++){
            elementi = i.getDati();
         }//end el
     }//end if
     return *this;
}
bool Insieme::operator==(const CollezioneDati& i) const{
    const Insieme* mc=dynamic_cast<const Insieme*>(&i);
    Insieme* m=const_cast<Insieme*>(mc);
    if(m==0){
        throw new erroriInput("Operazione con tipo non compatibile");
    }
    if(num == i.getNum()){
        for(unsigned int j=0;j<this->getNum();j++){
            int foundthis=this->getDati().at(j);
            bool trovato=false;
            for(unsigned int y=0;y<i.getNum() && !trovato;y++){
                int foundi=i.getDati().at(y);
                if(foundi==foundthis){
                    trovato=true;
                }
            }
            if(!trovato){
               return false;
            }
        }
        return true;
    }
    return false;
}

//op virtual

Insieme* Insieme::operator -(const CollezioneDati& i) const{ //{1,2,3}-{3,5}={1,2}
    const Insieme* mc=dynamic_cast<const Insieme*>(&i);
    Insieme* m=const_cast<Insieme*>(mc);
    if(m==0){
        throw new erroriInput("Operazione con tipo non compatibile");
    }
    unsigned int idif=0;
    std::vector<int> vdif;
    for(unsigned int j=0;j<this->getNum();j++){
        int foundthis=this->getDati().at(j);
        bool trovato=false;
        for(unsigned int y=0;y<i.getNum() && !trovato;y++){
            int foundi=i.getDati().at(y);
            if(foundi==foundthis){
                trovato=true;
            }
        }
        if(!trovato){
            vdif.push_back(foundthis);
            idif=idif+1;
        }
    }
    Insieme* diff= new Insieme(idif,vdif);
    return diff;

}

std::string Insieme::toString() const{
    std::string s="";
    bool b=true;
    for(std::vector<int>::const_iterator i=elementi.begin(); i!=elementi.end();i++){
        if(b){
            s=s+std::to_string(*i);
            b=false;
        }else{
            s=s+","+std::to_string(*i);
        }
    }
    s=s+";";
    return s;
}
//op di insieme
Insieme* Insieme::unione(const Insieme& i) const{
    Insieme* insr = this->clone();
    for(unsigned int j=0;j<i.getNum();j++){
        int foundthis=i.getDati().at(j);
        bool trovato=false;
        for(unsigned int y=0;y<this->getNum() && !trovato;y++){
            int foundi=this->getDati().at(y);
            if(foundi==foundthis){
                trovato=true;
            }
        }
        if(!trovato){
            insr->elementi.push_back(foundthis);
            insr->num=insr->num+1;
        }
    }

    return insr;
}

Insieme* Insieme::intersezione(const Insieme& i) const{
    unsigned int insnum=0;
    std::vector<int> insv;
    for(unsigned int j=0;j<i.getNum();j++){
        int foundthis=i.getDati().at(j);
        bool trovato=false;
        for(unsigned int y=0;y<this->getNum() && !trovato;y++){
            int foundi=this->getDati().at(y);
            if(foundi==foundthis){
                trovato=true;
            }
        }
        if(trovato){
            insv.push_back(foundthis);
            insnum=insnum+1;
        }
    }
    Insieme* insr= new Insieme(insnum,insv);
    return insr;
}

bool Insieme::checkparserI(QString all){
    //QString q=all;
    unsigned int nelementi=all.count(QString(","))+1;
    if(all.indexOf(';')!=all.length()-1){
        return false;
    }
    std::vector<int> v;
    all.replace(";",",");
    for(unsigned int j=0;j<nelementi;j++){
        QString supp = all.section(",",0,0);
        all = all.section(",",1);
        v.push_back(supp.toInt());
     }
    for(unsigned int i=0;i<v.size();i++){
        for(unsigned int j=0;j<v.size();j++){
            if(i!=j && v.at(i)==v.at(j)){
                return false;
            }
        }
    }
    return true;
}
