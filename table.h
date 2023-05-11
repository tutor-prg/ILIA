#ifndef TABLE_H
#define TABLE_H
#include "value.h"
#include "field.h"
#include <stdio.h>
#include "linkedlist.h"
#include <string.h>


class Table
{
    FILE* f;
    LinkedList<Field> fields;
    LinkedList<Value> CurrentRecord;
    char fileName[1000];
    int numberOfRecords;
    int dataOffset;
    void ResetCurrentRecord(){
        Value val;
        int n = getNumberOfFields();
        for (int i=0; i<n; i++){
            CurrentRecord.push_back(val);
        }
    }
    int getSizeOfRecord() const;
    int curRecordNumber;
public:
    Table(const char* _fileName);
    Table(const char* _fileName, const LinkedList<Field>& _fields);
    void showFields() const;
    int getNumberOfFields() const {return fields.size();}
    int getNumberOfRecords() const {return numberOfRecords;}
    const char* getFieldNameByIdx(int idx) const {return fields[idx].name;}
    int getFieldIdxByName(const char* fieldName) const;
    char getFieldTypeByIdx(int idx) const {return fields[idx].type;}

    void setIntFieldByIdx(int idx, int val);
    void setIntFieldByName(const char* fieldName, int val);
    int getIntFieldByIdx(int idx);
    int getIntFieldByName(const char* fieldName);

    void setDblFieldByIdx(int idx, double val);
    void setDblFieldByName(const char* fieldName, double val);
    double getDblFieldByIdx(int idx);
    double getDblFieldByName(const char* fieldName);

    void setBoolFieldByIdx(int idx, bool val);
    void setBoolFieldByName(const char* fieldName, bool val);
    bool getBoolFieldByIdx(int idx);
    bool getBoolFieldByName(const char* fieldName);

    void setStrFieldByIdx(int idx, const char* val);
    void setStrFieldByName(const char* fieldName, const char* val);
    const char* getStrFieldByIdx(int idx);
    const char* getStrFieldByName(const char* fieldName);

    void appendCurrentRecord();
    void OPEN();
    void ReadRecord();
    void WriteRecord();
    bool isEOF() const;
    void goTop();
    void goRecord(int recNo); //перейти на конкретний рядок таблиці
    void goBottom();
    void removeRecord(int recNo);
    void CLOSE();
    void showCurrentRecord();
    void show();

    virtual ~Table();
};

#endif // TABLE_H
