#ifndef VALUE_H
#define VALUE_H
#include <string>
#include <sstream>

using namespace std;

union Value
{
    int int_val;
    double dbl_val;
    bool bool_val;
    char str_val[256];
    Value(){
        Reset();
    }
    void Reset(){
        dbl_val = 0;
    }

    string toString(char type){
        stringstream out;
        if (type == 'i') out << int_val;
        else if (type == 'd') out << dbl_val;
        else if (type == 'b') out << bool_val;
        else if (type == 's') out << str_val;
        else out << "Value::toString ERROR";
        return out.str();
    }
};



#endif // VALUE_H
