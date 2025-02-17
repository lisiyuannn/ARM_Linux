#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct{
	char name[20];
	int time;
	int start;
	int end;
}Race_Arg;

//定义线程清理函数
void clean_func(void * arg)
{
    char *s = (char*)arg;
    printf("clean func: %s\n", s);
}

void *func(void* arg)
{
	Race_Arg *ra_arg = (Race_Arg *)arg;
    int execute = ra_arg->start;

    //压入线程清理函数
    pthread_cleanup_push(clean_func, "first clean func");
    pthread_cleanup_push(clean_func, "second clean func");

	for(int i = ra_arg->start; i <= ra_arg->end; i++)
	{
		printf("%lx %s thread : %d\n", pthread_self(), ra_arg->name, i);
		usleep(ra_arg->time);
	}

    pthread_cleanup_pop(execute);
    pthread_cleanup_pop(execute);

	return (void*)ra_arg;
}

int main()
{
	pthread_t rabbit, turtle;
	int err;

	//设置两个线程的参数
	Race_Arg ra_arg = {"rabbit", (int)(drand48()*10000000), 30, 60};
	Race_Arg tu_arg = {"turtle", (int)(drand48()*9000000), 0, 60};
	
	//创建线程
	err = pthread_create(&rabbit, NULL, func, (void*)(&ra_arg));
	if(err != 0)
	{
		perror("rabbit thread");
		exit(1);
	}

	err = pthread_create(&turtle, NULL, func, (void*)(&tu_arg));
	if(err != 0)
	{
		perror("turtle thread");
		exit(1);
	}

	Race_Arg *res1;
	long res2;

	pthread_join(rabbit, (void**)&res1);
	pthread_join(turtle, (void**)&res2);

	printf("%s\n", res1->name);
	printf("%s\n", ((Race_Arg*)res2)->name);

	printf("control thread id: %lx\n", pthread_self());
	return 0;
}
