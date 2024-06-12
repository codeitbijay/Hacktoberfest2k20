try:
	from requests import get
except:
	print("Install requests lib: python -m pip install requests")
	exit()

from sys import argv

if len(argv) != 2:
	print("Use: python get_website_content.py https://www.google.com")
	exit()

r = get(argv[1])
print(r.content)
