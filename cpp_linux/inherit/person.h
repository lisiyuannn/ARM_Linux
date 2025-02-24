#ifndef __PERSON_H
#define __PERSON_H

class Person
{
private:
    int weight;
    int hight;

public:
    Person();
    Person(int , int);
    ~Person();

    int getweight()const;
    int gethight()const;
};

#endif
