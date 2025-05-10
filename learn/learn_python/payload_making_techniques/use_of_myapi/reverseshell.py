# server.py
from ReverseShell import ReverseShellSocketTcp, ReverseShell

# TCP reverse shell server on localhost:4444
with ReverseShellSocketTcp(address=("127.0.0.1", 4444), ssl=False, handler=ReverseShell) as shellserver:
    shellserver.serve_forever()