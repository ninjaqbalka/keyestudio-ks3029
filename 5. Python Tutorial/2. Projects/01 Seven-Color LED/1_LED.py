'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 1
Color LED
http://www.keyestudio.com
'''
from machine import Pin,I2C
import mecanumCar_v2
import time

i2c = I2C(0, sda = Pin(20), scl = Pin(21), freq = 400000) #iic0 sda-->20,scl-->21
mecanumCar = mecanumCar_v2.Driver(i2c) #Create an instance for the car


# Principal loop function
while True:
    mecanumCar.right_led(1) #Turn on the right seven-color LED
    mecanumCar.left_led(1)  #Turn on the left seven-color LED
    time.sleep(3)           #Delay in 3s
    mecanumCar.right_led(0) #Turn off the right seven-color LED
    mecanumCar.left_led(0)  #Turn off the left seven-color LED
    time.sleep(1)           #Delay in 1s

