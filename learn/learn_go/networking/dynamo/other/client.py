import socket
import time

SERVER_HOST = 'https://dbf8-14-139-196-221.ngrok-free.app'  # Change this to the server's IP
SERVER_PORT = 80         # Change if your server is using a different port
MESSAGE = "Hello from client"
INTERVAL = 2  # seconds between messages

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect((SERVER_HOST, SERVER_PORT))
        print(f"Connected to {SERVER_HOST}:{SERVER_PORT}")

        while True:
            MESSAGE = input("message to send: ")
            sock.sendall(MESSAGE.encode('utf-8'))
            print(f"Sent: {MESSAGE}")
            time.sleep(INTERVAL)

if __name__ == "__main__":
    main()