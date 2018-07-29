#ifndef MATRICEQ_H
#define MATRICEQ_H

#include "matricer.h"

class MatriceR;

class MatriceQ : public MatriceR{
public:
    //costruttori
    MatriceQ(unsigned int);
    MatriceQ(unsigned int,std::vector<int> );
    MatriceQ(const MatriceQ&);
    MatriceQ(QString);
    virtual ~MatriceQ();
    MatriceQ* clone() const;
    //operazioni esclusive
    int traccia() const;
    bool isSimmetrica() const;
    MatriceQ* esponenziale(const unsigned int&) const;
    static bool checkparserQ(QString all);
};

#endif // MATRICEQ_H
