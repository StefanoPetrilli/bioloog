cmake_minimum_required(VERSION 3.22)
project(bioloog)

set(CMAKE_CXX_STANDARD 20)
set(FETCHCONTENT_QUIET off)

enable_testing()

add_subdirectory(test)
add_subdirectory(src)