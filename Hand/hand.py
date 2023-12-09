# import socket   #导入socket
import serial  # 导入serial
import time
# import pyautogui
from hand_config import *

# 先初始化一个串口
ser = serial.Serial(port="COM10", baudrate=500000, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE,
                    stopbits=serial.STOPBITS_ONE, timeout=1, rtscts=False)


def ser_send_buf(usb_buf):
    ser.write(usb_buf[0:len(usb_buf)].decode("utf-8").encode())
    time.sleep(0.06)
    # print(krybord[0:len(krybord)].decode("utf-8").encode())
    # print(len(usb_buf))
    # print("发送的Buf：", usb_buf[0:len(usb_buf)].decode("utf-8").encode())
    # print("发送的第%d个字符：%s" % (krybord[0:len(krybord)].decode("utf-8").encode()))
    # print("接收到的字符是%s" % (ser.read(10).decode("utf-8")))


def hand_keyboard(way, *key):
    # 先把键盘添加好
    usb_buf = hand_keyMapping.get(way)
    key_num = 0
    # 左右ctrl之类的
    if key[0] not in hand_keySpecial:
        usb_buf += hand_keyMapping.get('zero')
    else:
        usb_buf += hand_keySpecial.get(key[0])
        key_num = 1
    # 保留位，置零
    usb_buf += hand_keyMapping.get('zero')
    # 添加剩余的
    for i in range(len(key) - key_num):
        usb_buf += hand_keyMapping.get(key[i + key_num])
    # 剩下的补零
    for j in range(6 - len(key) + key_num):
        usb_buf += hand_keyMapping.get('zero')
    ser_send_buf(usb_buf)


if __name__ == '__main__':
    time.sleep(2)
    # usb_buf = b'010000040000000000'
    # ser.write(usb_buf[0:len(usb_buf)].decode("utf-8").encode())
    # time.sleep(1)
    hand_keyboard('click', 'b', 'b', 'b', 'b', 'b', 'b')
    hand_keyboard('click', 'b')
    hand_keyboard('click', 'c')
    hand_keyboard('down', 'a')
    time.sleep(2)
    hand_keyboard('up', 'zero')

