#include "erroriop.h"

erroriOp::erroriOp(unsigned int e): Errori(""){
    if( e == 1){
        this->setExc("Le matrici hanno dimensione incompatibile");
    }else if ( e == 2){
        this->setExc("L'iniseme non e' corretto");
    }else if ( e == 3){
        this->setExc("Indice fuori dal range");
    }else if ( e == 4){
        this->setExc("Il vettore e' vuoto");
    }
}



