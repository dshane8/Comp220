cmake_minimum_required(VERSION 3.8)
project(Lab01)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES TestMain.cpp TestLib.cpp ArrayLib.cpp)
add_executable(Lab01 ${SOURCE_FILES})