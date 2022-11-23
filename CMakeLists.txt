cmake_minimum_required(VERSION 3.23)
project(bioloog)

set(CMAKE_CXX_STANDARD 20)

add_executable(bioloog main.cpp utils/readFromFile.cpp utils/readFromFile.h test/test.cpp)
add_subdirectory(test)