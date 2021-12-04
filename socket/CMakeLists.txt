cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

#find cppzmq wrapper, installed by make of cppzmq
find_package(cppzmq)

# set the project name
project(socket)

# add the executable
add_executable(socket socket.cpp)
target_link_libraries(socket cppzmq)