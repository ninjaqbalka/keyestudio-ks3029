'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 9
Ultrasonic obstacle avoidance Robot
http://www.keyestudio.com
'''

from machine import Pin,I2C
import mecanumCar_v2
import time

i2c = I2C(0, sda = Pin(20), scl = Pin(21), freq = 400000) #iic0 sda-->20,scl-->21
mecanumCar = mecanumCar_v2.Driver(i2c) #Create a driver instance for the car

mecanumCar.set_angle(90)
time.sleep(0.5)
while True:
    distance = mecanumCar.get_distance()
    if distance <= 15:
        mecanumCar.stop()
        time.sleep(0.5)
        mecanumCar.set_angle(180)
        time.sleep(0.5)
        l_distance = mecanumCar.get_distance()
        time.sleep(0.1)
        mecanumCar.set_angle(0)
        time.sleep(0.5)
        r_distance = mecanumCar.get_distance()
        time.sleep(0.1)
        mecanumCar.set_angle(90)
        time.sleep(0.5)
        if l_distance > r_distance:
            mecanumCar.Turn_Left()
            time.sleep(0.3)
        else:
            mecanumCar.Turn_Right()
            time.sleep(0.3)
    else:
        mecanumCar.Advance()
