#ifndef COLLEZIONEDATI_H
#define COLLEZIONEDATI_H

#include <vector>
#include <string>
#include "erroriinput.h"
#include "erroriop.h"

class CollezioneDati{
protected:
        unsigned int num;
        std::vector<int> elementi;

public:
    //Costruttori
    CollezioneDati(unsigned int);
    CollezioneDati(unsigned int, std::vector<int>);
    //Cotruttore copia
    CollezioneDati(const CollezioneDati&);
    //metodi get
    unsigned int getNum() const;
    std::vector<int> getDati() const;
    //op

    //metodi virtuali
    virtual CollezioneDati& operator=(const CollezioneDati&)=0;
    virtual CollezioneDati* clone() const=0;
    virtual bool operator ==( const CollezioneDati&) const = 0;
    virtual ~CollezioneDati() ;
    virtual CollezioneDati* operator-(const CollezioneDati&) const=0;
    virtual std::string toString() const = 0;
    int getMin() const;
    int getMax() const;
};

#endif // COLLEZIONEDATI_H
