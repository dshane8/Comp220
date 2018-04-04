cmake_minimum_required(VERSION 3.8)
project(Lab09)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ListTests.cpp IntLinkedList.cpp LinkedNode.cpp Lab9Tester.cpp ArrayList.cpp ArrayLib.cpp)
add_executable(Lab09 ${SOURCE_FILES})