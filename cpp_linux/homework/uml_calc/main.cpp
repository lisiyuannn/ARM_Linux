#include <iostream>
#include <cstring>
#include <string>
#include "calc.h"
using namespace std;


int main(int argc, char const *argv[])
{
    //数据检查
    if(argc != 4)
    {
        cerr << "arg error! Input [numA] [numB] ['oper'] " << strerror(errno) << endl;
        return 1;
    }
    if(strlen(argv[3]) > 1)
    {
        cerr << "arg error! Input [numA] [numB] ['oper'] " << strerror(errno) << endl;
        return 1;
    }

    double numA, numB;
    try {
        numA = std::stod(argv[1]);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
        return 1;
    }

    try {
        numB = std::stod(argv[2]);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
        return 1;
    }

    //开始计算
    Factory fac;
    Operation* oper = fac.createOper(argv[3][0]);
    if(oper == nullptr)
    {
        cout << "new Operation error" << endl;
        return 2;
    }
    oper->setNumA(numA);
    oper->setNumB(numB);
    double res = oper->getResult();
    cout << "计算完毕！" << endl;
    cout << argv[1] << " " << argv[3] << " " << argv[2] << " = " << res << endl;

    delete oper;
    return 0;
}
