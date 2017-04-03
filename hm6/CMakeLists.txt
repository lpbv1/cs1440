cmake_minimum_required(VERSION 3.6)
project(hm6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

set(TEST_FILES testing/TestingMain.cpp)

add_executable(hm6 ${SOURCE_FILES})

add_executable(hm6_test ${TEST_FILES} ${SOURCE_FILES})