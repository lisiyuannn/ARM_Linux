#ifndef __STUDENT_H
#define __STUDENT_H

class Student
{
public:
    char* name;
    float score;
    bool sex;

public:
    Student();
    Student(float, bool);
    ~Student();

public:
    void introduce();
};

#endif
