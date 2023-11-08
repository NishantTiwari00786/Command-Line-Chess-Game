CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(ChessProject)

ADD_SUBDIRECTORY(googletest) 
ADD_EXECUTABLE(test
	ChessBoard.cpp
	ChessSquare.cpp
	menu.cpp

)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

