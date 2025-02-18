#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*启动两个线程，一个线程计算，一个线程获取计算后的值，利用条件变量技术保证线程同步*/

//定义资源结构体
typedef struct
{
	int res;
	int is_wait;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
}Result;

//定义计算线程入口函数
void * cal_fn(void *arg)
{
	Result *r = (Result *)arg;

	int i = 1, sum = 0;

	//先计算
	for(; i < 100; i++)
	{
		sum += i;
	}

	pthread_mutex_lock(&r->mutex);
	//答案放进去
	r->res = sum;
	pthread_mutex_unlock(&r->mutex);

	//检查获取线程有没有准备好
	pthread_mutex_lock(&r->mutex);
	while(!r->is_wait)
	{
		pthread_mutex_unlock(&r->mutex);
		usleep(1000);
		pthread_mutex_lock(&r->mutex);
	}
	pthread_mutex_unlock(&r->mutex);
	
	//通知获取线程可以工作了
	pthread_cond_signal(&r->cond);
	// pthread_cond_broadcast(&r->cond);

}

//定义获取线程入口函数
void * get_fn(void *arg)
{
	Result *r = (Result *)arg;

	pthread_mutex_lock(&r->mutex);

	//将is_wait置1，标识已经准备好读数据
	r->is_wait = 1;
	//进入等待队列
	pthread_cond_wait(&r->cond, &r->mutex);

	printf("Result is %d\n", r->res);

	pthread_mutex_unlock(&r->mutex);

}

int main()
{
	int err;
	pthread_t get, cal;

	//初始化结构体
	Result r;
	r.is_wait = 0;

	//初始化互斥锁和条件变量
	pthread_mutex_init(&r.mutex, NULL);
	pthread_cond_init(&r.cond, NULL);

	//创建线程
	err = pthread_create(&get, NULL, get_fn, (void*)&r);
	if(err != 0)
	{
		perror("get pthread_create");
		exit(1);
	}

	err = pthread_create(&cal, NULL, cal_fn, (void*)&r);
	if(err != 0)
	{
		perror("cal pthread_create");
		exit(1);
	}

	pthread_join(cal, NULL);
	pthread_join(get, NULL);

	pthread_mutex_destroy(&r.mutex);
	pthread_cond_destroy(&r.cond);

	return 0;
}
