import bson
import serial

class MsgService:
    def __init__(self, port, baudrate):
        self.port = port
        self.baudrate = baudrate
        self.ser = serial.Serial(port, baudrate)

    def send(self, msg):
        msg = bson.dumps(msg)
        self.ser.write(msg)
        self.ser.write('\n')

    def recv(self):
        msg = self.ser.read_until('\n')
        msg = bson.loads(msg)
        return msg
