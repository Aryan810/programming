import requests
from bs4 import BeautifulSoup

res = requests.get("http://172.16.32.44/opencourse/views/lectures.php?cid=1")
print(res.content)
with open("temp.html", "wb") as temp:
    temp.write(res.content)
with open("temp.html") as fp:
    soup = BeautifulSoup(fp, "html.parser")

# print(soup.findall("td"))