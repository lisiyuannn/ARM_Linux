#include <cstring>
#include "myString.h"

using namespace std;

MyString::MyString()
{
    this->length = 0;
    this->data = new char[1];
    this->data[0] = '\0';
}

MyString::MyString(const char* str)
{
    this->length = strlen(str);
    this->data = new char[this->length+1];
    strcpy(this->data, str);
}

//拷贝构造
MyString::MyString(const MyString& str)
{
    this->length = str.length;
    this->data = new char[str.length+1];
    strcpy(this->data, str.data);
}

MyString::~MyString()
{
    delete[] this->data;
}

//运算符重载
MyString& MyString::operator=(const MyString& str)
{
    if(this != &str)
    {
        delete[] this->data;
        this->length = str.length;
        this->data = new char[this->length+1];
        strcpy(this->data, str.data);
    }
    return *this;
}

bool MyString::operator==(const MyString& str)const
{
    return strcmp(this->data, str.data) == 0;
}

MyString MyString::operator+(const MyString& str)const
{
    char* newdata = new char[this->length + str.length];
    strcat(newdata, this->data);
    strcat(newdata, str.data);
    MyString newString{newdata};
    delete[] newdata;
    
    return newString;
}

char* MyString::getData()
{
    return this->data;
}

int MyString::getLength()
{
    return this->length;
}















