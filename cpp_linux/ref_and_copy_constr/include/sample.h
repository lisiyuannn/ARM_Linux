#ifndef __SAMPLE_H
#define __SAMPLE_H

class Sample
{
//友元函数，可以访问私有成员变量
//friend void func(Sample &obj);

private:
    int num;
public:
    //构造函数
    Sample(int num);
    //拷贝构造函数
    Sample(const Sample& obj);

    int getNum();
};

#endif
