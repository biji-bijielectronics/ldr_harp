import time
import pygame
import sys
import serial

pygame.mixer.pre_init(44100, -16, 12, 512)
pygame.init()

soundfile = "samples/loop_amen_full.wav"
sound =  pygame.mixer.Sound(soundfile)

strPort = '/dev/ttyACM0'

ser = serial.Serial(strPort, 9600)


while 1:
    line = ser.readline().strip()
    print line 
    if line == 'ON': 
        sound.play(loops = -1)
    if line == 'OFF':
        sound.stop()

