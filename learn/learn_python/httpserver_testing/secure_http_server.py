from http.server import HTTPServer, SimpleHTTPRequestHandler
import base64

# Define your username and password here
USERNAME = "admin"
PASSWORD = "password123"

class AuthHandler(SimpleHTTPRequestHandler):
    def do_HEAD(self):
        self.send_response(401)
        self.send_header('WWW-Authenticate', 'Basic realm="Login Required"')
        self.end_headers()

    def do_AUTHHEAD(self):
        self.send_response(401)
        self.send_header('WWW-Authenticate', 'Basic realm="Login Required"')
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        # Extract the 'Authorization' header
        auth_header = self.headers.get('Authorization')
        if auth_header is None:
            self.do_AUTHHEAD()
            self.wfile.write(b'Unauthorized: Please provide credentials.')
        else:
            # Decode the 'Basic <base64_encoded_value>' part
            encoded_credentials = auth_header.split(' ')[1]
            decoded_credentials = base64.b64decode(encoded_credentials).decode('utf-8')

            # Check if username & password match
            if decoded_credentials == f"{USERNAME}:{PASSWORD}":
                super().do_GET()  # Serve the file/directory
            else:
                self.do_AUTHHEAD()
                self.wfile.write(b'Unauthorized: Incorrect credentials.')

if __name__ == '__main__':
    PORT = 8080
    server_address = ('', PORT)
    httpd = HTTPServer(server_address, AuthHandler)
    print(f"Serving on port {PORT} with authentication...")
    httpd.serve_forever()