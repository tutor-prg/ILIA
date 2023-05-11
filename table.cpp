#include "my_lib.h"
#include "table.h"
#include <string.h>
#include <iostream>

using namespace std;

Table::Table(const char* _fileName){
    strcpy(fileName, _fileName);
    int fileLen = getFileLendth(fileName);
    FILE *f = fopen(fileName, "rb");
    if (!f)  throw "Table::Table(_fileName) - Error: Cannot open file for Table";

    int n;
    fread(&n, sizeof(n), 1, f);

    for (int i=0; i<n; i++){
        Field field;
        fread(&field, sizeof(field), 1, f);
        fields.push_back(field);
    }

    ResetCurrentRecord();

    dataOffset = sizeof(int)+n*sizeof(Field);
    int sizeOfRecord = getSizeOfRecord();
    numberOfRecords = (fileLen-dataOffset)/sizeOfRecord;
    fclose(f);
    f = nullptr;
    curRecordNumber = 0;
}

Table::Table(const char* _fileName, const LinkedList<Field>& _fields){
    fields = _fields;
    strcpy(fileName, _fileName);

    FILE *f = fopen(fileName, "wb");
    if (!f) throw "Table::Table(_fileName, _fields) - Error: Cannot create file for Table";
    fclose(f);
    f = fopen(fileName, "ab");

    int n = fields.size();
    fwrite(&n, sizeof(n), 1, f);
    for (int i=0; i<n; i++){
        Field field = fields[i];
        fwrite(&field, sizeof(field), 1, f);
    }

    ResetCurrentRecord();

    dataOffset = sizeof(int)+n*sizeof(Field);
    numberOfRecords = 0;
    fclose(f);
    f = nullptr;
    curRecordNumber = 0;
}

int Table::getFieldIdxByName(const char* fieldName) const{
    int n = getNumberOfFields();
    for (int i=0; i<n; i++){
        if (strcmp(fields[i].name, fieldName) == 0){
            return i;
        }
    }
    return -1;
}

void Table::showFields() const{
    cout << " --- " << fileName << " --- " << endl;
    fields.show(true);
}
//------------------------------------------------
void Table::setIntFieldByIdx(int idx, int val){
    CurrentRecord[idx].int_val = val;
}

int Table::getIntFieldByIdx(int idx){
    return CurrentRecord[idx].int_val;
}

void Table::setDblFieldByIdx(int idx, double val){
    CurrentRecord[idx].dbl_val = val;
}

double Table::getDblFieldByIdx(int idx){
    return CurrentRecord[idx].dbl_val;
}

void Table::setBoolFieldByIdx(int idx, bool val){
    CurrentRecord[idx].bool_val = val;
}

bool Table::getBoolFieldByIdx(int idx){
    return CurrentRecord[idx].bool_val;
}

void Table::setStrFieldByIdx(int idx, const char* val){
    strcpy(CurrentRecord[idx].str_val, val);
}

const char* Table::getStrFieldByIdx(int idx){
    return CurrentRecord[idx].str_val;
}
//------------------------------------------------

//------------------------------------------------
void Table::setIntFieldByName(const char* fieldName, int val){
    int idx = getFieldIdxByName(fieldName);
    if (idx == -1) throw "Table::setIntFieldByName() - Error: wrong field name";

    setIntFieldByIdx(idx, val);
}

int Table::getIntFieldByName(const char* fieldName){
    int idx = getFieldIdxByName(fieldName);
    if (idx == -1) throw "Table::getIntFieldByName() - Error: wrong field name";
    return getIntFieldByIdx(idx);
}

void Table::setDblFieldByName(const char* fieldName, double val){
    int idx = getFieldIdxByName(fieldName);
    if (idx == -1) throw "Table::setDblFieldByName() - Error: wrong field name";

    setDblFieldByIdx(idx, val);
}

double Table::getDblFieldByName(const char* fieldName){
    int idx = getFieldIdxByName(fieldName);
    if (idx == -1) throw "Table::getDblFieldByName() - Error: wrong field name";
    return getDblFieldByIdx(idx);
}

void Table::setBoolFieldByName(const char* fieldName, bool val){
    int idx = getFieldIdxByName(fieldName);
    if (idx == -1) throw "Table::setBoolFieldByName() - Error: wrong field name";

    setBoolFieldByIdx(idx, val);
}

bool Table::getBoolFieldByName(const char* fieldName){
    int idx = getFieldIdxByName(fieldName);
    if (idx == -1) throw "Table::getBoolFieldByName() - Error: wrong field name";
    return getBoolFieldByIdx(idx);
}

void Table::setStrFieldByName(const char* fieldName, const char* val){
    int idx = getFieldIdxByName(fieldName);
    if (idx == -1) throw "Table::setStrFieldByName() - Error: wrong field name";

    setStrFieldByIdx(idx, val);
}

const char* Table::getStrFieldByName(const char* fieldName){
    int idx = getFieldIdxByName(fieldName);
    if (idx == -1) throw "Table::getStrFieldByName() - Error: wrong field name";
    return getStrFieldByIdx(idx);
}
//------------------------------------------------


void Table::goTop(){
    //rewind(f);
    curRecordNumber = 0;
    fseek(f, dataOffset, SEEK_SET);
}

void Table::goRecord(int recNo){
    if (recNo<0) throw "Table::goRecord(int recNo) - Error: recNo<0";
    if (recNo>numberOfRecords) throw "Table::goRecord(int recNo) - Error: recNo>=numberOfRecords";
    curRecordNumber = recNo;
    int recSize = getSizeOfRecord();
    fseek(f, dataOffset+curRecordNumber*recSize, SEEK_SET);
}

void Table::removeRecord(int recNo){
    if (recNo<0) throw "Table::removeRecord(int recNo) - Error: recNo<0";
    if (recNo>numberOfRecords) throw "Table::removeRecord(int recNo) - Error: recNo>=numberOfRecords";
    //-----------------------------
    int recSize = getSizeOfRecord();
	char tmpFile[] = "tmp.tmp.tmp.tmp.tmp";
    FILE* tmp = fopen(tmpFile, "wb");
    int N = dataOffset+recNo*recSize;
    char x;
    rewind(f);
    for (int i=0; i<N; i++){
        fread(&x, sizeof(x), 1, f);
        fwrite(&x, sizeof(x), 1, tmp);
    }
    ReadRecord();
    while (fread(&x, sizeof(x), 1, f)){
        fwrite(&x, sizeof(x), 1, tmp);
    }
    fclose(tmp);
    curRecordNumber--;
    //-----------------------------
    CLOSE();
    remove(fileName);
    rename(tmpFile, fileName);
    OPEN();
}

void Table::goBottom(){
    curRecordNumber = numberOfRecords;
    fseek(f, 0, SEEK_END);
}

void Table::showCurrentRecord(){
    int n = getNumberOfFields();
    for (int j=0; j<n; j++)
    {
        char type = getFieldTypeByIdx(j);
        cout << CurrentRecord[j].toString(type) << " ";
    }
    cout << endl;
}

void Table::show(){
    //-------- шапка ----------
    int m = getNumberOfFields();
    cout << "+";
    for (int i=0; i<m; i++){
        int len = fields[i].getWidth()+2;
        for (int j=0; j<len; j++){
            cout <<"-";
        }
        cout << "+";
    }
    cout << endl;

    cout << "+ ";
    for (int i=0; i<m; i++){
        int len = fields[i].getWidth()+2;
        char* name = new char[len];
        strcpy(name, fields[i].name);
        center(name, len);
        cout  << name << " +";

        delete[] name;
    }
    cout << endl;

    cout << "+";
    for (int i=0; i<m; i++){
        int len = fields[i].getWidth()+2;
        for (int j=0; j<len; j++){
            cout <<"-";
        }
        cout << "+";
    }
    cout << endl;
    //-------------------------

    int n = getNumberOfRecords();
    OPEN();
    for (int i=0; i<n; i++)
    {
        ReadRecord();
        showCurrentRecord();
    }
    CLOSE();
}

bool Table::isEOF() const{
    if (curRecordNumber >= numberOfRecords) return true;
    return false;
}

void Table::OPEN(){
    if (f) CLOSE();
    f = fopen(fileName, "r+b");
    goTop();
}

void Table::CLOSE(){
    fclose(f);
    f = nullptr;
}

void Table::ReadRecord(){
    if (isEOF()) throw "Table::ReadRecord() - Error: Attempt to read beyond the EOF";
    int n = getNumberOfFields();
    for (int i=0; i<n; i++)
    {
        char fieldType = fields[i].type;
        if (fieldType == 'i')
        {
            int x;
            fread(&x, sizeof(x), 1, f);
            CurrentRecord[i].int_val = x;
        }
        if (fieldType == 'd')
        {
            double x;
            fread(&x, sizeof(x), 1, f);
            CurrentRecord[i].dbl_val = x;
        }
        if (fieldType == 'b')
        {
            bool x;
            fread(&x, sizeof(x), 1, f);
            CurrentRecord[i].bool_val = x;
        }
        if (fieldType == 's')
        {
            int len = fields[i].length;
            fread(CurrentRecord[i].str_val, sizeof(char), len, f);
        }
    }
    curRecordNumber++;
}

void Table::WriteRecord(){
    int n = getNumberOfFields();
    for (int i=0; i<n; i++){
        char fieldType = fields[i].type;
        if (fieldType == 'i'){
            int x = CurrentRecord[i].int_val;
            fwrite(&x, sizeof(x), 1, f);
        }
        if (fieldType == 'd'){
            double x = CurrentRecord[i].dbl_val;
            fwrite(&x, sizeof(x), 1, f);
        }
        if (fieldType == 'b'){
            bool x = CurrentRecord[i].bool_val;
            fwrite(&x, sizeof(x), 1, f);
        }
        if (fieldType == 's'){
            char* x = CurrentRecord[i].str_val;
            int len = fields[i].length;
            fwrite(x, sizeof(char), len, f);
        }
    }
    curRecordNumber++;
    if (curRecordNumber>numberOfRecords)numberOfRecords++;
}

void Table::appendCurrentRecord(){
    goBottom();
    WriteRecord();
}

int Table::getSizeOfRecord() const{
    int sum = 0;
    int n = getNumberOfFields();
    for (int i=0; i<n; i++)
    {
        char fieldType = fields[i].type;
        if (fieldType == 'i') sum += sizeof(int);
        if (fieldType == 'd') sum += sizeof(double);
        if (fieldType == 'b') sum += sizeof(bool);
        if (fieldType == 's') sum += fields[i].length;
    }
    return sum;
}

Table::~Table(){
    fclose(f);
}
