#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define grn_pin 20
#define red_pin 21
#define org_pin 16

void led_low()
{
    digitalWrite(grn_pin, LOW);
    digitalWrite(red_pin, LOW);
    digitalWrite(org_pin, LOW);
}

int main()
{
    if(wiringPiSetup() < 0)
    {
        perror("wiringPiSetup error: ");
        exit(1);
    }

    pinMode(grn_pin, OUTPUT);
    pinMode(red_pin, OUTPUT);
    pinMode(org_pin, OUTPUT);
    while((char ch = getchar()) != 'q')
    {
        switch(ch)
        {
            case '1':
                led_low();
                digitalWrite(grn_pin, HIGH);
                break;
            case '2':
                led_low();
                digitalWrite(red_pin, HIGH);
                break;
            case '3':
                led_low();
                digitalWrite(org_pin, HIGH);
                break;
            case '4':
                led_low();
                break;
            case 'q':
                led_low();
                break;
            default:
                printf("Please input 1, 2, 3, 4, q\n");
                break;
        }
    }

    return 0;
}
