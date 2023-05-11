#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

class Person
{
private:
    char name[30];
    char lastName[30];
    int year;
    char adress[60];
    char phone[20];
	int departNumber;
	int numberOfCertificates;
protected:
    char professionName[30];
    virtual void InitRnd();
public:
    Person();
    Person(const char *_name, const char *_lastName,
           int _year, const char *_adress, const char* _phone);
    static Person getRandom();

    const char* getName() const;
    void  setName(const char* _name);

    const char* getLastName() const;
    void  setLastName(const char* _lastName);

    const int getYear() const;
    void  setYear(int _year);

    const char* getAdress() const;
    void  setAdress(const char* _adress);

    const char* getPhone() const;
    void  setPhone(const char* _phone);

    void appointToDepartment(int _departNumber);
	int getDepNumber() const {return departNumber;}

	const int getNumberOfCertificates() const;
	void  setNumberOfCertificates(int _numberOfCertificates);

    virtual void show(ostream& out) const;

    virtual ~Person();
    friend ostream& operator<<(ostream& out, const Person& person);
};

#endif // PERSON_H
