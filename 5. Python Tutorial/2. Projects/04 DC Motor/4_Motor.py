'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 4
Motor
http://www.keyestudio.com
'''

from machine import Pin,I2C
import mecanumCar_v2
import time

i2c = I2C(0, sda = Pin(20), scl = Pin(21), freq = 400000) #iic0 sda-->20,scl-->21
mecanumCar = mecanumCar_v2.Driver(i2c) #Create an instance for the car

# Principal loop function
while True:
  mecanumCar.Advance()
  time.sleep(2)           #Wait for 2 s
  
  mecanumCar.Back()       #Move back
  time.sleep(2)
  
  mecanumCar.Turn_Left(); #Turn left
  time.sleep(2)

  mecanumCar.Turn_Right() #Turn right
  time.sleep(2)

  mecanumCar.stop();      #Stop
  time.sleep(1)

