#include "project.h"
#include <string.h>

Project::Project()
{
    strcpy(name, "unknown");
    strcpy(number, "unknown");
    chief = nullptr;
    price = 0;
}

Project::Project(const char *_name, const char *_number, Person* _chief, int _price)
{
    strcpy(name, _name);
    strcpy(number, _number);
    chief = _chief;
    price = _price;
}

Project::~Project()
{
    //dtor
}
