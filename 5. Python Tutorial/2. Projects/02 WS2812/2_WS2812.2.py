'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 2.2
WS2812
http://www.keyestudio.com
'''
from machine import Pin,I2C
import mecanumCar_v2
import time
import random

#Create a class called mecanumCar for controlling the car
i2c = I2C(0, sda = Pin(20), scl = Pin(21), freq = 400000)
mecanumCar = mecanumCar_v2.Driver(i2c)


#Principal loop function
while True:
    r = random.randint(0, 255) #Take a random number from 0~255
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    for i in range(4):
        mecanumCar.pixels_set(i, (r, g, b)) #The color of the i +1 LED is random(r,g,b)
        mecanumCar.pixels_show() #Refresh display
        time.sleep(0.1) #Wait for a while

