cmake_minimum_required(VERSION 3.22)
project(linkedLists)

set(CMAKE_CXX_STANDARD 14)

add_executable(linkedLists
        SingleLinkedList.h
        SingleLinkedList.cpp
        main.cpp SingleLinkedList.cpp)