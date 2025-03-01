#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char const *argv[])
{
    int num;

    for(int i = 0; i < 10; i++)
    {
        num = std::pow(10, i);
        std::cout << std::setiosflags(std::ios::left)
        << std::setw(10) << num << std::endl;
    }

    return 0;
}