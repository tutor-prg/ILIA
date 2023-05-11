#ifndef ENTERPRISE_H
#define ENTERPRISE_H
#include "linkedlist.h"
#include "person.h"
#include "department.h"

class Enterprise
{
    char chiefName[50];
    char name[50];
    char phone[20];
    LinkedList<Department> departments;
    LinkedList<Person*> staff;
public:
    Enterprise();
    void setName(const char* _name);
    void setChiefName(const char* _name);
    void setPhone(const char* _phone);

    void addNewEmployee(Person* employee);
    void showAllStaff() const;

    void addNewDepartment(Department department);
    void showAllDepartments() const;

    virtual ~Enterprise();
};

#endif // ENTERPRISE_H
