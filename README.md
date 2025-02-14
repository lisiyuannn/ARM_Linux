# 嵌入式系统概述
嵌入式系统是以应用为中心，以计算机技术为基础，且软硬件可裁剪，对功能、可靠性、成本、体积、功耗有严格要求的专用计算机系统。
# Linux基础知识
## 文件权限
### 权限说明
> 示例：drwxr-xr-x 7 siyuan siyuan 4096 Jan 15 13:31 cmake_test
1. 第一个字符 __d__ 表示该文件是个目录，__-__表示普通文件
2. 第二到第十个字符表示文件权限，分为三组，每组三个，第一组'rwx'表示文件所有者的权限；第二组'r-x'表示和文件所有者同组的用户权限；第三组'r-x'表示其他用户的访问权限。'r'表示读权限，'w'表示写权限，'x'代表可执行。
### 修改文件权限
语法：chmod [who] [+|-|=] [mode] 文件名  
参数：
> who：u表示文件的所有者，g表示与文件所有者的同组用户，o表示其他用户，a表示所有用户（默认）
> +|-|=：+表示添加权限，-表示取消权限，=表示赋予给定权限
> mode：r w x    

也可以直接使用数字赋予权限
语法：chmod [数字1][数字2][数字3] 文件名  
> r为4，w为2，x为1  
> 例如 'chmod 721 文件名'   
## 磁盘
### 查看磁盘使用情况
命令 df
## 查看目录大小
## 网络
### 网络配置
### 查看网络状态
## 查找
### 查找文件名
### 查找文件中的字符串
## VIM编辑器的使用
### 功能键
> yy：复制当前光标所在行  
> [n]yy：n为数字，复制当前开始光标开始的n行  
> p：粘贴复制的内容到光标所在行  
> dd：删除光标当前所在行  
> [n]dd：删除光标当前所在行开始的n行  
> /name：查找光标光标之后的名为“name”的字符串  
> G：光标移动到文件尾部，注意是大写  
> u：取消前一个动作，注意是小写  
## Linux系统管理
### TFTP服务安装
## shell
命令解释器，将用户输入的指令转换为相应的机器能够运行的程序
### shell脚本
shell脚本是一个包含一系列命令序列的文本文件。当运行这个脚本文件时，文件中包含的命令序列将得到执行。
1. 脚本的编写，#!/bin/sh表示使用其来解析脚本
2. 以井号开头注释单行文本
3. 使用sh filename.sh来执行脚本
4. 可以通过更改脚本文件的可执行权限，使用./filename.sh来运行脚本程序
5. 变量赋值时，等号的左右两端都不可以有空格，语句结尾不可以加分号
### shell脚本编写
1. 变量：所有的变量都由字符串组成，并且不需要预先对变量进行声明。取变量时需要加上花括号  
```txt
    #!/bin/sh
    #设置变量
    a="hello"
    #打印变量
    echo "a is "
    echo ${a}
```
2. 默认变量：
> \$#：传入脚本的命令行参数个数  
> $*：所有命令行参数值，在各个参数之间留有空格  
> $0：命令本身（shell）文件名  
> $1：第一个命令参数  
> $2：第二个命令参数  

```txt
    #!/bin/sh
    echo "numver of vars："$#
    echo "values of vars: "$*
    echo "values of var1: "$1
    echo "values of var2: "$2
    echo "values of var3: "$3
    echo "values of var4: "$4
```
3. 局部变量：在变量首次被赋值时加上local关键字：local a="hello"
4. if语句
5. 比较
6. 判断
7. for循环
## GDB调试
GDB主要完成下面三个方面的功能
1. 启动被调试程序  
2. 让被调试的程序在指定位置停住  
3. 当程序被停住时可以检查程序的状态  
示例：  
* gcc -g hello.c -o hello 编译时必须加上-g参数来表示编译一个可调试程序  
> 启动GDB：gdb hello  
> 设置断点: b，后面添加行号，也可以添加函数名称，也可以是文件名：行号，还可以是行号if条件
> 运行程序：run  
> 执行一条指令：next(不进入子函数)，step(进入子函数)  
> 连续运行：continue  
> 显示一段程序：list 
> 查看所有设置的断点：info break  
> 删除断点：delete 断点编号  
> 查看变量名：print(变量名)  
> 运行程序，知道当前函数结束：finish  
> 对指定变量进行监控：watch 变量名  
> 退出：quit
## cmake和makefile
### cmake的使用
### makefile的使用
# Linux应用程序编程
## 文件编程
### 使用linux系统调用的方式
* 创建文件
```C++
    //必备头文件
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>

    int create(const char* filename, mode_t mode)
    //filename：要创建的文件名，包含路径
    //mode：创建模式（文件属性，可读可写可执行），使用数字来表示
    //返回文件描述符fd，fd小于0时表示创建失败
```
* 打开文件
```C++
    //必备头文件
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>

    int open(const char* pathname, int flags, mode_t mode)
    //pathname:带路径的文件名
    //flags:打开方式，只读，只写，读写，追加等
    //mode:表示文件的访问方式，也就是当文件不存在时，需要指定文件属性然后创建文件
```
* 关闭文件
```C++
    //必备头文件
    #include <unistd.h>

    close(fd);
```
* 读文件
```C++
    //必备头文件
    #include <unistd.h>

    readsize = open(fd, buff, size);
```
* 写文件
```C++
    //必备头文件
    #include <unistd.h>

    writesize = write(fd, buff, size);
```
* 文件定位
```C++
    //必备头文件
    #include <unistd.h>

    lseek(fd, size, loc);
```
* 访问判断
### 使用c语言库函数的方式
## 时间编程
* 获取日历时间
* 日历时间转化成本地时间
* 日历时间转化成格林威治时间
* 将tm格式的时间转化成字符串
* 将日历时间转化成本地时间，再转化成字符串
* 获取今日凌晨到现在的时间差
* 让程序阻塞睡眠秒或微妙
## 进程
### 进程控制原理
* 进程是一个具有一定独立功能的程序的一次运行活动  
* 特点：
> 动态性 并发 独立 异步  
> 运行 就绪 阻塞  
* 进程ID：标识进程的唯一数字，父进程ID（PPID），启动进程的用户ID（UID）
* 调度算法：  
> 先来先服务  
> 短进程优先
> 高优先级优先  
> 时间片轮转
### 进程控制程序设计
* 头文件和获取进程ID
```c
    #include <sys/types.h>
    #include <unistd.h>
    pid_t getpid(void);     //获取pid
    pid_t getppid(void);    //获取ppid
```
* 创建子进程
```c
    //这里只有一个进程
    pid_t pid = fork();
    //fork在一个进程中执行，但是在两个进程返回，子进程返回0，父进程返回子进程的pid
    //这里有两个进程
    if(pid < 0)
    {
        error();
    }
    else if(pid == 0)
    {
        //子进程执行这里
    }
    else
    {
        //父进程执行这里
    }
```
* fork和vfork
> fork拷贝子进程的数据段，vfork共享子进程的数据段
> fork中子进程和父进程的运行顺序不确定，vfork会先运行子进程，再运行父进程
* exec函数族
* 进程等待
```c
    //阻塞该进程，直到其某个子进程退出
    pid_t wait(int *statu);
```
### 进程的退出
* pid_t wait(int *status); 成功返回子进程id，出错返回-1。等待子进程退出并回收，防止孤儿进程产生。  
* pid_t waitpid(pit_t pid, int *status, int options); 成功返回子进程id，出错返回-1。wait函数的非阻塞版本。opitions参数可以指定是否阻塞等待，参数status可以获得子进程结束的状态。
## 打印错误信息
* errno：errno 是一个全局变量，定义在 <errno.h> 头文件中。当系统调用或库函数执行出错时，会将一个错误码赋值给 errno，不同的错误码代表不同的错误类型。
```c
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main() {
    int fd = open("nonexistent_file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file, errno: %d\n", errno);
    }
    return 0;
}
```

* perror 函数会根据 errno 的值，将对应的错误信息输出到标准错误输出 stderr。参数 s 是一个自定义的字符串，会在错误信息前打印。
```c
#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd = open("nonexistent_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
    }
    return 0;
}
```

* char *strerror(int errnum); strerror 函数接受一个错误码作为参数，返回一个指向描述该错误信息的字符串的指针。与 perror 不同，strerror 不会直接输出错误信息，而是返回错误信息的字符串，方便用户自定义输出格式。
```c
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("nonexistent_file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
    }
    return 0;
}
```

## 管道
### 无名管道
* 用于父进程和子进程之间通信
```c
//头文件
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

//创建管道 pipefd[1]为写端文件描述符
int pipe(int pipefd[2]);    //成功返回0，否则返回-1
//写数据
write(pipefd[1], message, strlen(message));
//读数据
read(pipefd[0], buffer, sizeof(buffer));
```

### 有名管道
* 用于任意两个进程之间进行通信
```c
#include <sys/stat.h>

int mkfifo(const char *pathname, mode_t mode);
//pathname为FIFO文件名
//mode为文件操作属性，例如read，write等，此外还有是否阻塞的标志O_NONBLOCK，使用该参数后如果打开失败，则不阻塞，立即返回
```

## 信号
* 注册信号处理函数：void (*signal(int sig, void (*func)(int)))(int);
* ubuntu发送信号至零：kill

## 共享内存
* 被多个进程共同使用的内存，使用简单，访问快
* 步骤：
> 创建共享内存：int shmget(key_t key, int size, int shmflg)，成功返回共享内存标识符，失败返回-1  
> 映射共享内存：int shmat(int shmid, char *shmaddr, intflg)，成功返回共享内存映射到进程中的地址，失败返回-1  
> 解除地址映射：int shmdt(char* shmaddr)
```c
    //头文件
    #include <sys/shm.h>
    #include <sys/ipc.h>
```

## 消息队列
> 键值
```c
    #include <sys/types.h>
    #include <sys/ipc.h>
    key_t ftok(char* pathname, char proj);
    //pathname为带路径的文件名，proj为项目名称，不为0即可
```
> 打开/创建消息队列
```c
    #include <sys/types.h>
    #include <sys/ipc.h>

    #include <sys/msg.h>
    int msgget(key_t key, int msgflg);
    //返回消息队列描述字，标志位
```
> 向队列中发送消息和接收消息
```c
    int msgsnd(int msqid, struct msgbuf* msgp, int msgsz, int msgflag);
    int msgrcv(int msqid, struct msgbuf* msgp, int msgsz, long mtype, int msgflag);
    //成功读取消息后，这条消息将会被删除
```
> 消息格式
```c
    struct msgbuf
    {
        long mtype; //消息类型，>0
        char mtext[1];  //消息数据的首地址

    }
```