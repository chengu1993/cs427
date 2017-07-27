cmake_minimum_required(VERSION 3.6)
project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
        frozen.c frozen.h
        mongoose.c mongoose.h
        Graph.hpp Graph.cpp
        Utils.hpp
        candidateNode.cpp candidateNode.hpp getTheShortestPath.cpp getTheShortestPath.hpp FileSystem.cpp FileSystem.hpp)

add_executable(lab1 ${SOURCE_FILES})