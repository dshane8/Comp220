cmake_minimum_required(VERSION 3.8)
project(Lab02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Lab2Tester.cpp TestLib.cpp ArrayLib.cpp)
add_executable(Lab02 ${SOURCE_FILES})