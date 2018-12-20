cmake_minimum_required(VERSION 3.12)

set (CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(calc
	calculator.cpp
)

TARGET_LINK_LIBRARIES(calc  gtest)
