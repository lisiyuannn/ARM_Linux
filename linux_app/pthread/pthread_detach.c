#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//输出线程分离属性函数
void out_state(pthread_attr_t *attr)
{
	int state;
	if(pthread_attr_getdetachstate(attr, &state) != 0)
	{
		perror("getdetachstate");
	}
	else
	{
		if(state == PTHREAD_CREATE_JOINABLE)
		{
			printf("joinable state!\n");
		}
		else if(state == PTHREAD_CREATE_DETACHED)
		{
			printf("detached state!\n");
		}
		else printf("error state!\n");
	}
}


//线程入口函数
void* start_func(void* arg)
{
	long i = (long)arg;
	long sum = 0;
	printf("I am thread: %lx \n", pthread_self());
	for(; i < 100; i++)
	{
		sum += i;
	}
	printf("%lx finished!\n", pthread_self());
	return (void*)sum;
}


int main()
{
	pthread_t joinable_th, detached_th;
	int err;

	//创建线程属性
	pthread_attr_t attr;
	//初始化线程属性
	pthread_attr_init(&attr);
	
	//获取线程属性
	out_state(&attr);
	//创建线程
	err = pthread_create(&joinable_th, &attr, start_func, (void*)1);
	if(err != 0)
	{
		perror("joinable_th create");
		exit(1);
	}

	long res;

	err = pthread_join(joinable_th, (void**)&res);
	if(err != 0)
	{
		perror("joinable join failed!\n");
	}
	else
	{
		printf("res is : %ld\n", res);
	}

	printf("--------------------------------------------------\n");
	
	//更改线程属性
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	//获取线程属性
	out_state(&attr);
	//创建线程
	err = pthread_create(&detached_th, &attr, start_func, (void*)90);
	if(err != 0)
	{
		perror("detached_th create");
		exit(1);
	}

	err = pthread_join(joinable_th, (void**)&res);
	if(err != 0)
	{
		printf("res is : %ld\n", res);
		perror("joinable join failed!\n");
	}
	else
	{
		printf("res is : %ld\n", res);
	}

	printf("main control thread: %lx finished!\n", pthread_self());

	return 0;
}
