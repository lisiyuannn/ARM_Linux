#include "sample.h"
#include <iostream>
using namespace std;

void func(Sample& obj);

int main()
{
    Sample obj(7);

    func(obj);

    return 0;
}

void func(Sample &obj)
{
    cout << obj.getNum() << endl;
}
