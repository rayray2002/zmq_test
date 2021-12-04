import zmq

context = zmq.Context()
print("Connecting to server...")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

while True:
    msg = input("CLI msg：")
    socket.send_string(msg)

    reply = socket.recv()
    print("Received reply: ", reply.decode())
