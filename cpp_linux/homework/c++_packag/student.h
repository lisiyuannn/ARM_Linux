#ifndef __STUDENT_H
#define __STUDENT_H

#include <string>
using namespace std;

class Student
{
public:

	int id;
	string name;
	double score;
	bool sex;

	Student();
	Student(int, string, double, bool);
	~Student();

	void introduce();
};

#endif
