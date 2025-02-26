#include <iostream>
using namespace std;

//两数之和模板函数
template<typename T>
T add(T a, T b)
{
    return a+b;
}

int main(int argc, char const *argv[])
{
    cout << add<double>(1.2, 4.5) << endl;
    cout << add<double>(2, 8) << endl;
    cout << add('c', 'a') << endl;
    cout << add<int>(1.7, 4.5) << endl;

    return 0;
}
