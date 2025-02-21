#include <iostream>
#include "object.h"
using namespace std;

int main()
{
    Base b(1, 2, 3);
    b.publicData++;
    //类的实例无法访问保护成员
    //b.protectedData++;
    //类的实例无法访问私有成员
    //b.privateData++;

    Child c(1, 2, 3);
    c.publicData++;
    //子类的对象无法访问父类受保护的成员
    // c.protectedData++;
    //子类的对象无法访问父类私有成员
    // c.privateData++;
    
    return 0;
}
