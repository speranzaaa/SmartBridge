# Importing Libraries
import serial
import time
import sys
import serial.tools.list_ports
from MsgService import MsgService
import bson


def chooseport():
    ports = list(serial.tools.list_ports.comports())
    for i in range(len(ports)):
        print(f"{i} -> {ports[i]}")
    port = int(input("Enter port number: "))
    return str.split(str(ports[port]))[0]

# def write_read(x):
#     arduino.write(bytes(x, 'utf-8'))
#     time.sleep(0.05)
#     data = arduino.readline()
#     return data
msgService = MsgService(chooseport(), 9600)
while True:
    msg = msgService.recv()
    print({msg})