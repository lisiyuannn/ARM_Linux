#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*读者和写者问题，读线程反复读数据，写线程反复写数据，注意线程同步*/

typedef struct reader_writer
{
    int data;

    int writer_wait;
    int reader_wait;

    pthread_mutex_t w_mutex;
    pthread_cond_t w_cond;
    pthread_mutex_t r_mutex;
    pthread_cond_t r_cond;
}Source;


//定义写数据函数
void write_data(Source* s, int value)
{
    s->data = value;
}

//定义读函数
int read_data(Source* s)
{
    return s->data;
}

//定义写线程入口函数
void* w_fn(void *arg)
{
    Source *s = (Source*)arg;

    //开始写数据
    int i = 1;
    for(; i < 100; i++)
    {
        //先写数据
        s->data = i+100;
        printf("writer is write done : %d\n", s->data);
        //判断是否已经有读线程准备好了
        pthread_mutex_lock(&s->r_mutex);
        while(!s->reader_wait)
        {
            pthread_mutex_unlock(&s->r_mutex);
            sleep(1);
            pthread_mutex_lock(&s->r_mutex);
        }
        //程序到这里说明已经有读线程准备好了，唤醒他
        s->reader_wait = 0;
        pthread_cond_broadcast(&s->r_cond);
        pthread_mutex_unlock(&s->r_mutex);
        //自己进入等待队列
        pthread_mutex_lock(&s->w_mutex);
        s->writer_wait = 1;
        pthread_cond_wait(&s->w_cond, &s->w_mutex);
        pthread_mutex_unlock(&s->w_mutex);

    }
}

//定义读线程入口函数
void* r_fn(void* arg)
{
    Source *s = (Source*)arg;
    int i = 1;

    for(; i < 100; i++)
    {

        //先拿锁，进入等待队列，表示自己已经准备好读数据
        pthread_mutex_lock(&s->r_mutex);
        s->reader_wait = 1;
        pthread_cond_wait(&s->r_cond, &s->r_mutex);
        pthread_mutex_unlock(&s->r_mutex);

        //程序走到这里说明已经被唤醒，读数据
        printf("reader read data : %d\n", read_data(s));

        //判断写者是否已经进入等待队列
        pthread_mutex_lock(&s->w_mutex);
        while(!s->writer_wait)
        {
            //还没有进入，等待
            pthread_mutex_unlock(&s->w_mutex);
            sleep(1);
            pthread_mutex_lock(&s->w_mutex);
        }

        //程序走到这里，说明写这已经进入等待队列，唤醒她
        s->writer_wait = 0;
        pthread_cond_broadcast(&s->w_cond);
        pthread_mutex_unlock(&s->w_mutex);    
    }
}


int main()
{
    int err;
    pthread_t writer, reader;

    Source s;
    s.writer_wait = 0;
    s.reader_wait = 0;

    //初始化互斥锁和条件变量
    pthread_mutex_init(&s.r_mutex, NULL);
    pthread_cond_init(&s.r_cond, NULL);
    pthread_mutex_init(&s.w_mutex, NULL);
    pthread_cond_init(&s.w_cond, NULL);

    //启动线程
    err = pthread_create(&writer, NULL, w_fn, (void*)&s);
    if(err != 0)
    {
        perror("writer pthread_create");
        exit(1);
    }

    err = pthread_create(&reader, NULL, r_fn, (void*)&s);
    if(err != 0)
    {
        perror("reader pthread_create");
        exit(1);
    }

    //等待线程结束
    pthread_join(writer, NULL);
    pthread_join(reader, NULL);

    //销毁互斥锁和条件变量
    pthread_mutex_destroy(&s.r_mutex);
    pthread_cond_destroy(&s.r_cond);
    pthread_mutex_destroy(&s.w_mutex);
    pthread_cond_destroy(&s.w_cond);

}