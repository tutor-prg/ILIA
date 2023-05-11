#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "engineer.h"


class Constructor : public Engineer
{
    int numberOfCertificates;
    virtual void InitRnd();
public:
    Constructor();
    Constructor(const char *_name, const char *_lastName,
           int _year, const char *_adress, const char* _phone,
           char* _projectOrContractNumber, int _numberOfCertificates);

    const int getNumberOfCertificates() const;
    void  setNumberOfCertificates(int _numberOfCertificates);

    static Constructor getRandom();
    virtual ~Constructor();
    virtual void show(ostream& out) const;
    friend ostream& operator<<(ostream& out, const Constructor& constructor);
};

#endif // CONSTRUCTOR_H
