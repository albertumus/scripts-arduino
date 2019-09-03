# -*- coding: utf-8 -*-
"""
Created on Tue Aug 27 17:12:02 2019

@author: admin
"""

from pyfirmata import Arduino, util
import time

board = Arduino('COM4')

iterator = util.Iterator(board)
iterator.start()

Tv1 = board.get_pin('d:2:i')
Tv1.write(1)

time.sleep(30)

board.exit()