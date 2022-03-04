#HTML.PARSER
#BeautifulSoup4
import requests
from bs4 import BeautifulSoup
url = input("Enter a website to extract the URL's from: ")
r = requests.get("http://" +url)
data = r.text
soup = BeautifulSoup(data,'html.parser')
for link in soup.find_all('a'):
  print(link.get('href'))

