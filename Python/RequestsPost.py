#!/usr/bin/env python3

import requests

# Get request
r = requests.post("https://httpbin.org/post", headers={"Cookie": "This cookie is a sample"}, data={"firstname": "John", "lastname": "Doe"})

# Get response
response = r.text
