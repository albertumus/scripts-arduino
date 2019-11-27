# -*- coding: utf-8 -*-
"""
Created on Thu Sep  5 19:23:41 2019

@author: admin
"""
from pyfirmata import Arduino, util
import time

board = Arduino('COM4')

iterator = util.Iterator(board)
iterator.start()

temperature = board.get_pin('a:0:i')

time.sleep(2)

print((temperature.read()*5000.0-500.0) /10.0)

board.exit()
