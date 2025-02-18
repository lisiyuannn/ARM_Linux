//线程的信号量
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

//使用两个信号量规定三个线程的执行顺序

//定义信号量
sem_t sem1, sem2;

//定义线程入口
void* a_func(void *arg)
{
	sem_wait(&sem1);
	printf("this is a\n");
	return (void*)0;
}

void* b_func(void *arg)
{
	sem_wait(&sem2);
	printf("this is b\n");
	sem_post(&sem1);
	return (void*)0;
}

void* c_func(void *arg)
{
	sem_post(&sem2);
	printf("this is c\n");
	return (void*)0;
}

int main()
{
	pthread_t a, b, c;

	//初始化信号量
	sem_init(&sem1, 0, 0);
	sem_init(&sem2, 0, 0);

	//创建线程
	pthread_create(&a, NULL, a_func, (void*)0);
	pthread_create(&b, NULL, b_func, (void*)0);
	pthread_create(&c, NULL, c_func, (void*)0);

	pthread_join(a, NULL);
	pthread_join(b, NULL);
	pthread_join(c, NULL);

	//销毁信号量
	sem_destroy(&sem1);
	sem_destroy(&sem1);


	return 0;
}
