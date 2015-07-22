cmake_minimum_required(VERSION 3.2)
project(XMLParser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES)
add_executable(XMLParser ${SOURCE_FILES} src/XMLClass.cpp src/XMLClass.h src/main.cpp)