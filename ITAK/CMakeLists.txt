cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Dictionary.h KeyValue.h
        Analyzer.cpp Analyzer.h
        DenialOfServiceAnalyzer.cpp DenialOfServiceAnalyzer.h
        PortScanAnalyzer.cpp PortScanAnalyzer.h
        ResultSet.cpp ResultSet.h
        Configuration.cpp Configuration.h
        Utils.cpp Utils.h)
add_executable(ITAK main.cpp ${SOURCE_FILES})

set(TEST_FILES)
add_executable(ITAKTest Test/mainTest.cpp)