#ifndef __OBJECT_H
#define __OBJECT_H

class Base
{
public:
    int publicData;
protected:
    int protectedData;
private:
    int privateData;

public:
    Base(int, int , int);
   // ~Base();

    void testBase();
};

class Child:public Base
{
public:
    Child(int, int, int);
   // ~Child();

    void testChild();
};


#endif
