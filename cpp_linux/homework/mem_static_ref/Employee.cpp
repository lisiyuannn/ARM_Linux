#include <iostream>
#include "Employee.h"

using namespace std;

int Employee::number = 0;

Employee::Employee()
{
    cout << "Employee()" << endl;
}

Employee::Employee(int id, string name)
    :id(id), name(name)
{
    this->number++;
}

Employee::~Employee()
{
    this->number--;
    cout << "~Employee()" << endl;
}

void Employee::setid(int id)
{
    this->id = id;
}

void Employee::setname(string name)
{
    this->name = name;
}

void Employee::print()
{
    cout << "name: " << this->name
    << ", id is " << this->id << endl;
}

void Employee::count()
{
    cout << "The total number people is " << this->number << endl;
}
