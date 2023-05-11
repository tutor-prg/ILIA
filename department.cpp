#include "department.h"
#include <string.h>

Department::Department()
{
    //ctor
}

Department::Department(int _number, const char* _name, Person* _chief){
    number = _number;
    strcpy(name, _name);
    chief = _chief;
}

void Department::show(ostream& out) const{
    out << "#" << number << " " << name << " Chief:"
        << chief->getLastName() << " " << chief->getName();
}

Department::~Department()
{
    //dtor
}
