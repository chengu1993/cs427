cmake_minimum_required(VERSION 3.6)
project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
        frozen.c frozen.h
        mongoose.c mongoose.h
        Graph.hpp Graph.cpp
        http_server.cpp http_server.h)

add_executable(lab1 ${SOURCE_FILES})