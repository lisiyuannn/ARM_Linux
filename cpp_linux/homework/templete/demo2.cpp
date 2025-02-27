#include <iostream>
#include <string>
using namespace std;

//定义函数模板实现两个数的相加
template<typename T>
T add(T a, T b)
{
    return a+b;   
}

//定义函数模板实现两个数的比较
template<typename T>
int myCompare(T a, T b)
{
    if (a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}

//特化函数模板实现两个字符串的比较
template<>
int myCompare(string &a, string &b)
{
    int res = a.compare(b);
    if (res < 0) return -1;
    else if(res > 0)return 1;
    else return 0;
}


int main()
{
   int a = 1;
   int b = 2;
   double aa = 1.1;
   double bb = 2.2;
   
   string str1("sdfs");
   string str2("wegda");

   cout << add(a, b) << endl;
   cout << add(aa, bb) << endl;

   cout << myCompare(a, b) << endl;
   cout << myCompare(b, a) << endl;

   cout << myCompare(str1, str2) << endl;
   cout << myCompare(str2, str1) << endl;

    return 0;
}
