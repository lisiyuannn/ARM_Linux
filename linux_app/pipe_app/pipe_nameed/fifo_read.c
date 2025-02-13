#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO "./myfifo"
#define BUFFSIZE 100

int main()
{
	//读进程
	char buffer[100];	//存放读取到的数据
	int pipefd;
	int nread;		//存放读取了多少数据
	
	memset(buffer, 0, sizeof(buffer));

	//创建管道
	if(mkfifo(FIFO, 0666) < 0)
	{
		perror("can not creat fifo");
		exit(1);
	}

	//打开管道
	pipefd = open(FIFO, O_RDONLY | O_NONBLOCK);
	if(pipefd < 0)
	{
		perror("fifo open faild");
		exit(2);
	}

	//循环读取数据
	while(1)
	{
		memset(buffer, 0, BUFFSIZE);
		if((nread = read(pipefd, buffer, 100)) == -1)
		{
			if(errno == EAGAIN || errno == EWOULDBLOCK)
			{
				printf("no data\n");
			}
			else
			{
				perror("read faild");
				exit(3);
			}
		}
		else if(nread == 0)
		{
			printf("no data\n");
		}
		else
		{
			printf("read success: %s\n", buffer);
		}

		sleep(1);
	}
	pause();
	return 0;
}
