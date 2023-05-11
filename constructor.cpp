#include "constructor.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Constructor::Constructor()
{
    //ctor
}

Constructor::Constructor(const char *_name, const char *_lastName,
           int _year, const char *_adress, const char* _phone,
           char* _projectOrContractNumber, int _numberOfCertificates)
    :Engineer(_name, _lastName, _year, _adress, _phone, _projectOrContractNumber)
{
    numberOfCertificates = _numberOfCertificates;
    strcpy(professionName, "Constructor");
}

const int Constructor::getNumberOfCertificates() const{
    return numberOfCertificates;
}

void  Constructor::setNumberOfCertificates(int _numberOfCertificates){
    numberOfCertificates = _numberOfCertificates;
}

void Constructor::InitRnd(){
    Engineer::InitRnd();
    setNumberOfCertificates(rand()%7);
}

Constructor Constructor::getRandom(){
    Constructor constructor;
    constructor.InitRnd();
    return constructor;
}

ostream& operator<<(ostream& out, const Constructor& constructor){
    out << (Engineer)constructor << " " << constructor.numberOfCertificates;
    return out;
}

void Constructor::show(ostream& out) const{
    Engineer::show(out);
    out << " " << numberOfCertificates;
}

Constructor::~Constructor()
{
    //dtor
}
