import base64

a = base64.b64decode('''eyJuIjogMSwgImRhdGEiOiBbeyJwY2FwIjogImJtOTBJR0VnZG1Gc2FXUXpnR0JoY0E9PSIsICJteXN0IjogImJtOTBJ
R0VnZG1Gc2FXUXNiWHl6Z0hkMmhhR1Y0WTI5a1pRPT0iLCAibWVtb3J5X2FkZHJlc3MiOiAyfV19''')
print(a.decode('utf-8', errors="ignore"))