cmake_minimum_required(VERSION 3.26)
project(P3group_50)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(P3group_50
        hashTable.h
        main.cpp
        parsingCSV.h)
