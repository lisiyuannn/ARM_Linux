#include <netdb.h>
#include <sys/socket.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define ADDRLEN (sizeof(struct sockaddr_in))

int main(int argc, char* argv[])
{
    //用户需要输入想要连接的服务器网络信息
    if(argc < 3)
    {
        printf("usage: %s ip port\n", argv[0]);
        exit(1);
    }

    /*
        步骤1：创建套接字
    */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
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
        步骤4：调用IO函数（read/write）和服务器进行双向通信
    */
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    size_t size;
    if((size = read(sockfd, buffer, sizeof(buffer))) < 0)
    {
        perror("read");
        exit(1);
    }
    if(write(STDOUT_FILENO, buffer, size) != size)
    {
        perror("write");
        exit(1);
    }

    /*
        步骤5：关闭套接字
    */
    close(sockfd);

    return 0;
}
