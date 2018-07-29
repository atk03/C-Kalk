#ifndef MATRICER_H
#define MATRICER_H
#include"collezionedati.h"
#include <qstring.h>

class MatriceR: public CollezioneDati{
protected:
    unsigned int righe;
    unsigned int colonne;
public:
    MatriceR(unsigned int,unsigned int, std::vector<int>);
    MatriceR(unsigned int r =0,unsigned int c=0);
    MatriceR(const MatriceR&);
    MatriceR(QString);
    virtual ~MatriceR();
    //ridefinizione metodi virtuali classe base
    MatriceR& operator=(const CollezioneDati&);
    MatriceR* clone() const;
    bool operator ==(const CollezioneDati& ) const;
    MatriceR* operator-(const CollezioneDati& ) const;
    std::string toString() const;

    MatriceR* operator*(const int& s) const;

    //medodi propri
    //get
    unsigned int getRighe() const;
    unsigned  int getColonne() const;
    //accesso agli elemnti
    const int& getElemento(const unsigned int&, const unsigned int&) const;
    int& goElemento(const unsigned int &, const unsigned int &);
   //operazioni
    MatriceR* operator+(const MatriceR&) const;
    MatriceR* operator*(const MatriceR& ) const;
    MatriceR* trasposta() const;

    static bool checkparserR(QString all);
};

#endif // MATRICER_H
