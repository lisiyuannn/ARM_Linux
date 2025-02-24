#ifndef __STUDENT_H
#define __STUDENT_H

#include "person.h"

class Student:Person
{
private:
    int student_id;
public:
    Student();
    Student(int);
    Student(int, int, int);
    ~Student();

    int get_id()const;
};

#endif
