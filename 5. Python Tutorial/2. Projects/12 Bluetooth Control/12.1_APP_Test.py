'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 12.1
APP Test
http://www.keyestudio.com
'''

from machine import Pin,UART,I2C
import mecanumCar_v2
import time

i2c = I2C(0, sda = Pin(20), scl = Pin(21), freq = 400000) #iic0 sda-->20,scl-->21
mecanumCar = mecanumCar_v2.Driver(i2c) #Create a driver class instance for the car

#Set Bluetooth serial port baud rate to 9600,8 data bits, no parity bit and 1 stop bit ，tx-->GPIO0,rx-->GPIO1
uart = UART(0,baudrate = 9600,bits = 8,parity = None,stop = 1,tx = machine.Pin(0),rx = machine.Pin(1))
buf=bytearray(6) #Define a serial port receive buffer


# Principal loop function
while True:
    if uart.any():
        uart.readinto(buf)
        #print(buf.decode())
        ble_val = chr(buf[0]) #Print the first character received
        print(ble_val)