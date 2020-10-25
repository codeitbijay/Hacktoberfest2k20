# -*- coding: utf-8 -*-
"""
Created on Fri Aug 21 17:28:08 2020

@author: DELL
"""

import pyshorteners
import tkinter as tk
from tkinter import END


win=tk.Tk()
win.title("URL SHORTENER")
win.geometry("700x200")

def short():
    link = input.get("1.0","end-1c")
    print(link)
    shortener=pyshorteners.Shortener()
    short_url=shortener.tinyurl.short(link)
    output.insert(END,short_url)
    
    
label=tk.Label(text="Enter the url here")
label.grid(row=2,column=0)
input=tk.Text(win,height=2,width=20,bg="light yellow")
input.grid(row=4,column=0)
btn=tk.Button(win,text="Go",command=lambda:short())
btn.grid(row=6,column=0)
label1=tk.Label(text="Display the shortened url here")
label1.grid(row=8,column=0)
output=tk.Text(win,height=2,width=20,bg="light cyan")
output.grid(row=9,column=0)
win.mainloop()
