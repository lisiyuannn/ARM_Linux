#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO "./myfifo"
#define MSGSIZE 100

int main()
{
	//写数据进程
	char message[MSGSIZE];
	int pipefd;

	//无需创建，需要打开一个已有管道
	if((pipefd = open(FIFO, O_WRONLY)) < 0)
	{
		perror("fifo open failed!");
		exit(1);
	}

	while(fgets(message, sizeof(message), stdin))
	{
		//一直写数据
		if(write(pipefd, message, strlen(message)) < 0)
		{
			perror("write data failed!");
			exit(2);
		}

	}

	return 0;
	
}
