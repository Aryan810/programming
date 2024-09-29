import requests
# url = input("ENTER URL: ")
# name = input("ENTER FILENAME: ")
name = "continuity"
url = "https://www.iitg.ac.in/anjankc/Continuity.pdf"
req = requests.get(url)

with open(name, 'wb') as file:
    file.write(req.content)