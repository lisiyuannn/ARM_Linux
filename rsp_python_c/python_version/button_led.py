import RPi.GPIO as GPIO
import time

button = 21
beep = 20

GPIO.setmode(GPIO.BCM)
# 设置按键引脚为输入模式
GPIO.setup(button, GPIO.IN)
# 设置LED引脚为输出模式
GPIO.setup(beep, GPIO.OUT, initial=GPIO.LOW)

button_flag = GPIO.LOW # 按键标志位

try:
    while True:
        # 读取按键状态
        button_state = GPIO.input(button)
        # 如果按键状态发生变化
        if button_state == GPIO.LOW: # 按键按下
            time.sleep(0.02)    # 延时去抖动
            if button_state == GPIO.LOW: # 再次确认按键按下

                while button_state == GPIO.LOW: # 等待按键释放
                    button_state = GPIO.input(button)
                    time.sleep(0.02)
                    button_flag = not button_flag # 切换按键标志位
                
                if button_flag == GPIO.HIGH: # 如果按键标志位为高
                    GPIO.output(beep, GPIO.HIGH) # 打开
                else:
                    GPIO.output(beep, GPIO.LOW) # 关闭
except KeyboardInterrupt:
    GPIO.cleanup()