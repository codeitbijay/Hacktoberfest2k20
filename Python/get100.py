import requests
from bs4 import BeautifulSoup
import json

URL = 'https://www.dutchmultimedia.nl/top-100-meest-gebruikte-franse-werkwoorden/'
page = requests.get(URL)
soup = BeautifulSoup(page.content, 'html.parser')

result = soup.find('div', class_='table-responsive')
tbody = result.find('tbody')
trList = tbody.findAll('tr')

wwList = []
for a in trList:
    wwList.append(a.findAll('td')[1].text.strip())

print(wwList)

with open('100.json', 'w', encoding='utf-8') as jsonfile:
    json.dump(wwList, jsonfile, ensure_ascii=False)

