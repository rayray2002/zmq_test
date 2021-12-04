cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

#find cppzmq wrapper, installed by make of cppzmq
find_package(cppzmq)

# set the project name
project(controller)

# add the executable
add_executable(controller controller.cpp)
target_link_libraries(controller cppzmq)