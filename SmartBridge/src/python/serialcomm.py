# Importing Libraries
import serial
import time
import sys
import serial.tools.list_ports


def chooseport():
    ports = list(serial.tools.list_ports.comports())
    for p in ports:
        print(p)
    port = input("Enter port number: ")
    return port

arduino = serial.Serial(chooseport() , 9600, timeout=.1)

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
while True:
    num = input("Enter a number: ") # Taking input from user
    value = write_read(num)
    print(value) # printing the value 