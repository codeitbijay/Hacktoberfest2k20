# -*- coding: utf-8 -*-
"""
Created on Fri Sep  4 13:32:55 2020

@author: DELL
"""

import requests
from tkinter import *
import tkinter as tk

def weather():
    city_name=entry.get()
    api_key = "dea5a2217c08125e1395555a7c9cf8e3"
    base_url="http://api.openweathermap.org/data/2.5/weather?"
    complete_url = base_url + "appid=" + api_key + "&q=" + city_name 
  
    res=requests.get(complete_url)
    output=res.json()
    if output["cod"] != "404": 
        y = output["main"] 
        temprature = y["temp"] 
        pressure = y["pressure"] 
        humidity = y["humidity"] 
        z = output["weather"] 
        weather_status= z[0]["description"] 
        temprature=output['main']['temp']
        pressure=output['main']['pressure']
        humidity=output['main']['humidity']
        
        w_label.configure(text="Weather Status:"+weather_status)
        t_label.configure(text="Temprature(in Kelvin):  "+str(temprature))
        h_label.configure(text="Humidity:  "+str(humidity))
        s_label.configure(text="Pressure:  "+str(pressure))
    else:
        a_label.configure(text="No such city found")
    
    
    
    
win=tk.Tk()
win.geometry("400x350")
win.title("Weather prediction")
label=tk.Label(win,text="Enter the name of the city",font=("times",15,"bold"))
label.grid(row=2,column=2)
entry=tk.Entry(win)
entry.grid(row=3,column=2)
b1=tk.Button(win,text="Find weather",width=20,command=weather)
b1.grid(row=4,column=2)
w_label=tk.Label(win,font=("times",15,"italic"))
w_label.grid(row=10,column=2)

t_label=tk.Label(win,font=("times",15,"italic"))
t_label.grid(row=12,column=2)

h_label=tk.Label(win,font=("times",15,"italic"))
h_label.grid(row=14,column=2)

s_label=tk.Label(win,font=("times",15,"italic"))
s_label.grid(row=16,column=2)

a_label=tk.Label(win,font=("times",15,"italic"))
a_label.grid(row=18,column=2)
win.mainloop()