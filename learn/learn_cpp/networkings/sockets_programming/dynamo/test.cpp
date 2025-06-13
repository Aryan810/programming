#include <asio.hpp>
#include <asio/ssl.hpp>
#include <iostream>

int main() {
    try {
        asio::io_context io;
        asio::ssl::context ctx(asio::ssl::context::sslv23_client);
        asio::ssl::stream<asio::ip::tcp::socket> socket(io, ctx);

        // Resolve the host
        asio::ip::tcp::resolver resolver(io);
        auto endpoints = resolver.resolve("aryan810.github.io", "443");

        // Connect the TCP socket
        asio::connect(socket.lowest_layer(), endpoints);

        // Perform SSL handshake
        socket.handshake(asio::ssl::stream_base::client);

        // Form the HTTP request
        std::string request =
            "GET /index.html HTTP/1.1\r\n"
            "Host: aryan810.github.io\r\n"
            "Connection: close\r\n\r\n";

        // Send the request
        asio::write(socket, asio::buffer(request));

        // Read the response
        asio::streambuf response;
        asio::read_until(socket, response, "\r\n");

        // Print the status line
        std::istream response_stream(&response);
        std::string http_version;
        unsigned int status_code;
        std::string status_message;

        response_stream >> http_version >> status_code;
        std::getline(response_stream, status_message);

        if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
            std::cout << "Invalid response\n";
            return 1;
        }

        std::cout << "Status: " << status_code << " " << status_message;

        // Print remaining headers and body
        asio::read_until(socket, response, "\r\n\r\n");
        std::string header;
        while (std::getline(response_stream, header) && header != "\r")
            std::cout << header << "\n";
        std::cout << "\n";

        // Print body
        std::ostringstream body;
        if (response.size() > 0)
            body << &response;
        asio::error_code ec;
        while (asio::read(socket, response, asio::transfer_at_least(1), ec))
            body << &response;
        if (ec != asio::error::eof) throw asio::system_error(ec);
        std::cout << body.str();
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}