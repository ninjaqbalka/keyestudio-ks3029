'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 3
Servo
http://www.keyestudio.com
'''
from machine import Pin,I2C
import mecanumCar_v2
import time

i2c = I2C(0, sda = Pin(20), scl = Pin(21), freq = 400000)
#print("STC8G1K08 address：", machine.I2C.scan(i2c))
mecanumCar = mecanumCar_v2.Driver(i2c)

mecanumCar.set_angle(90) #Rotate to 90 degrees
time.sleep(1)

# Principal loop function
while True:
    for i in range(180):
        mecanumCar.set_angle(i) #Rotate from 0 to 180 degrees  
        time.sleep_ms(20) #Wait for a while
    for i in range(180):
        mecanumCar.set_angle(180-i) #Rotate from 180 to 0 degrees
        time.sleep_ms(20) #Wait for a while