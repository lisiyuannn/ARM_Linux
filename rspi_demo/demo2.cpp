/**
 * 使用软件模拟pwm
 */

#include "wiringPi.h"
#include <iostream>
#include <pthread.h>
#include <unistd.h>

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

    void setFreq(int freq) {this->freq = freq;}
    void setDutyCycle(int dutyCycle) {this->dutyCycle = dutyCycle;}

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
        //参数
        Pwm* pwm = (Pwm*)arg;

        while(pwm->pwmFlag)
        {
            /**
             * 根据频率和占空比计算高电平和低电平的持续时间
             * 高电平持续时间 = 1000000 / hz * x / 100
             * 低电平持续时间 = 1000000 / hz * (100-x) / 100
             */

            /* 执行pwm发射程序 */
            digitalWrite(pwm->pin, HIGH);     //高电平
            usleep(10000/pwm->freq*pwm->dutyCycle);   //睡眠一段时间
            digitalWrite(pwm->pin, LOW);     //低电平
            usleep(10000/pwm->freq*(100-pwm->dutyCycle));
        }
        return (void*)0;
    }
};


int main(int argc, char const *argv[])
{
/* code */
    wiringPiSetupGpio();

    Pwm pwm1(18);
    pwm1.startPwm();
    sleep(5);
    pwm1.stopPwm();

    while(1){};
    return 0;
}
 