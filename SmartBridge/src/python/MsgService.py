import json
import serial

class MsgService:
    def __init__(self, port, baudrate):
        self.port = port
        self.baudrate = baudrate
        self.ser = serial.Serial(port, baudrate)

    def send(self, msg):
        msg = json.dumps(msg)
        self.ser.write(msg)
        self.ser.write('\n')

    def recv(self):
        msg = b""
        while (True):
            c = self.ser.read()
            if (c == b'\n'):
                return msg.decode('UTF-8').split(" ")
            else:
                msg += c
