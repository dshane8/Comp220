cmake_minimum_required(VERSION 3.8)
project(Lab03)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ArrayLib.cpp TestLib.cpp EfficiencyComparisonMain.cpp)
add_executable(Lab03 ${SOURCE_FILES})