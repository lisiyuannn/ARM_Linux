#include "student.h"
#include <iostream>
using namespace std;

Student::Student()
{
    cout << "Student()" << endl;
}

Student::Student(int id)
    :student_id(id)
{
    cout << "Student(int)" << endl;
}

Student::Student(int id, int weight, int hight)
    :Person(weight, hight), student_id(id)
{
    cout << "Student(int , int, int)" << endl;
}

Student::~Student()
{
    cout << "~Student()" << endl;
}

int Student::get_id()const
{
    return this->student_id;
}
