'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 8
Ultrasonic follow Robot
http://www.keyestudio.com
'''
from machine import Pin,I2C
import mecanumCar_v2
import time

i2c = I2C(0, sda = Pin(20), scl = Pin(21), freq = 400000) #iic0 sda-->20,scl-->21
mecanumCar = mecanumCar_v2.Driver(i2c) #Create an instance for the car

while True:
    distance = mecanumCar.get_distance()
    if distance <= 15:
        mecanumCar.Back()
    elif distance <= 25:
        mecanumCar.stop()
    elif distance <= 45:
        mecanumCar.Advance()
    else:
        mecanumCar.stop()


