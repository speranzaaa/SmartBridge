# Importing Libraries
import serial
import time

arduino = serial.Serial('COM5', 9600) #Creating our serial object named arduino

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
while True:
    num = input("Enter a number: ") # Taking input from user
    value = write_read(num)
    print(value) # printing the value