#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.h"


class Engineer : public Person
{
    char ProjectOrContractNumber[20];
protected:
    virtual void InitRnd();
public:
    Engineer();
    Engineer(const char *_name, const char *_lastName,
           int _year, const char *_adress, const char* _phone,
           const char* _projectOrContractNumber);

    const char* getProjectOrContractNumber() const;
    void  setProjectOrContractNumber(const char* _projectOrContractNumber);

    static Engineer getRandom();
    virtual ~Engineer();
    virtual void show(ostream& out) const;
    friend ostream& operator<<(ostream& out, const Engineer& engineer);
};

#endif // ENGINEER_H
