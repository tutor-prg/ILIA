#ifndef TECHNIC_H
#define TECHNIC_H

#include "Person.h"


class Technic : public Person
{
    char EquipmentNumber[20];
protected:
    virtual void InitRnd();
public:
    Technic();
    Technic(const char *_name, const char *_lastName,
           int _year, const char *_adress, const char* _phone,
           const char* _equipmentNumber);

    const char* getEquipmentNumber() const;
    void  setEquipmentNumber(const char* _equipmentNumber);

    static Technic getRandom();
    virtual ~Technic();
    virtual void show(ostream& out) const;
    friend ostream& operator<<(ostream& out, const Technic& technic);
};

#endif // TECHNIC_H
