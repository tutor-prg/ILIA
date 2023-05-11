#include "field.h"
#include <algorithm>

Field::Field()
{
    //ctor
}

Field::~Field()
{
    //dtor
}

int Field::getWidth()const{
    int nameWidth = strlen(name);
    int dataWidth = length;
    if (type == 'i') dataWidth = 10;
    if (type == 'd') dataWidth = 12;
    if (type == 'b') dataWidth = 5;
    return max(nameWidth, dataWidth);
}

ostream& operator<<(ostream& out, const Field& field){
    out << " Name: " << field.name << "  Type: "
        << field.type << "  Len: " << field.length;
    return out;
}
