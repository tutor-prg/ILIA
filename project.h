#ifndef PROJECT_H
#define PROJECT_H
#include "person.h"
#include "linkedlist.h"

class Project
{
    char name[30];
    char number[20];
    Person* chief;
    LinkedList<Person*> staff;
    int price;
public:
    Project();
    Project(const char *_name, const char *_number, Person* _chief, int _price);
    const char* getName() const { return name;}
    const char* getNumber() const { return number;}
    const Person* getChief() const { return chief;}
    int getPrice() const { return price;}
    int getNumberOfStaff() const {return staff.size();}
    const Person* getParticipantByIdx(int idx) const {return staff[idx];}
    virtual ~Project();
};

#endif // PROJECT_H
