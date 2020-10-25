# -*- coding: utf-8 -*-
"""
Created on Sun Aug 23 20:50:10 2020

@author: DELL
 ''' '
"""
#In this project after giving the topic input, the news is read out first after clicking the button and then the news text is displayed in the TextBox
#pip install GoogleNews(to install the google news package)
#pip install pywin32(to install win32 package)

from GoogleNews import GoogleNews
import tkinter as tk
from tkinter import END
import tkinter.font as tkFont
from win32com.client import Dispatch #import this module for text to speech conversion



win=tk.Tk()
win.title("News Reader")
win.geometry("900x400")
def news():
    topic=entry.get()
    googlenews=GoogleNews()
    googlenews=GoogleNews('en','d')
    googlenews.search(topic)
    googlenews.getpage()
    googlenews.result()
    a=googlenews.gettext()
    output.insert(END,a) 
    speak=Dispatch("SAPI.SpVoice") #calling this dispatch method helps to interact with Microsoft Speech SDK to speak
    speak.Speak(a)

    
    
label=tk.Label(win,text="ENTER THE NEWS TOPIC Y0U WANT TO SEE",bg="light cyan")
label.grid(row=0,column=0)
entry=tk.Entry(win)
entry.grid(row=1,column=0)
btn=tk.Button(win,text="Go",command=news)
btn.grid(row=5,column=0)
output=tk.Text(win,height=30,width=80,bg="light pink")
output.grid(row=9,column=0)
style = tkFont.Font(family="Algerian", size=16, weight="bold", slant="italic")
label.configure(font=style)
win.mainloop()
