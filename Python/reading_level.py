from cs50 import get_string
import re

"""
This program asks for some text as input and then returns the reading grade of the text
"""

def readability():
    # acquire text from user
    text = get_string("Text: ")
    # variable for letter, word and sentence count
    lc = wc = sc = 0
    # acquire counts
    for i in text:
        if i.isalpha():
            lc += 1
        if i in ('.', '!', '?'):
            sc += 1
        if i == ' ':
            wc += 1
    # +1 to wc for final word
    wc += 1
    # calculate CL index
    L = (lc / wc) * 100
    S = (sc / wc) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    # print that
    if index < 1:
        print("Before Grade 1")
        return
    if index > 16:
        print("Grade 16+")
        return
    print(f"Grade: {round(index)}")
    return
    
    
readability()
