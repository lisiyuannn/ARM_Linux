#include <time.h>
#include <stdio.h>

int main()
{
    struct tm *local;
    time_t t;
    t = time(NULL);     //获取日历时间
    local = localtime(&t);  //转换日历时间为当地时区时间
    printf("%d/%d/%d/%d/%d/%d/\n", 
    local->tm_mon,
    local->tm_mday,
    local->tm_year+1900,
    local->tm_hour,
    local->tm_min,
    local->tm_sec
    );
    printf("%s",asctime(local));
    printf("%s",ctime(&t));
    local = gmtime(&t);     //转换日历时间为格林威治时间
    printf("%d/%d/%d/%d/%d/%d/\n", 
    local->tm_mon,
    local->tm_mday,
    local->tm_year+1900,
    local->tm_hour,
    local->tm_min,
    local->tm_sec
    );
    printf("%s",asctime(local));
    printf("%s",ctime(&t));
    return 0;
}
