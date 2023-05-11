#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "person.h"
#include "linkedlist.h"

class Department
{
    int number;
    char name[50];
    Person* chief;
public:
    Department();
    Department(int _number, const char* _name, Person* _chief=NULL);
    virtual void show(ostream& out) const;
    virtual ~Department();
};

#endif // DEPARTMENT_H
