#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

//pv操作
//等待操作，也就是获取信号量
void sem_wait(int semid)
{
    //定义操作结构体
    struct sembuf opbuff = {0, -1, 0};      //信号量编号，获取信号量，semflg
    if((semop(semid, &opbuff, 1)) < 0)          //最后一个参数为操作的信号量个数
    {
        perror("semop");
        exit(2);
    }
}

//发送操作，也就是释放信号量
void sem_signal(int semid)
{
    //定义操作结构体
    struct sembuf opbuff = {0, 1, 0};      //信号量编号，获取信号量，semflg
    if((semop(semid, &opbuff, 1)) < 0)          //最后一个参数为操作的信号量个数
    {
        perror("semop");
        exit(2);
    }
}

int main()
{
    key_t key;
    int semid;
    pid_t pid;

    //生成键
    key = ftok("./semfile", 1);

    //创建信号量
    //这里的1表示创建1个信号量
    semid = semget(key, 1, IPC_CREAT | 0666);
    if(semid == -1)
    {
        perror("semget");
        exit(1);
    }

    //初始化信号量
    //这里的1表示信号量的初始值为1
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl SETVAL failed");
        exit(EXIT_FAILURE);
    }

    //创建进程
    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(2);
    }
    else if(pid == 0)
    {
        //子进程执行
        sleep(1);
        printf("Child: Trying to acquire the semaphore...\n");
        sem_wait(semid);  // P 操作
        printf("Child: Semaphore acquired!\n");

        // 模拟子进程使用共享资源
        sleep(2);

        printf("Child: Releasing the semaphore...\n");
        sem_signal(semid);  // V 操作
        printf("Child: Semaphore released.\n");
    }
    else
    {
        //父进程执行
        printf("Parent: Trying to acquire the semaphore...\n");
        sem_wait(semid);  // P 操作
        printf("Parent: Semaphore acquired!\n");

        // 模拟父进程使用共享资源
        sleep(2);

        printf("Parent: Releasing the semaphore...\n");
        sem_signal(semid);  // V 操作
        printf("Parent: Semaphore released.\n");

        wait(NULL);

        //删除信号量
        semctl(semid, 0, IPC_RMID);
    }


    return 0;
}


