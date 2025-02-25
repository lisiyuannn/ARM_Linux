/*
    自定义一个字符串类MyString，用来存放不定长的字符串
    重载运算符‘==’，‘+’，用于两个字符串的比较和连接
*/

#ifndef __MYSTRING_H
#define __MYSTRING_H

class MyString
{
private:
    int length;
    char *data;
public:
    //构造函数
    MyString();
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    //运算符重载
    MyString& operator=(const MyString& str);
    bool operator==(const MyString& str)const;
    MyString operator+(const MyString& str)const;

    char* getData();
    int getLength();
};

#endif
