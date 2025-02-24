#include <iostream>
#include "person.h"

using namespace std;

Person::Person()
{
    cout << "Person()" << endl;
}

Person::Person(int weight, int hight)
    :weight(weight), hight(hight)
{
    cout << "Person(int, int)" << endl;
}

Person::~Person()
{
    cout << "~Person()" << endl;
}

int Person::getweight()const
{
    return this->weight;
}

int Person::gethight()const
{
    return this->hight;
}
