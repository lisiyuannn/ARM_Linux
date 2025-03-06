#include <wiringPi.h>
#include <stdio.h>

/**
 * 中断和按键消抖问题
 */

int pin;
int state = 0;
/**
 * 中断处理函数
 * 如果不是one shot函数，如何处理多次触发的堆积问题
 */
void toggle(void)
{
    if(state == digitalRead(pin)) return;
    state = digitalRead(pin);
    delay(30);
    if(state == digitalRead(pin))
    {
        if(state == HIGH) printf("按下\n");
        else printf("松开\n");
    }
    else{
        //抖动
        state = !state;
    }
}

int main(int argc, char const *argv[])
{
    /*1. 初始化GPIO*/
    wiringPiSetupGpio();

    /*2. 23号引脚输入*/
    pin = 23;
    pinMode(pin, INPUT);

    /*3. 登记中断*/
    wiringPiISR(pin, INT_EDGE_BOTH, toggle);

    return 0;
}

