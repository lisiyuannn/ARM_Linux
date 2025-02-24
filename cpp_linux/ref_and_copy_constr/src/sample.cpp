#include "sample.h"
#include <iostream>
using namespace std;

Sample::Sample(int num)
    :num(num)
{

}

//拷贝构造函数
Sample::Sample(const Sample& obj)
{
    cout << "this is copy constructs" << endl;
    this->num = obj.num;
}

int Sample::getNum()
{
    return this->num;

}
