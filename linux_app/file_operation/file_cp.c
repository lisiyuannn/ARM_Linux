#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFSIZE 10

int main(int argc, char *argv[])
{
    int fromFileFd;
    int toFileFd;

    char buff[BUFFSIZE];

    int byteRead;   //读取到的字节数
    int byteWrite;  //成功写入的字节数
    
    //首先检查参数，需要用户输入两个文件名
    if(argc != 3)
    {
        printf("please input fromfile and tofile then try again!\n");
        exit(EXIT_FAILURE);
    }

    //判断被复制的文件是否存在
    if((fromFileFd = open(argv[1], O_RDONLY)) < 0)
    {
        //打开失败，文件不存在
        printf("fromfile is not exit!\n");
        exit(EXIT_FAILURE);
    }

    //打开目标文件时，如果不存在，就创建一个
    if((toFileFd = open(argv[2], O_CREAT | O_RDWR, 0666)) < 0)
    {
        //打开或者创建tofile失败
        printf("tofile open or creat faild!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        //打开成功，开始复制
        while(byteRead = read(fromFileFd, buff, BUFFSIZE))
        {
            if(byteRead == -1)
            {
                //读取失败
                printf("read fromfile faild!\n");
                break;
            }
            else if(byteRead == 0)
            {
                //无数据
                printf("fromfile have no data!\n");
                break;
            }
            else
            {
                //正常读到了数据
                if(byteRead < BUFFSIZE)
                {
                    //表示数据已经全部读出，复制后即可退出循环
                    char*ptr = buff;
                    byteWrite = write(toFileFd, ptr, byteRead);
                    break;
                }
                else
                {
                    //成功读出数据，但是数据还没有复制完，需要进入下一次循环再次复制
                    char*ptr = buff;
                    byteWrite = write(toFileFd, ptr, byteRead);
                }
            }

        }
    }
    close(fromFileFd);
    close(toFileFd);
    return 0;
}
