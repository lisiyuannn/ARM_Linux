/*
线程与信号的关系：在多线程程序中，信号的处理变得更加复杂。每个线程都有自己的信号掩码（signal mask），用于决定哪些信号会被阻塞（即不会被传递）。

信号的传递目标：在多线程环境中，信号可以发送给整个进程，也可以发送给特定的线程。具体取决于信号的类型和发送方式：

进程信号：某些信号（如SIGTERM、SIGKILL）是发送给整个进程的，所有线程都会受到影响。

线程信号：某些信号（如SIGSEGV、SIGFPE）是发送给特定线程的，通常是由于该线程执行了非法操作（如访问无效内存或除以零）。

信号处理函数：在多线程程序中，信号处理函数是进程级别的，即所有线程共享同一个信号处理函数。因此，信号处理函数必须是线程安全的。
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//信号处理函数
void signal_func(int signo)
{
    printf("%lx thread is running by signal_func!\n", pthread_self());
    if(signo == SIGALRM)
    {
        printf("timeout!\n");
        alarm(2);
    }
}


//线程入口函数
void* func(void* arg)
{
    //在子线程中修改信号处理方式
    if(signal(SIGALRM, signal_func) == SIG_ERR)
    {
        perror("signal");
        exit(1);
    }

    //在子线程中启动第一次计时
    alarm(2);

    for(int i = 0; i < 100; i++)
    {
        printf("%lx thread : i is %d\n", pthread_self(), i);
        sleep(1);
    }
    return (void *)0;

}

int main()
{
    pthread_t p;
    int err;

    //以分离属性启动线程
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    //启动线程
    err = pthread_create(&p, &attr, func, (void*)0 );
    if(err != 0)
    {
        perror("pthread_create");
        exit(1);
    }

    //主线程进入死循环
    while(1)
    {
        sleep(1);
    }

    return 0;
}
