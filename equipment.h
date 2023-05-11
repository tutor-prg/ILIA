#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "department.h"
#include "project.h"


class Equipment
{
    char name[30];
    char number[20];
    Department *department;
    Project *project;
public:
    Equipment();
    Equipment(const char *_name, const char *_number, Department *_department, Project *_project);
    const char* getName() const { return name;}
    const char* getNumber() const { return number;}
    const Department* getDepartment() const { return department;}
    const Project* getProject() const { return project;}
    virtual ~Equipment();
};

#endif // EQUIPMENT_H
