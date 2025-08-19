'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 2.1
WS2812
http://www.keyestudio.com
'''
from machine import Pin,I2C
import mecanumCar_v2
import time

#Create a class called mecanumCar for controlling the car
i2c = I2C(0, sda = Pin(20), scl = Pin(21), freq = 400000)
mecanumCar = mecanumCar_v2.Driver(i2c)

mecanumCar.pixels_set(0, (255, 0, 0))
mecanumCar.pixels_set(1, (0, 255, 0))
mecanumCar.pixels_set(2, (0, 0, 255))
mecanumCar.pixels_set(3, (255, 255, 255))
mecanumCar.pixels_show()

