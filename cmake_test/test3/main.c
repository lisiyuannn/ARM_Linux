#include <stdio.h>
#include "calc.h"

int main()
{
    int intRes;
    long longRes;
    double douRes;
    intRes = twoNumAdd(2, 8);
    printf("twoNumAdd is %d\n", intRes);
    
    intRes = twoNumSub(2, 8);
    printf("twoNumSub is %d\n", intRes);

    longRes = twoNumMul(2, 8);
    printf("twoNumMul is %ld\n", longRes);

    douRes = twoNumDiv(2, 8);
    printf("twoNumDiv is %lf\n", douRes);
    return 0;
}
