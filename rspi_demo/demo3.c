/**
 * 使用pwm硬件
 */

#include <wiringPi.h>

/**
 * 平衡模式
 * 平衡模式则是通过在一个周期内分散高电平脉冲的方式来实现不同的占空比
 * 而不是像标记空间模式那样集中一个连续的高电平。并且在平衡模式下，
 * PWM 的频率会根据占空比自动调整。
 */
// int main(int argc, char const *argv[])
// {
//     wiringPiSetupGpio();

//     //硬件pwm只能使用18号引脚
//     int pin = 18;

//     //默认为balance模式，分频32， 19200 / 32 = 600khz，默认range 1024
//     pinMode(pin, PWM_OUTPUT);

//     pwmWrite(pin, 1024 / 2);        //占空比百分之50，频率600/2 = 300khz


// return 0;
// }


/**
 * 在标记空间模式下，
 * PWM 信号的周期是固定的，
 * 通过改变高电平（标记）的持续时间来调整占空比。
 */
int main(int argc, char const *argv[])
{
    wiringPiSetupGpio();

    int pin = 18;
    pinMode(pin, PWM_OUTPUT);

    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(192);       //设置分频，结果为100khz
    pwmSetRange(2000);      //设置总计数range
    pwmWrite(pin, 500);     //设置value，占空比为value/range
    return 0;
}
