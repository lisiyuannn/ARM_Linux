#ifndef __SINGLETONE_H
#define __SINGLETONE_H

class Singletone
{
private:
    //单例类的唯一实例
    static Singletone* instance;
    //构造函数私有化
    Singletone();
    //删除拷贝构造函数
    Singletone(const Singletone &other) = delete;
    //删除赋值运算符
    Singletone &operator=(const Singletone &other) = delete;
public:
    //获取单例实例的静态方法
    static Singletone * getInstance(void);
};   

#endif
