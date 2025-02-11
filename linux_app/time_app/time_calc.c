#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>
#include <math.h>

void func()
{
    unsigned int i, j;
    double y;
    for(i = 0; i < 1000; i++)
    {
        for(j = 0; j < 1000; j++)
        {
            y++;
        }
    }
}

int main()
{
    struct timeval tpstart, tpend;
    double timeuse;

    gettimeofday(&tpstart, NULL);
    func();
    gettimeofday(&tpend, NULL);

    timeuse = 1000000 * (tpend.tv_sec - tpstart.tv_sec) + (tpend.tv_usec - tpstart.tv_usec);
    timeuse = timeuse/1000000;

    printf("%f\n", timeuse);
    return 0;
}
