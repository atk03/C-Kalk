#ifndef INSIEME_H
#define INSIEME_H

#include<collezionedati.h>
#include<QString>

class Insieme: public CollezioneDati {
public:
    Insieme(unsigned int);
    Insieme(unsigned int, std::vector<int>);
    Insieme(const Insieme&);
    Insieme(QString);
    Insieme* clone() const;
    Insieme& operator =(const CollezioneDati&);
    bool operator ==(const CollezioneDati&) const;
    virtual ~Insieme();

    //op virtual
    Insieme* operator -(const CollezioneDati&) const;
    std::string toString() const;
    //op di insieme
    Insieme* unione(const Insieme&) const;
    Insieme* intersezione(const Insieme&) const;


    static bool checkparserI(QString all);
};

#endif // INSIEME_H
