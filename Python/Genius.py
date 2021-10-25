import random, time
from datetime import datetime

letters, sequence, play = ["Q", "W", "E", "R"], [], True
start = input("Welcome to Genius!\nUse the letters Q, W, E, R to play\nPress ENTER to start")

while play: #game
    print("\n"*100) #clear screen
    sequence.append(letters[random.randint(0, 3)]) #adds a new letter to the sequence
    time.sleep(2)
    for letter in sequence: #shows sequence
        print(letter)
        time.sleep(2)
    print("\n"*100) #clear screen
    for letter in sequence: #asks for the memorized sequence
        if play:
            guess = input().capitalize()
            if guess != letter:
                print("Wrong letter.")
                play = False

timeend, score = datetime.now().strftime("%x"), len(sequence)-1 #user stats
name = input("\nCongrats! You've made it to round {}!\nPlease type our name: ".format(score))

try: #try open the file that has the previous saved stats
    f = open("geniusbestscore.txt")
    bestscore, bestname, besttime = f.read().split(",")
    if score >= int(bestscore):
        f = open("geniusbestscore.txt", "w")
        f.write("{}, {}, {}".format(score, name, timeend))
        bestscore, bestname, besttime = score, name, timeend
except FileNotFoundError: #if the file does not exist
    f = open("geniusbestscore.txt", "w")
    f.write("{}, {}, {}".format(score, name, timeend))
    bestscore, bestname, besttime = score, name, timeend

print("Higher score of {} by {} on {}".format(bestscore, bestname, besttime)) #higher score