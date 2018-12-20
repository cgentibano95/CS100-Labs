cmake_minimum_required(VERSION 3.12)
set (CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
               test.cpp
	       iterator.cpp
               composite.cpp
               visitor.cpp
               )

TARGET_LINK_LIBRARIES(test gtest)
