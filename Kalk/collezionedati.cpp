#include "collezionedati.h"
#include <vector>


CollezioneDati::CollezioneDati(unsigned int n): num(n), elementi(n,0) {}
CollezioneDati::CollezioneDati(unsigned int n, std::vector<int> el): num(n), elementi(el) {
    if(n != elementi.size()){
        throw erroriInput("inserimento dati non valido");
    }
}
//Costruttore copia
CollezioneDati::CollezioneDati(const CollezioneDati& c): num(c.num), elementi(c.elementi){}
//metodi get
CollezioneDati::~CollezioneDati(){}
unsigned int CollezioneDati::getNum() const{    return num;}
std::vector<int> CollezioneDati::getDati() const{   return elementi;}

//operazioni

int CollezioneDati::getMin() const{
    if(elementi.size()==0){
        throw erroriOp(4);
    }
    int r=elementi.at(0);
    for(unsigned int i=1;i<elementi.size();i++){
        if(r>elementi.at(i)){
            r=elementi.at(i);
        }
    }
    return r;
}
int CollezioneDati::getMax() const{
    if(elementi.size()==0){
        throw erroriOp(4);
    }
    int r=elementi.at(0);
    for(unsigned int i=1;i<elementi.size();i++){
        if(r<elementi.at(i)){
            r=elementi.at(i);
        }
    }
    return r;

}
