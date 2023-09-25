import requests
import urllib.parse

address = 'uttarpara kotrung'
url = 'https://nominatim.openstreetmap.org/search/' + urllib.parse.quote(address) +'?format=json'

response = requests.get(url).json()
print("lat: " + response[0]["lat"])
print("lon: " + response[0]["lon"])