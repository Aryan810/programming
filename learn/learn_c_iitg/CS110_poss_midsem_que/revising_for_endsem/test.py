# import ngrok python sdk
import ngrok
import time

# Establish connectivity
listener = ngrok.forward(9000, authtoken="1wCXo5uwLzNLJiPdNluFAJDnLP7_7kpv642SYbNo5uZLdciDw")

# Output ngrok url to console
print(f"Ingress established at {listener.url()}")

# Keep the listener alive
try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    print("Closing listener")