# save this as web_terminal.py
import os
import pty
import select
import subprocess
from flask import Flask, render_template_string
from flask_sock import Sock

app = Flask(__name__)
sock = Sock(app)

# HTML page with basic terminal emulator using WebSocket
HTML = '''
<!DOCTYPE html>
<html>
<head>
  <title>Python Terminal</title>
  <style>
    body { background-color: black; color: white; font-family: monospace; }
    #term { white-space: pre; }
  </style>
</head>
<body>
  <div id="term"></div>
  <script>
    let term = document.getElementById("term");
    let ws = new WebSocket("ws://" + location.host + "/ws");
    ws.onmessage = (event) => term.innerText += event.data;
    window.addEventListener("keydown", e => {
      if (e.key.length === 1) ws.send(e.key);
      else if (e.key === "Enter") ws.send("\\n");
      else if (e.key === "Backspace") ws.send("\\x7f");
    });
  </script>
</body>
</html>
'''

@app.route('/')
def index():
    return render_template_string(HTML)

@sock.route('/ws')
def terminal(ws):
    pid, fd = pty.fork()
    if pid == 0:
        # Child process: start shell
        os.execvp("bash", ["bash"])

    # Parent process: interact via socket
    while True:
        rlist, _, _ = select.select([fd], [], [], 0.1)
        if rlist:
            output = os.read(fd, 1024).decode(errors='ignore')
            ws.send(output)
        if ws.close:
            break
        if ws.available():
            data = ws.receive()
            os.write(fd, data.encode())

if __name__ == '__main__':
    app.run(port=5000)