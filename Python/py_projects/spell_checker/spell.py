# -*- coding: utf-8 -*-
"""
Created on Fri Aug 28 22:26:53 2020

@author: DELL
"""

from textblob import TextBlob
import tkinter as tk
from tkinter import END


def correction() : 
    input_word = entry1.get() 
    blob_obj = TextBlob(input_word) 
    corrected_word = str(blob_obj.correct()) 
    entry2.insert(10,corrected_word) 
    
def clearAll() : 
    entry1.delete(0, END) 
    entry2.delete(0, END) 
  
     
    
win=tk.Tk()
win.geometry("400x350")
win.title("Spell Checker")
win.configure(background = 'light cyan')   
label1=tk.Label(win,text="Write anything here",font=("times",15,"bold"))
label1.grid(row=1,column=0)
entry1=tk.Entry(win,width=50)
entry1.grid(row=1,column=2)
label2=tk.Label(win,text="Corrected statement",font=("times",15,"bold"))
label2.grid(row=3,column=0)
entry2=tk.Entry(win,width=50)
entry2.grid(row=3,column=2)
b1=tk.Button(win,text="Correct",width=20,command=correction)
b1.grid(row=5,column=0)  
b2=tk.Button(win,text="Exit",width=20,command=clearAll)
b2.grid(row=5,column=2)    
win.mainloop() 