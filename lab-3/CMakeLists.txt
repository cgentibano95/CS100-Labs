cmake_minimum_required(VERSION 3.12)

set (CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
	test.cpp
)

ADD_EXECUTABLE(main
	main.cpp
)
ADD_EXECUTABLE(calculator
	calculator.cpp
)

ADD_EXECUTABLE(calc
	testCalc.cpp
)

TARGET_LINK_LIBRARIES(calc  gtest)
