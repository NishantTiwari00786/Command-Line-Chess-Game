# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Special targets provided by cmake.
.SUFFIXES:

.NOTPARALLEL:
.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

# Set environment variables for the build.
SHELL = /bin/sh
CMAKE_COMMAND = /usr/bin/cmake
RM = /usr/bin/cmake -E rm -f
CMAKE_SOURCE_DIR = /home/csmajs/rmoha023/final-project-rmoha023-ntiwa006-akoks002-swang433-1
CMAKE_BINARY_DIR = /home/csmajs/rmoha023/final-project-rmoha023-ntiwa006-akoks002-swang433-1

# Targets
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components: \"Unspecified\""
.PHONY : list_install_components

install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start $(CMAKE_BINARY_DIR)/CMakeFiles $(CMAKE_BINARY_DIR)/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start $(CMAKE_BINARY_DIR)/CMakeFiles 0
.PHONY : all

clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

# Build rule for target test.
test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test
.PHONY : test

# Build rule for target gmock_main, gmock, gtest_main, and gtest
gmock_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

gmock: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

gtest_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

gtest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# Object and preprocessor rules for ChessBoard, ChessSquare, and test
ChessBoard.o: ChessBoard.cpp.o
.PHONY : ChessBoard.o
ChessSquare.o: ChessSquare.cpp.o
.PHONY : ChessSquare.o
test.o: test.cpp.o
.PHONY : test.o

# Preprocess and assembly rules
ChessBoard.cpp.i ChessBoard.cpp.s: 
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/ChessBoard.cpp.s
ChessSquare.cpp.i ChessSquare.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/ChessSquare.cpp.s
test.cpp.i test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/test.cpp.s

# Help Target
help:
	@echo "The following are valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean, depend, edit_cache, install"
	@echo "... install/local, install/strip, rebuild_cache"
	@echo "... gmock, gmock_main, gtest, gtest_main, test"
	@echo "... ChessBoard.o, ChessBoard.i, ChessBoard.s"
	@echo "... ChessSquare.o, ChessSquare.i, ChessSquare.s"
	@echo "... test.o, test.i, test.s"
.PHONY : help

cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
