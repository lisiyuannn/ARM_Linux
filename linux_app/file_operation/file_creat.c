#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void file_creat(char* filename)
{
    //指定文件权限，0755中0为占位符，可忽略，755分别表示三个用户的属性
   if(creat(filename, 0666) < 0)
   {
        //创建失败
        printf("file create failed!\n");
        return;
   }
   else
   {
        //创建成功
        printf("file create success!\n");
        return;
   }
}

int main(int argc, char *argv[])
{
    //首先判断程序执行时有没有输入想要创建的文件名称
    if(argc < 2)
    {
        //参数不足，应用程序名算第一个参数
        printf("You haven`t input the filename, please try angin!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for(int i = 1; i < argc; i++)
        {
            file_creat(argv[i]);
        }
    }

    //打开文件
    int fd;     //文件描述符
    char* openname = "test.txt";
    fd = open(openname, O_RDWR);
    if(fd < 0)
    {
        printf("open file faild!\n");
    }
    else
    {
        printf("open file success!\n");
    }
    close(fd);
    return 0;
}
