#include "technic.h"
#include <string.h>

void Technic::InitRnd(){
    Person::InitRnd();
    int rnd = rand()%10;
    char EquipmentNumber[20] = "None";
    sprintf(EquipmentNumber, "EquipmentNumber EQ%05d", rand()%10000);
    setEquipmentNumber(EquipmentNumber);
}

Technic::Technic()
{
    //ctor
}

Technic::Technic(const char *_name, const char *_lastName,
           int _year, const char *_adress, const char* _phone,
           const char* _equipmentNumber)
    :Person(_name, _lastName, _year, _adress, _phone)
{
    strcpy(EquipmentNumber, _equipmentNumber);
    strcpy(professionName, "Technic");
}

const char* Technic::getEquipmentNumber() const{
    return EquipmentNumber;
}

void Technic::setEquipmentNumber(const char* _equipmentNumber){
    strcpy(EquipmentNumber, _equipmentNumber);
}

Technic Technic::getRandom(){
    Technic technic;
    technic.InitRnd();
    return technic;
}

Technic::~Technic()
{
    //dtor
}

void Technic::show(ostream& out) const{
    Person::show(out);
    out << " " << getEquipmentNumber();
}

ostream& operator<<(ostream& out, const Technic& technic){
    out << (Person)technic << " " << technic.getEquipmentNumber();
    return out;
}
