#include <iostream>
#include <cstring>
#include "myString.h"

using namespace std;

int main()
{
    MyString str1{"hello"};
    MyString str2{" world"};
    MyString str3{};

    str3 = str1;
    cout << str3.getData() << endl;
    str3 = str1 + str2;
    cout << str3.getData() << endl;

    if(str3 == str2) cout << "true" << endl;
    str3 = str2;
    if(str3 == str2) cout << "true2" << endl;


    return 0;
}
