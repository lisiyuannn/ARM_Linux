#include <netdb.h>
#include <sys/socket.h>
#include <signal.h>
#include <time.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

/*
 * 实现tcp服务器代码，功能是当客户端建立连接时，返回服务器时间给客户端
 */

#define ADDRLEN (sizeof(struct sockaddr_in))

int sockfd;		//网络标识符

void sig_handler(int signo)
{
	if(signo == SIGINT)
	{
		//执行程序退出程序
		printf("server closed!\n");
		close(sockfd);
		exit(0);
	}
	else
	{
		perror("sig_handler");
		exit(1);
	}
}

//输出网络结构体中包含的网络地址
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

//和客户端进行通信
void do_servers(int fd)
{
	//获得系统时间
	long t = time(0);
	char *s = ctime(&t);
	size_t len = strlen(s)*sizeof(char);
	//将服务器系统时间写回到客户端
	if(write(fd, s, len) != len)
	{
		perror("write");
	}
}



int main(int argc, char* argv[])
{
	//服务器端口号需要通过程序参数输入
	if(argc < 2)
	{
		printf("usage: %s port\n", argv[0]);
		exit;
	}

	//登记信号，当键盘按下ctrl+c时，结束服务器程序运行
	if(signal(SIGINT, sig_handler) == SIG_ERR)
	{
		perror("signel");
		exit(1);
	}

	//程序从这里开始建立连接

	/*
		步骤1：创建套接字
		AF_INET: IPV4
		SOCK_STREAM: tcp协议
	 */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
		exit(1);
	}

	/*
		步骤2：填充IP地址结构体
	 */
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, ADDRLEN);
	serveraddr.sin_family = AF_INET;	//协议族
	serveraddr.sin_port = htons(atoi(argv[1]));		//字符串转整形再转字节序
	serveraddr.sin_addr.s_addr = INADDR_ANY;	//本机所有地址

	/*
		步骤3：绑定ip地址和套接字
	 */
	if(bind(sockfd, (struct sockaddr*)&serveraddr, ADDRLEN) < 0)
	{
		perror("bind");
		exit(2);
	}

	/*
		步骤4：启动listen函数监听
				将接收到的客户端连接请求放置到对应的队列中
				bind函数第二个参数即为队列大小，可以后期修改
	 */
	if(listen(sockfd, 10) < 0)
	{
		perror("listen");
		exit(3);
	}

	/*
		步骤5：调用accept函数从队列中获得一个客户端的连接请求
				首先要指定一个ip结构体用来存放客户端的网络地址信息
				也可以不填这个地址，填NULL即可
				如果连接成功，会返回一个新的描述符
				若没有客户端连接，程序会在accept函数处阻塞
	 */
	struct sockaddr_in clientaddr;
	socklen_t clientaddr_len = ADDRLEN;
	while(1)
	{
		int fd = accept(sockfd, (struct sockaddr*)&clientaddr, &clientaddr_len);
		if(fd < 0)
		{
			perror("accept");
			continue;
		}

		/*
			步骤6：调用IO接口（read/write）和连接的客户端进行通信
		 */
		//输出连接的客户端的地址信息
		out_addr(&clientaddr);
		//通信示例
		do_servers(fd);

		/*
		   步骤7：关闭套接字
		 */
		close(fd);

	}

	/*
		步骤8：关闭服务器套接字
	 */
	//close(sockfd)

	return 0;
}




















