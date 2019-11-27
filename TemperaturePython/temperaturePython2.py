# -*- coding: utf-8 -*-
"""
Created on Sun Oct  6 20:00:46 2019

@author: admin
"""

import serial
ser = serial.Serial('COM4', 9600)

while 1:
    msg = ser.readline()
    print(msg.decode('utf-8'))
    
    
    
