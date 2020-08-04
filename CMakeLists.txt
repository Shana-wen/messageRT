cmake_minimum_required(VERSION 3.16)
project(messageRT)

set(CMAKE_CXX_STANDARD 11)

add_executable(messageRT main.cpp message.cpp)
target_link_libraries(messageRT pthread)