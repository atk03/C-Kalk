#include "errori.h"

std::string Errori::getExc() const{
    return exc;
}

Errori::Errori(std::string s): exc(s) {}

void Errori::setExc(std::string s){ exc=s;}

Errori::~Errori(){}
