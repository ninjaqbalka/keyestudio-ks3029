'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 7
Ultrasonic sensor
http://www.keyestudio.com
'''

from machine import Pin,I2C
import mecanumCar_v2
import time

i2c = I2C(0, sda = Pin(20), scl = Pin(21), freq = 400000)
mecanumCar = mecanumCar_v2.Driver(i2c) 

while True:
    distance = mecanumCar.get_distance()
    print("distance is : {} cm".format(distance))
    time.sleep_ms(100)

