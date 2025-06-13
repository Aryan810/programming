#include <bits/stdc++.h>
#include <chrono>
#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

using namespace std;
int main(){
    asio::error_code ec;
    asio::io_context context;

   asio::ip::tcp::endpoint endpoints(asio::ip::make_address("51.38.81.49", ec), 80);

    asio::ip::tcp::socket socket(context);

    socket.connect(endpoints, ec);

    if (!ec){
        cout << "Connected successfully !" << endl;
    }else{
        cout << "Failed to connect: \n" << ec.message() << std::endl;
    }

    if (socket.is_open()){
        // cout << "WE ARE HERE" << endl;
        string sRequest = "GET /~fdc/sample.html HTTP/1.1\r\n"
                          "HOST: david-brr.co.uk\r\n"
                          "Connection: close\r\n\r\n";
        // buffer is actually a container which contains some bytes/
        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
        socket.wait(socket.wait_read);
        size_t bytes = socket.available();
        cout << "Bytes available: " << bytes << endl;
        if (bytes > 0){
            vector<char> vBuffer(bytes);
            socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);
            for (auto c: vBuffer){
                cout << c;
            }cout << endl;
        }
        cout << ec.message() << endl;
    }

    int n;
    cin >> n;
    return 0;
}
