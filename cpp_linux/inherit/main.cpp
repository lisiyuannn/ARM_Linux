#include <iostream>
#include "person.h"
#include "student.h"
using namespace std;

int main()
{
    cout << "Person is " << sizeof(Person) << endl;
    cout << "Student is " << sizeof(Student) << endl;

    Student s1(10001, 180, 75);

    return 0;

}

