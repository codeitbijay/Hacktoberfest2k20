#Number Guessing Game Objectives:

# Include an ASCII art logo.
# Allow the player to submit a guess for a number between 1 and 100.
# Check user's guess against actual answer. Print "Too high." or "Too low." depending on the user's answer. 
# If they got the answer correct, show the actual answer to the player.
# Track the number of turns remaining.
# If they run out of turns, provide feedback to the player. 
# Include two different difficulty levels (e.g., 10 guesses in easy mode, only 5 guesses in hard mode).

import random
from art import logo
from replit import clear

def lives(level):
  """Takes Level response and returns life count"""
  if level == "easy":
    tries = 10
  elif level == "hard":
    tries = 5
  else:
    print("Invalid Entry")
  return tries

print(logo)
number = random.randint(1, 100) #this will give me a random number to use
level = input("Welcome to Guessing Game: Easy or Hard?\n").lower()
#print(level)
#print(number)
tries = lives(level)
#print(tries)


game_in_play = True

while game_in_play != False:
  while tries > 0:
    guess = int(input(f"You have {tries} attempts left, What number do you guess?"))
    if tries == 0:
      print("Game Over")
      game_in_play = False
    elif guess == number:
      print("You guessed correctly!")
      game_in_play = False
    elif guess > number:
      print("Your guess is too high")
      tries -= 1
    elif guess < number:
      print("Your guess is too Low")
      tries -= 1 
    else:
      game_in_play = False
  print("Game Over")
  game_in_play = False
