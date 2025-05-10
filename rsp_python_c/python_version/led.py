'''
使用python编写代码点亮led小灯

控制模块思路
2. 根据要求设置引脚状态
3. 功能结束后要重置引脚
'''
# 根据输入的数字设置灯的点亮和关闭

import RPI.GPIO as GPIO

grn_pin = 20  # 绿灯引脚
red_pin = 21  # 红灯引脚
org_pin = 16  # 黄灯引脚
led = (red_pin, grn_pin, org_pin)

# 设置gpio模式
GPIO.setmode(GPIO.BCM)

# 设置引脚为输出模式，并且设置为低电平
GPIO.setup(led, GPIO.OUT, initial=GPIO.LOW)

while True:
    # 获取用户输入
    user_input = input("\n用户: 1. 绿灯；2. 红灯；3. 黄灯；0：退出。\n")
    if user_input == "1":
        # 先关闭所有灯
        GPIO.output(led, GPIO.LOW)
        # 再点亮绿灯
        GPIO.output(grn_pin, GPIO.HIGH)
    elif user_input == "2":
        # 先关闭所有灯
        GPIO.output(led, GPIO.LOW)
        # 再点亮红灯
        GPIO.output(red_pin, GPIO.HIGH)
    elif user_input == "3":
        # 先关闭所有灯
        GPIO.output(led, GPIO.LOW)
        # 再点亮黄灯
        GPIO.output(org_pin, GPIO.HIGH)
    elif user_input == "0":
        break
    else:
        print("输入错误，请重新输入！")

# 重置引脚
GPIO.cleanup()