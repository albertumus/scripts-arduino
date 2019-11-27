# -*- coding: utf-8 -*-
"""
Created on Thu Sep  5 19:23:41 2019

@author: admin
"""
import time
from pyfirmata import Arduino

board = Arduino('COM4')

i = True

board.digital[12].write(1)
time.sleep(1)
board.digital[12].write(0)
time.sleep(1)
board.digital[12].write(1)
time.sleep(1)
board.digital[12].write(0)

while i:
    # "on" para encender, "off" para agapar y "quit" para salir
    userInput = input("Esperando comando: ")
    
    if (userInput == "on"):
        board.digital[12].write(1)
    elif (userInput == "off"):
        board.digital[12].write(0)
    elif ( userInput == "quit"):
        board.digital[12].write(0)
        i = False
    else:
        board.digital[12].write(0)
        i = False
    
board.exit()
