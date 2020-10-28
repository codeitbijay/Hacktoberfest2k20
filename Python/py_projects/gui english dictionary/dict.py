import json 
from difflib import get_close_matches 
import tkinter as tk
from tkinter import messagebox
from tkinter import StringVar
import tkinter.font as TkFont
data = json.load(open("data.json")) 
def translate(w): 
    # converts to lower case 
    w = w.lower() 
  
    if w in data: 
        #return data[w] 
        tk.messagebox.showinfo("Meaning",data[w] )
    # for getting close matches of word 
    elif len(get_close_matches(w, data.keys())) > 0:              
        yn = input("Did you mean % s instead? Enter y if yes, or n if no: " % get_close_matches(w, data.keys())[0]) 
        yn = yn.lower() 
        if yn == "y": 
            a=data[get_close_matches(w, data.keys())[0]] 
            tk.messagebox.showinfo("Meaning",a )
        elif yn == "n": 
            #return "Please recheck."
            tk.messagebox.showinfo("Meaning","Please check" )
        else: 
            #return "Entry not found"
            tk.messagebox.showinfo("Meaning","entry not found" )
    else: 
        #return "Word not exist"
        tk.messagebox.showinfo("Meaning","word not exist" )

root=tk.Tk()
root.geometry('250x150')
root.title("Dictionary")
w= tk.StringVar()
fontStyle=TkFont.Font(family="Lucida Grade",size=15)
tk.Label(root,text="Enter word",font=fontStyle).grid(row=5)
tk.Entry(root, textvariable=w).grid(row=5,column=1)
tk.Button(root,text="Find meaning",command=lambda :translate(w.get())).grid(row=6)
root.mainloop()