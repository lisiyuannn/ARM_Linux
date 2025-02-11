#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[])
{
	FILE *fromfile, *tofile;
	char *buff[BUFFSIZE];
	int readsize, writesize;

	//首先判断参数输入是否正确
	if(argc != 3)
	{
		printf("please input fromfile and tofile then try again!\n");
		exit(EXIT_FAILURE);
	}
	//尝试打开拷贝源文件
	if((fromfile = fopen(argv[1], "r")) == NULL)	//只读方式打开
	{
		//打开失败
		printf("fromfile open failed!\n");
		exit(EXIT_FAILURE);
	}

	//尝试打开拷贝目标文件，如果目标文件不存在，就创建目标文件
	if((tofile = fopen(argv[2], "a")) == NULL)	//追加写入
	{
		printf("tofile open or creat failed!\n");
	}
	else
	{
		//文件都打开成功，可以准备写入
		while(readsize = fread(buff, 1, BUFFSIZE, fromfile))
		{
			if(readsize < 0)
			{
				//读取失败
				printf("fromfile read failed!\n");
				exit(EXIT_FAILURE);
			}
			else if(readsize < BUFFSIZE)
			{
				//已经全部读取完毕，准备写入
				if((writesize = fwrite(buff, 1, readsize, tofile)) != readsize)
				{
					printf("data write failed!\n");
					exit(EXIT_FAILURE);
				}
				break;
			}
			else
			{
				//文件还没有读取完毕，先写入一部分
				if((writesize = fwrite(buff, 1, readsize, tofile)) != readsize)
				{
					printf("data write failed!\n");
					exit(EXIT_FAILURE);
				}
				//不要break，下次循环接着写	
			}
		}
	}
	fclose(fromfile);
	fclose(tofile);
	return 0;
}
