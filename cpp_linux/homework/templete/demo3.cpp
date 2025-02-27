#include <iostream>
using namespace std;

template<typename T>
void bubbleSort(T *A, int n)
{
    T temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

template<typename T>
void myPrint(T *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {3,45,57,35,3,5,57,452,23};
    bubbleSort(a, sizeof(a)/sizeof(a[0]));
    myPrint(a, sizeof(a)/sizeof(a[0]));

    double b[5] = {1.1, 32.4, 3.3, 2.4, 324.5};
    bubbleSort(b, sizeof(b)/sizeof(b[0]));
    myPrint(b, sizeof(b)/sizeof(b[0]));

    char c[]={'a','e','v','c','b','f'};
    bubbleSort(c, sizeof(c)/sizeof(c[0]));
    myPrint(c, sizeof(c)/sizeof(c[0]));

    return 0;
}
