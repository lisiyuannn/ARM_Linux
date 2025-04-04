#include <netdb.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <signal.h>
#include <time.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define ADDRLEN (sizeof(struct sockaddr_in))
#define BUFF_LEN 512

int sockfd;

void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		//执行程序退出程序
		printf("client closed!\n");
		close(sockfd);
		exit(0);
	}
	else if(signo =- SIGCHLD)
	{
		//回收子进程资源
		printf("client closed!\n");
		wait(0);
	}
	else
	{
		perror("sig_handler");
		exit(1);
	}
}


int main(int argc, char* argv[])
{
    //用户需要输入想要连接的服务器网络信息
    if(argc < 3)
    {
        printf("usage: %s ip port\n", argv[0]);
        exit(1);
    }

	//登记信号，当键盘按下ctrl+c时，结束服务器程序运行
	if(signal(SIGINT, sig_handler) == SIG_ERR)
	{
		perror("SIGINT signal error");
		exit(1);
	}

    /*
        步骤1：创建套接字
    */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    /*
        步骤2：填充服务器网络地址结构体
    */
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    //将点分十进制ip地址字符串转换为网络字节序
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    /*
        步骤3：调用connect函数尝试连接服务器
    */
    if(connect(sockfd, (struct sockaddr*)&serveraddr, ADDRLEN) < 0)
    {
        perror("connect");
        exit(1);
    }

    /*
        步骤4：反复调用IO函数（read/write）和服务器进行双向通信
    */
    //注意当数组名作为参数传递时会退化成指针
    char buffer[BUFF_LEN];
	size_t size;
	while(1)
	{
		memset(buffer, 0, BUFF_LEN);
		//先写后读
		//从键盘输入字符串
		if(fgets(buffer, BUFF_LEN, stdin) == NULL)
		{
			//键盘输入失败
			continue;
		}
		else
		{
			//键盘输入成功，发送给服务器并等待接收
			if(size = write(sockfd, buffer, BUFF_LEN) < 0)
			{
				//与服务器断开连接
				if(errno == EPIPE)
				{
					perror("write");
					break;
				}
			}
			else
			{
				//发送成功，等待接收
				if((size = read(sockfd, buffer, BUFF_LEN)) < 0)
				{
					perror("read");
					continue;
				}
				else if(size == 0)
				{
					//服务器断开了连接
					break;
				}
				else
				{
					//打印出读到的数据
					printf("%s\n", buffer);
				}
			}
		}
	}

    /*
        步骤5：关闭套接字
    */
    close(sockfd);

    return 0;
}
