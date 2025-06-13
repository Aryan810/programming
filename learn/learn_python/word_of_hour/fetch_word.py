import requests
import json
import tkinter as tk
req = requests.get("https://wordofthehour.org/cache/wordofthehour.json?src=python_woth_api")
data = json.loads(str(req.content.decode('utf-8-sig')))
root = tk.Tk()
root.title("Word Of Hour")
root.geometry("600x380")
label = tk.Label(root, text=data['english'])
label.pack(padx=20, pady=20)
label = tk.Label(root, text=data['hindi'])
label.pack(padx=20, pady=20)
try:
    label = tk.Label(root, text=data['english_definitions'][0], wraplength=550)
    label.pack(padx=20, pady=20)
except Exception as e:
    pass
try:
    label = tk.Label(root, text=data['english_definitions'][1], wraplength=550)
    label.pack(padx=20, pady=20)
except Exception as e:
    pass
try:
    label = tk.Label(root, text="Eg: " + data['english_sentence'], wraplength=550)
    label.pack(padx=20, pady=20)
except Exception as e:
    pass
root.mainloop()
