#include <zmq.hpp>
#include <string>
#include <iostream>
#include <string>

void send(const std::string &msg)
{
    //  Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);

    std::cout << "Connecting to receiver ..." << std::endl;
    socket.connect("tcp://localhost:5555");

    zmq::message_t request(100);
    memcpy(request.data(), msg.c_str(), 100);
    std::cout << "Sending message " << msg << "..." << std::endl;
    socket.send(request);

    zmq::message_t response;
    socket.recv(&response);
    std::cout << "Response: " << response.to_string() << std::endl;
}

int main()
{
    while (1)
    {
        std::string msg;
        std::cout << "socket msg: ";
        std::cin >> msg;
        send(msg);
    }
}