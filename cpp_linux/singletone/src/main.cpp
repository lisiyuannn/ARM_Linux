#include <iostream>
#include "singletone.h"

int main()
{
    Singletone* s1 = Singletone::getInstance();
    Singletone* s2 = Singletone::getInstance();

    std::cout << s1 << '\t' << s2 << std::endl;

    return 0;
    
}
