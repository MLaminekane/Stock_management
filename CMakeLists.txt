cmake_minimum_required(VERSION 3.29)
project(Devoir2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")

add_executable(Devoir2 app/main.cpp ${SOURCES})