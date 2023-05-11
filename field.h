#ifndef FIELD_H
#define FIELD_H
#include <string.h>
#include <iostream>

using namespace std;
#pragma pack(push, 1)
struct Field{
    char name[20];
    char type;//s-string, i-int, d-double, b-bool
    int length;
    Field();
    Field(const char* _name, char _type, int _length=0){
        strcpy(name, _name);
        type = _type;
        length = _length;
    }
    int getWidth()const;
    virtual ~Field();
};
#pragma pack(pop)

ostream& operator<<(ostream& out, const Field& field);


#endif // FIELD_H
