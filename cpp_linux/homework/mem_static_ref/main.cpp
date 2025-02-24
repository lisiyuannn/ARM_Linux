#include <iostream>
#include <cstring>
using namespace std;

void swap(char* &a, char* &b)
{
    char *temp = a;
    a = b;
    b = temp;
}

int main()
{
    const char* ap = "hello";
    const char* bp = "how are you?";

    cout << "before swap" << endl;
    cout << ap << endl;
    cout << bp << endl;

    swap(ap, bp);

    cout << "after swap" << endl;
    cout << ap << endl;
    cout << bp << endl;

    return 0;
}
