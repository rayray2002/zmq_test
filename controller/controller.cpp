#include <zmq.hpp>
#include <string>
#include <cstring>
#include <iostream>

int main()
{
    //  Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");

    char buf[100] = {0};
    while (std::string(buf).compare("done"))
    {
        zmq::message_t request;

        //  Wait for next request from client
        socket.recv(&request);
        std::memcpy(buf, request.data(), 100);
        std::cout << "Received request " << request.to_string() << std::endl;

        //  Send reply back to client
        zmq::message_t reply("Received", 8);
        socket.send(reply);
    }
    return 0;
}