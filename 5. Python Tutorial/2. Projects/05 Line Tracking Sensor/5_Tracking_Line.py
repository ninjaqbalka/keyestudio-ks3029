'''
Keyestudio 4WD Mecanum Robot for Pico
lesson 5
Line Tracking Sensor
http://www.keyestudio.com
'''

from machine import Pin
import time

l_pin = Pin(16, Pin.IN)
m_pin = Pin(17, Pin.IN)
r_pin = Pin(18, Pin.IN)


while True:
    l_val = l_pin.value() #Read the value of the left line tracking sensor
    m_val = m_pin.value() #Read the value of the middle line tracking sensor
    r_val = r_pin.value() #Read the value of the right line tracking sensor
    print(l_val, end = ' ')
    print(m_val, end = ' ')
    print(r_val)
    time.sleep_ms(100)