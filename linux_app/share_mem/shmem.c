#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//shmget函数标志，表示共享内存不存在时创建，存在时报错
#define SHM_FLAG IPC_CREAT | IPC_EXCL
#define SHM_SIZE 1024

int main(int argc, char* argv[])
{

	if(argc != 2)
	{
		printf("try again!\n");
		return 0;
	}

	int shmid;
	int pid;
	key_t key;
	char *p_addr, *c_addr;

	if((shmid = shmget(key, SHM_FLAG, SHM_FLAG | 0666)) < 0)
	{
		perror("shmem creat failed!");
		exit(1);
	}

	if((pid = fork()) < 0)
	{
		perror("fork failed!");
		exit(2);
	}
	else if(pid == 0)
	{
		//子进程执行
		sleep(1);
		c_addr = shmat(shmid, NULL, 0);
		printf("child sh_addr : %p\n", (void*)c_addr);
		printf("child get : %s\n", c_addr);
	}
	else
	{
		//父进程执行
		p_addr = shmat(shmid, NULL, 0 );	//参数：共享内存标志，内存地址（0自动分配），标志位
		memset(p_addr, '\0', SHM_SIZE);
		strncpy(p_addr, argv[1], SHM_SIZE);
		printf("father sh_addr : %p\n", (void*)p_addr);
		printf("father send : %s\n", p_addr);
		wait(NULL);
		exit(0);
	}

	return 0;
}
