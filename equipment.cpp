#include "equipment.h"
#include <string.h>

Equipment::Equipment()
{
    strcpy(name, "unknown");
    strcpy(number, "unknown");
    department = nullptr;
    project = nullptr;
}

Equipment::Equipment(const char *_name, const char *_number, Department *_department, Project *_project)
{
    strcpy(name, _name);
    strcpy(number, _number);
    department = _department;
    project = _project;
}


Equipment::~Equipment()
{
    //dtor
}
