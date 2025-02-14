#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/msg.h>

#define PATHFILE "./msgbuf"

struct msg_buff
{
    int mtype;
    char data[255];
};

int main()
{
    int msgfd;  //消息队列描述符
    int pid;
    key_t msgkey;
    
    //生成键值
    msgkey = ftok(PATHFILE, 'A');
    printf("key : %x\n", msgkey);
    
    //创建消息队列
    msgfd = msgget(msgkey, IPC_CREAT | 0666);
    if(msgfd < 0)
    {
        perror("msgget failed!");
        exit(1);
    }

    //创建线程
    if((pid = fork()) < 0)
    {
        perror("fork failed!");
        exit(2);
    }
    else if(pid == 0)
    {
        //子进程执行
        sleep(1);
        //开始接收消息
        char buff[255];
        int ret = msgrcv(msgfd, buff, sizeof(buff), 1, IPC_NOWAIT);
        if(ret < 0)
        {
            if(errno == EAGAIN || errno == EWOULDBLOCK)
            {
                printf("暂未收到消息！\n");
                return 0;
            }
            else
            {
                perror("data rec failed!");
                exit(4);
            }
        }

        printf("data get success : %s\n", buff);
    }
    else
    {
        //父进程执行
        //向消息队列中写入数据
        struct msg_buff buff;
        buff.mtype = 1;
        strcpy(buff.data, "hello world");

        int ret = msgsnd(msgfd, &buff, sizeof(buff.data), IPC_NOWAIT);
        if(ret < 0)
        {
            perror("data send failed!");
            exit(3);
        }
        printf("send success: %s\n", buff.data);
        pause();
    }

    return 0;
}