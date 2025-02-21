#include "object.h"
#include <iostream>
using namespace std;

Base::Base(int i, int j, int k)
    :publicData(i), protectedData(j), privateData(k)
{
    cout << "Base(int, int, int)" << endl;
}

void Base::testBase()
{
    publicData++;
    protectedData++;
    privateData++;
}

Child::Child(int i, int j, int k)
    :Base(i, j, k)
{
    cout << "Child(int, int, int)" << endl;
}

void Child::testChild()
{
    publicData++;
    protectedData++;
    //子类的成员函数无法访问父类的私有成员变量
    //privateData++;

}


