#!/usr/bin/python3

import requests
import graphyte

r = requests.get('https://api.openweathermap.org/data/2.5/weather?id=2753801&APPID=8c8360b6ce37f210f43f9cdb8a2ccc07&units=metric')

temp = r.json()['main']['temp']
humidity = r.json()['main']['humidity']
pressure = r.json()['main']['pressure']
windSpeed = r.json()['wind']['speed']

graphyte.init('const.rocks', prefix='weather')
graphyte.send('temp', temp)
graphyte.send('humidity', humidity)
graphyte.send('pressure', pressure)
graphyte.send('windSpeed', windSpeed)
