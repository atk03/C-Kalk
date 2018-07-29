#ifndef ERRORI_H
#define ERRORI_H

#include<string>


class Errori{
private:
    std::string exc;
public:
    std::string getExc() const;
    Errori(std::string );
    //virtual Errori(unsigned int e)=0;
    virtual ~Errori()=0;
protected:
    void setExc(std::string );
};

#endif // ERRORI_H
