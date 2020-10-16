from pynput.keyboard import Key, Controller
from time import sleep
keyboard = Controller()
f=open("text.txt","r+")
sleep(5)
for line in f.readlines():
    #print(line.strip().split())
    for l in line.strip():
        keyboard.press(l)
        keyboard.release(l)
        sleep(0.05)
    keyboard.press(Key.enter)
    keyboard.release(Key.enter)
