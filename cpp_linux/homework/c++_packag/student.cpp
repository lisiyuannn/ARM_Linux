#include "student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student(int id, string name, double score, bool sex)
	:id(id), name(name), score(score), sex(sex)
{
cout << "Student(int, string, int, bool)" << endl;
}

Student::Student()
{
	cout << "Student()" << endl;

}

Student::~Student()
{
	cout << "~Student()" << endl;
}

void Student::introduce()
{

	cout << "my name is " << this->name << endl;

	cout << "my score is " << this->score << endl;

	cout << "I am " << sex << "^_^" << endl;

}
