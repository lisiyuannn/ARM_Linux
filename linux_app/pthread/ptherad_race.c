#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//基本的线程创建
//创建两个线程，看哪个线程先执行完毕

//兔子入口函数
void* rabbit_func(void* arg)
{
	long step = (long)arg;

	for(int i = 1; i <= step; i++)
	{
		printf("%lx rabbit run : %d\n", pthread_self(), i);

		//产生随机数睡眠时间
		int time = (int)(drand48() * 100000);
		//drand48()残生0-1之间的随机数
		usleep(time);
	}
	return (void*)0;
}
//乌龟入口函数
void* turtle_func(void *arg)
{
	long step = (long)arg;

	for(int i = 1; i <= step; i++)
	{
		printf("%lx turtle run : %d\n", pthread_self(), i);	
		//产生随机数睡眠时间
		int time = (int)(drand48() * 100000);
		//drand48()残生0-1之间的随机数
		usleep(time);
	}
	return (void*)0;
}

int main()
{
	//定义线程标识符
	pthread_t rabbit, turtle;
	//存放错误信息
	int err;

	//创建线程
	err = pthread_create(&rabbit, NULL, rabbit_func, (void*)50);
	if(err != 0)
	{
		perror("rabbit thread");
	}

	err = pthread_create(&turtle, NULL, turtle_func, (void*)50);
	if(err != 0)
	{
		perror("turtle thread");
	}

	pthread_join(rabbit, NULL);
	pthread_join(turtle, NULL);
	//主控线程阻塞，等待参数线程运行结束，才继续运行

	printf("control thread id : %lx\n", pthread_self());

	return 0;
}
