import serial
from time import sleep
ser = serial.Serial('/dev/ttyS0',9600)
toggle = 1
#i = 0
id = 1
while True:
    ser.write(f"{id}".encode())
    sleep(3)
    if toggle == 1:
        id = 2
        toggle = 0
    else:
        id = 1
        toggle = 1