import RPI.GPIO as GPIO
import time

# 设置GPIO模式为BCM
GPIO.setmode(GPIO.BCM)
# 定义按钮引脚
beeper_pin = 21
# 设置按钮引脚为输入模式
GPIO.setup(beeper_pin, GPIO.IN)

old_state = GPIO.input(beeper_pin)

try:
    while True:
        # 读取按钮状态
        button_state = GPIO.input(beeper_pin)

        if old_state != button_state:
            sleep(0.02)
            if old_state!= button_state:
                old_state = button_state
                if button_state == GPIO.HIGH:
                    print("Button pressed")
                else:
                    print("Button released")
except KeyboardInterrupt:
    GPIO.cleanup()