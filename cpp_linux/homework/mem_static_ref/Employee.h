#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    static int number;

public:
    Employee();
    Employee(int, string);
    ~Employee();

    void setid(int);
    void setname(string);
    void print();
    void count();
};

#endif
