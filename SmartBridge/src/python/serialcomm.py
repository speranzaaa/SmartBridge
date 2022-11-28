# Importing Libraries
import serial
from os import system, name
import serial.tools.list_ports
from MsgService import MsgService
import matplotlib.pyplot as plt
import matplotlib.animation as animation


def chooseport():
    ports = list(serial.tools.list_ports.comports())
    for i in range(len(ports)):
        print(f"{i} -> {ports[i]}")
    port = int(input("Enter port number: "))
    return str.split(str(ports[port]))[0]

def clear():
    if name == 'nt':
        _ = system('cls')
    else:
        _ = system('clear')

history = []
msgService = MsgService(chooseport(), 9600)
fig = plt.figure()
ax1 = fig.add_subplot(1, 1, 1)

def animate(i):
    clear()
    msg = msgService.recv()
    print(f"Current status: {msg[0]}\tBridge Light: {msg[1]}\tWater Level: {msg[2]}")
    history.append(float(msg[2]))
    xar = [i for i in range(len(history))]
    ax1.clear()
    ax1.plot(xar, history)

ani = animation.FuncAnimation(fig, animate, interval=1000)
plt.show()
