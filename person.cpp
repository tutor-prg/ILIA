#include "person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Person::Person()
{
    //ctor
}

Person::Person(const char *_name, const char *_lastName,
           int _year, const char *_adress, const char* _phone){
    strcpy(name, _name);
    strcpy(lastName, _lastName);
    year = _year;
    strcpy(adress, _adress);
    strcpy(phone, _phone);
    departNumber = 0;
    strcpy(professionName, "none");
}

void Person::InitRnd(){
    char names[10][30]={"Ivan", "Iliano", "Vasyl", "Sergiy",
     "Yura", "Maryna", "Arsen", "Andriy", "Natalya", "Valentyna"};
    char lastNames[10][30]={"Shpak", "Davyiduk", "Vasyilchuk", "Bondar",
     "Yukovich", "Shevchenko", "Franko", "Tkach", "Pinkevich", "Homa"};
    char cityes[10][30]={"Lutsk", "Kharkiv", "Kyiv", "Donetsk", "Lviv",
    "Kolomyia", "Ivano-Frankivsk", "Kalush", "Khmelnytskyi", "Lugansk"};
    char streets[10][30]={"Dovzhenka", "Petliyura", "Franka", "Konovaltsi", "Hrushevskyi",
    "Mazepy", "Bandery", "Mozarta", "Leontovycha", "Drahomanova"};

    int i1 = rand()%10;
    int i2 = rand()%10;
    int i3 = rand()%10;
    int i4 = rand()%10;
    int i5 = rand()%100;
    int i6 = rand()%100;

    char name[30];      strcpy(name, names[i1]);
    char lastName[30];  strcpy(lastName, lastNames[i2]);
    int year = 1970 + rand()%50;

    char adress[60];
    sprintf(adress, "%s %s st. %d/%d", cityes[i3], streets[i4], i5, i6);

    char phone[20];
    char operators[8][3] = {"50", "68", "95", "99", "78", "67", "93", "66"};
    int i7 = rand()%8;
    int number = rand()%10000000;
    sprintf(phone, "+380%s%07d", operators[i7], number);

    setName(name);
    setLastName(lastName);
    setYear(year);
    setAdress(adress);
    setPhone(phone);
}

Person Person::getRandom(){
    Person person;
    person.InitRnd();
    return person;
}

const char* Person::getName() const{
    return name;
}

void  Person::setName(const char* _name){
    strcpy(name, _name);
}

const char* Person::getLastName() const{
    return lastName;
}

void  Person::setLastName(const char* _lastName){
    strcpy(lastName, _lastName);
}

const int Person::getYear() const{
    return year;
}

void  Person::setYear(int _year){
    year = _year;
}

const char* Person::getAdress() const{
    return adress;
}

void  Person::setAdress(const char* _adress){
    strcpy(adress, _adress);
}

const char* Person::getPhone() const{
    return phone;
}

void  Person::setPhone(const char* _phone){
    strcpy(phone, _phone);
}

void Person::appointToDepartment(int _departNumber){
    departNumber = _departNumber;
}

Person::~Person()
{
	//dtor
}

const int Person::getNumberOfCertificates() const{
	return numberOfCertificates;
}

void  Person::setNumberOfCertificates(int _numberOfCertificates){
    numberOfCertificates = _numberOfCertificates;
}

void Person::show(ostream& out) const{
    out <<professionName << " " << name << " " << lastName << " " << year
        << " " << adress << " " << phone << " " << departNumber;
}

ostream& operator<<(ostream& out, const Person& person){
    out << person.name << " " << person.lastName << " " << person.year
        << " " << person.adress << " " << person.phone << " " << person.departNumber;
    return out;
}
