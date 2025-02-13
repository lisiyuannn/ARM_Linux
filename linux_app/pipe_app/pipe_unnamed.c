#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	int pipefd[2];		//创建管道描述符
	char message[] = {"hello world"};	//写数据
	char buffer[100];	//读数据缓存
	pid_t pid;

	if(pipe(pipefd) < 0)
	{
		exit(-1);
	}

	if((pid = fork()) < 0)
	{
		printf("fork faild!");
		exit(-1);
	}
	else if(pid == 0)
	{
		//子进程执行  读数据
		close(pipefd[1]);
		sleep(3);
		read(pipefd[0], buffer, sizeof(buffer));
		printf("child process : %s\n", buffer);
		close(pipefd[0]);
	}
	else
	{
		//父进程执行  写数据
		close(pipefd[0]);
		write(pipefd[1], message, strlen(message));
		printf("father process write done : %s\n", message);
		close(pipefd[1]);
		waitpid(pid, NULL, 0);
	}

	return 0;
}
