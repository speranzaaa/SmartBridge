import matplotlib.pyplot as plt
import matplotlib.animation as animation
import random
import time

fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)

def animate(i):
    pullData = open("sampleText.txt","r").read()
    print("test")
    dataArray = pullData.split('\n')
    xar = []
    yar = []
    for eachLine in dataArray:
        if len(eachLine)>1:
            x,y = eachLine.split(',')
            # xar.append(int(x))
            xar.append(random.random() % 100)
            # yar.append(int(y))
            yar.append(random.random() % 100)
    ax1.clear()
    ax1.plot(xar,yar)
ani = animation.FuncAnimation(fig, animate, interval=1000)
plt.show()