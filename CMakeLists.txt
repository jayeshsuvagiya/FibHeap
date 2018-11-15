cmake_minimum_required(VERSION 3.6)
project(FibHeap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp fibheap.cpp fibheap.h)
add_executable(keywordcounter ${SOURCE_FILES})