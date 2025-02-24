#include <iostream>
#include "student.h"
#include <string>
using namespace std;

void max(Student* c, int size)
{
	int tag = 0;
	for(int i = 1; i < size; i++)
	{
		if(c[tag].score < c[i].score)
		{
			tag = i;
		}
	}
	cout << c[tag].id << " have the highest score " << c[tag].score << endl;
}

int main()
{
	Student *class1 = new Student[3];
	class1[0] = {10001, "Alice", 90.5, 0};
	class1[1] = {10002, "Bob", 70.5, 1};
	class1[2] = {10003, "Tom", 80.5, 1};

	max(class1, sizeof(class1)/sizeof(class1[1]));

	delete[] class1;

	return 0;
}
