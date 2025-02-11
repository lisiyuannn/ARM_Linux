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
