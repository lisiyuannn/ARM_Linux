import RPi.GPIO as GPIO
import time


# 设置GPIO模式为BCM
GPIO.setmode(GPIO.BCM)
# 定义蜂鸣器引脚
beeper_pin = 21
# 设置蜂鸣器引脚为输出模式
GPIO.setup(beeper_pin, GPIO.IN)

try:
    while True:
        # 响
        GPIO.output(beeper_pin, GPIO.HIGH)
        time.sleep(0.05)
        # 停
        GPIO.output(beeper_pin, GPIO.LOW)
        time.sleep(0.5)
except KeyboardInterrupt:
    GPIO.cleanup()
