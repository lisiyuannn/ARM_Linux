#include <iostream>
#include "exam.h"
using namespace std;

void exam(Examinee &e)
{
    e.exam();
}

int main()
{
    //创建好学生
    ExcellentStd es1;
    ExcellentStd es2;
    //创建坏学生
    PoorStd ps1;
    PoorStd ps2;

    //开始考试
    exam(es1);
    exam(es2);
    exam(ps1);
    exam(ps2);

    return 0;
}
