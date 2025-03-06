/**
 * 使用软件模拟pwm
 */

#include "wiringPi.h"
#include <iostream>
#include <pthread.h>

class Pwm
{
private:
    int pin;
    int freq;
    int dutyCycle;
    bool pwmFlag;
public:
    Pwm(int pin, int freq = 100, int dutyCycle = 50)
        :pin(pin), freq(freq), dutyCycle(dutyCycle), pwmFlag(false)
    {
        //频率调整
        if(freq < 0) freq = 1;
        else if(freq > 100) freq = 100;

        //占空比调整
        if(dutyCycle < 0) dutyCycle = 0;
        else if(dutyCycle > 100) dutyCycle = 100;

        //设置引脚
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    setFreq(int freq) {this->freq = freq;}
    setDutyCycle(int dutyCycle) {this->dutyCycle = dutyCycle;}

    void startPwm()
    {
        /* 启动子线程来发射pwm脉冲 */
        //设置线程属性
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

        pwmFlag = true;
        //开启线程
        pthread_t pid;
        pthread_create(&pid, &attr, pwmPthread, this);

    }

    void stopPwm()
    {
        pwmFlag = false;
    }

    /* pwm线程调用函数,static函数属于类而不属于线程 */
    static void* pwmPthread(void* arg)
    {
        while(pwmFlag)
        {
            /* 执行pwm发射程序 */
        }
    }
};


int main(int argc, char const *argv[])
{
/* code */
return 0;
}
 