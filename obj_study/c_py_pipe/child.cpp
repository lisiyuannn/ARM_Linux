#include <iostream>
#include <unistd.h>

int main()
{
    std::string line;
    while(std::getline(std::cin, line))
    {
        std::cout << "Child received: " << line << std::endl;
    }

    return 0;
}

