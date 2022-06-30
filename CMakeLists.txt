cmake_minimum_required(VERSION 3.22)
project(Walking_Person)

set(CMAKE_CXX_STANDARD 14)

add_executable(Walking_Person
        mainWalkingScreen.cpp
        Move.cpp
        Person.cpp
        Screen.cpp)
