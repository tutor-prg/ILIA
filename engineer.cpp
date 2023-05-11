#include "engineer.h"
#include <string.h>
#include <stdlib.h>

void Engineer::InitRnd(){
    Person::InitRnd();
    int rnd = rand()%10; //0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    char projectOrContractNumber[20] = "None";
    if (rnd == 0){
        sprintf(projectOrContractNumber, "Project PR%05d", rand()%10000);
    }
    if (rnd == 1){
        sprintf(projectOrContractNumber, "Contract C#%05d", rand()%10000);
    }
    setProjectOrContractNumber(projectOrContractNumber);
}

Engineer::Engineer()
{
    //ctor
}

Engineer::Engineer(const char *_name, const char *_lastName,
           int _year, const char *_adress, const char* _phone,
           const char* _projectOrContractNumber)
    :Person(_name, _lastName, _year, _adress, _phone)
{
    strcpy(ProjectOrContractNumber, _projectOrContractNumber);
    strcpy(professionName, "Engineer");
}

const char* Engineer::getProjectOrContractNumber() const{
    return ProjectOrContractNumber;
}

void Engineer::setProjectOrContractNumber(const char* _projectOrContractNumber){
    strcpy(ProjectOrContractNumber, _projectOrContractNumber);
}

Engineer Engineer::getRandom(){
    Engineer engineer;
    engineer.InitRnd();
    return engineer;
}

Engineer::~Engineer()
{
    //dtor
}

void Engineer::show(ostream& out) const{
    Person::show(out);
    out << " " << getProjectOrContractNumber();
}

ostream& operator<<(ostream& out, const Engineer& engineer){
    out << (Person)engineer << " " << engineer.getProjectOrContractNumber();
    return out;
}
