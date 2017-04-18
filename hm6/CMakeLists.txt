cmake_minimum_required(VERSION 3.6)
project(hm6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Dictionary.h KeyValue.h)

set(TEST_FILES testing/TestingMain.cpp testing/DictionaryTest.cpp testing/DictionaryTest.h testing/KeyValueTest.cpp testing/KeyValueTest.h testing/Person.cpp testing/Person.h)

add_executable(hm6 main.cpp ${SOURCE_FILES})

add_executable(hm6_test ${TEST_FILES} ${SOURCE_FILES})