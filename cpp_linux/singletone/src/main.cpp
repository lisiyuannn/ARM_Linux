#include <iostream>
#include "singletone.h"

int main()
{
    Singletone* s1 = Singletone::getInstance();
    Singletone* s2 = Singletone::getInstance();

    std::cout << s1 << '\t' << s2 << std::endl;

    if(s1 == s2)
    {
        std::cout << "相等" << std::endl;
    }
    else
    {
        std::cout << "不相等" << std::endl;
    }

    return 0;
    
}
