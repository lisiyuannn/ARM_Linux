#include <iostream>
using namespace std;

template<typename T>
int seqSearch(T list[], int n, T key)
{
    for(int i = 0; i < n; i++)
    {
        if(list[i] == key) return i;
    }
    return -1;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    double b[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char c[]={'a','b','c','d','e','f'};

    cout << seqSearch(a, sizeof(a)/sizeof(a[0]), 2) << endl;
    cout << seqSearch(a, sizeof(a)/sizeof(a[0]), 7) << endl;

    cout << seqSearch(b, sizeof(b)/sizeof(b[0]), 3.3) << endl;
    cout << seqSearch(b, sizeof(b)/sizeof(b[0]), 2.3) << endl;

    cout << seqSearch(c, sizeof(c)/sizeof(c[0]), 'd') << endl;
    cout << seqSearch(c, sizeof(c)/sizeof(c[0]), 'h') << endl;

    return 0;
}
