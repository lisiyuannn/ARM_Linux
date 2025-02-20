#include <netdb.h>
#include <sys/socket.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>


#define ADDRLEN (sizeof(struct sockaddr_in))

int sockfd;     //全局定义网络标识符

void sig_handler(int signo)
{
    if(signo == SIGINT)
    {
        printf("server closed!\n");
        close(sockfd);
        exit(0);
    }
}

void out_addr(struct sockaddr_in *addr)
{
	//获取端口号
	int port = ntohs(addr->sin_port);		//注意字节序的转换
	//存放ip地址
	char ip[INET_ADDRSTRLEN];
	memset(ip, 0, sizeof(ip));
	inet_ntop(AF_INET, addr, ip, INET_ADDRSTRLEN);
	printf("ipaddr: %s : %d connected\n", ip, port);
}

void do_services(void)
{
    //在这里接收客户端信息，并且返回客户端信息加时间
    struct sockaddr_in clientaddr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[512];
    memset(buffer, 0, sizeof(buffer));

    if(recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientaddr, &len) < 0)
    {
        perror("recvfrom");
    }
    else
    {
        //打印客户端信息，输出接收到的信息
        out_addr(&clientaddr);
        printf(">>>>%s\n", buffer);
        //封装信息返回
        strcat(buffer, "__^_^__");
        long int t = time(0);
        char *time_ptr = ctime(&t);
        strcat(buffer, time_ptr);
        if(sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientaddr, ADDRLEN) < 0)
        {
            perror("write");
            exit(5);
        }
    }
}

int main(int argc, char *argv[])
{
    //从参数设置端口号
    if(argc < 2)
    {
        printf("usage: %s port\n", argv[0]);
        exit(1);
    }

    //登记信号，当程序退出时，清理内存
    if(signal(SIGINT, sig_handler) == SIG_ERR)
    {
        perror("signal");
        exit(1);
    }

    //程序从这里开始建立连接
    
    /*
		步骤1：创建套接字
		AF_INET: IPV4
		SOCK_STREAM: tcp协议
	 */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0)
    {
        perror("socker");
        exit(2);
    }


    /*
		步骤2：填充IP地址结构体
    */
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, ADDRLEN);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[1]));
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    /*
		步骤3：绑定ip地址和套接字
	 */
    if(bind(sockfd, (struct sockaddr*)&serveraddr, ADDRLEN) < 0)
    {
        perror("bind");
        exit(3);
    }

    /*
			步骤6：调用IO接口（read/write）和连接的客户端进行通信
	 */
    while(1)
    {
        do_services();
    }


    return 0;
}





























