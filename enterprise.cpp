#include "enterprise.h"
#include <string.h>
#include <iostream>

using namespace std;

Enterprise::Enterprise()
{
    //ctor
}

void Enterprise::setName(const char* _name){
    strcpy(name, _name);
}

void Enterprise::setChiefName(const char* _name){
    strcpy(chiefName, _name);
}

void Enterprise::setPhone(const char* _phone){
    strcpy(phone, _phone);
}

void Enterprise::addNewEmployee(Person* employee){
    staff.push_back(employee);
}

void Enterprise::showAllStaff() const{
    int n = staff.size();
    for (int i=0; i<n; i++){
        staff[i]->show(cout);
        cout << endl;
    }
}

void Enterprise::showAllDepartments() const
{
    int n = departments.size();
    for (int i=0; i<n; i++){
        departments[i].show(cout);
        cout << "\n";
    }
}

void Enterprise::addNewDepartment(Department department){
    departments.push_back(department);
}

Enterprise::~Enterprise()
{
    //dtor
}
