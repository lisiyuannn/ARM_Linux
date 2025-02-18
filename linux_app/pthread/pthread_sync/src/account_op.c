#include "account.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//定义线程运行函数

void* withdraw_func(void *arg)
{
    Account *a = (Account*)arg;
    double amt = withdraw(a, 10000);
    printf("%lx withdraw: %lf\n", pthread_self(), (double)amt);
    return (void*)0;
}

int main()
{
    pthread_t boy, gril;
    int err;

    //创建账户
    Account *myaccount = account_creat(100001, 10000);

    //创建两个线程同时执行取款操作
    err = pthread_create(&boy, NULL, withdraw_func, myaccount);
    if(err < 0)
    {
        perror("boy pthread_create");
        exit(1);
    }
    err = pthread_create(&gril, NULL, withdraw_func, myaccount);
    if(err < 0)
    {
        perror("gril pthread_create");
        exit(1);
    }

    double amt;
    pthread_join(boy, (void **)&amt);
    //printf("boy withdraw: %lf\n", (double)amt);
    pthread_join(gril, (void **)&amt);
    //printf("gril withdraw: %lf\n", (double)amt);

    account_destroy(myaccount);

    return 0;
}
