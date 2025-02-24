#include "student.h"
#include <cstring>
#include <iostream>
using namespace std;

Student::Student()
{
    cout << "Student()" << endl;
}

Student::Student(float score, bool sex)
    :score{score}, sex{sex}
{
    this->name = new char[17];
    strcpy(name, "default_name");
    cout << "Student(float, bool)" << endl;
    
}

Student::~Student()
{
    if(this->name != nullptr)
    {
        delete[] this->name;
    }
}

void Student::introduce()
{
    cout << "I am " << this->name << ", my score is " << this->score 
    << "!"<< endl;
}
