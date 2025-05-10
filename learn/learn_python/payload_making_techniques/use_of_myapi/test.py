# client.py
from ReverseShell import ReverseShellClientTcp

# Connects back to localhost on port 4444
client = ReverseShellClientTcp(address=("127.0.0.1", 4444), ssl=False)
client.run()