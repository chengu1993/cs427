# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chengu/git/Distributed/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chengu/git/Distributed/lab2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab1.dir/flags.make

CMakeFiles/lab1.dir/main.cpp.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/Distributed/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab1.dir/main.cpp.o -c /Users/chengu/git/Distributed/lab2/main.cpp

CMakeFiles/lab1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chengu/git/Distributed/lab2/main.cpp > CMakeFiles/lab1.dir/main.cpp.i

CMakeFiles/lab1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chengu/git/Distributed/lab2/main.cpp -o CMakeFiles/lab1.dir/main.cpp.s

CMakeFiles/lab1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/lab1.dir/main.cpp.o.requires

CMakeFiles/lab1.dir/main.cpp.o.provides: CMakeFiles/lab1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab1.dir/build.make CMakeFiles/lab1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lab1.dir/main.cpp.o.provides

CMakeFiles/lab1.dir/main.cpp.o.provides.build: CMakeFiles/lab1.dir/main.cpp.o


CMakeFiles/lab1.dir/frozen.c.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/frozen.c.o: ../frozen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/Distributed/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab1.dir/frozen.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab1.dir/frozen.c.o   -c /Users/chengu/git/Distributed/lab2/frozen.c

CMakeFiles/lab1.dir/frozen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab1.dir/frozen.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chengu/git/Distributed/lab2/frozen.c > CMakeFiles/lab1.dir/frozen.c.i

CMakeFiles/lab1.dir/frozen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab1.dir/frozen.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chengu/git/Distributed/lab2/frozen.c -o CMakeFiles/lab1.dir/frozen.c.s

CMakeFiles/lab1.dir/frozen.c.o.requires:

.PHONY : CMakeFiles/lab1.dir/frozen.c.o.requires

CMakeFiles/lab1.dir/frozen.c.o.provides: CMakeFiles/lab1.dir/frozen.c.o.requires
	$(MAKE) -f CMakeFiles/lab1.dir/build.make CMakeFiles/lab1.dir/frozen.c.o.provides.build
.PHONY : CMakeFiles/lab1.dir/frozen.c.o.provides

CMakeFiles/lab1.dir/frozen.c.o.provides.build: CMakeFiles/lab1.dir/frozen.c.o


CMakeFiles/lab1.dir/mongoose.c.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/mongoose.c.o: ../mongoose.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/Distributed/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab1.dir/mongoose.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab1.dir/mongoose.c.o   -c /Users/chengu/git/Distributed/lab2/mongoose.c

CMakeFiles/lab1.dir/mongoose.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab1.dir/mongoose.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chengu/git/Distributed/lab2/mongoose.c > CMakeFiles/lab1.dir/mongoose.c.i

CMakeFiles/lab1.dir/mongoose.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab1.dir/mongoose.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chengu/git/Distributed/lab2/mongoose.c -o CMakeFiles/lab1.dir/mongoose.c.s

CMakeFiles/lab1.dir/mongoose.c.o.requires:

.PHONY : CMakeFiles/lab1.dir/mongoose.c.o.requires

CMakeFiles/lab1.dir/mongoose.c.o.provides: CMakeFiles/lab1.dir/mongoose.c.o.requires
	$(MAKE) -f CMakeFiles/lab1.dir/build.make CMakeFiles/lab1.dir/mongoose.c.o.provides.build
.PHONY : CMakeFiles/lab1.dir/mongoose.c.o.provides

CMakeFiles/lab1.dir/mongoose.c.o.provides.build: CMakeFiles/lab1.dir/mongoose.c.o


CMakeFiles/lab1.dir/Graph.cpp.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/Distributed/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab1.dir/Graph.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab1.dir/Graph.cpp.o -c /Users/chengu/git/Distributed/lab2/Graph.cpp

CMakeFiles/lab1.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1.dir/Graph.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chengu/git/Distributed/lab2/Graph.cpp > CMakeFiles/lab1.dir/Graph.cpp.i

CMakeFiles/lab1.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1.dir/Graph.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chengu/git/Distributed/lab2/Graph.cpp -o CMakeFiles/lab1.dir/Graph.cpp.s

CMakeFiles/lab1.dir/Graph.cpp.o.requires:

.PHONY : CMakeFiles/lab1.dir/Graph.cpp.o.requires

CMakeFiles/lab1.dir/Graph.cpp.o.provides: CMakeFiles/lab1.dir/Graph.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab1.dir/build.make CMakeFiles/lab1.dir/Graph.cpp.o.provides.build
.PHONY : CMakeFiles/lab1.dir/Graph.cpp.o.provides

CMakeFiles/lab1.dir/Graph.cpp.o.provides.build: CMakeFiles/lab1.dir/Graph.cpp.o


CMakeFiles/lab1.dir/candidateNode.cpp.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/candidateNode.cpp.o: ../candidateNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/Distributed/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab1.dir/candidateNode.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab1.dir/candidateNode.cpp.o -c /Users/chengu/git/Distributed/lab2/candidateNode.cpp

CMakeFiles/lab1.dir/candidateNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1.dir/candidateNode.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chengu/git/Distributed/lab2/candidateNode.cpp > CMakeFiles/lab1.dir/candidateNode.cpp.i

CMakeFiles/lab1.dir/candidateNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1.dir/candidateNode.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chengu/git/Distributed/lab2/candidateNode.cpp -o CMakeFiles/lab1.dir/candidateNode.cpp.s

CMakeFiles/lab1.dir/candidateNode.cpp.o.requires:

.PHONY : CMakeFiles/lab1.dir/candidateNode.cpp.o.requires

CMakeFiles/lab1.dir/candidateNode.cpp.o.provides: CMakeFiles/lab1.dir/candidateNode.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab1.dir/build.make CMakeFiles/lab1.dir/candidateNode.cpp.o.provides.build
.PHONY : CMakeFiles/lab1.dir/candidateNode.cpp.o.provides

CMakeFiles/lab1.dir/candidateNode.cpp.o.provides.build: CMakeFiles/lab1.dir/candidateNode.cpp.o


CMakeFiles/lab1.dir/getTheShortestPath.cpp.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/getTheShortestPath.cpp.o: ../getTheShortestPath.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/Distributed/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lab1.dir/getTheShortestPath.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab1.dir/getTheShortestPath.cpp.o -c /Users/chengu/git/Distributed/lab2/getTheShortestPath.cpp

CMakeFiles/lab1.dir/getTheShortestPath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1.dir/getTheShortestPath.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chengu/git/Distributed/lab2/getTheShortestPath.cpp > CMakeFiles/lab1.dir/getTheShortestPath.cpp.i

CMakeFiles/lab1.dir/getTheShortestPath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1.dir/getTheShortestPath.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chengu/git/Distributed/lab2/getTheShortestPath.cpp -o CMakeFiles/lab1.dir/getTheShortestPath.cpp.s

CMakeFiles/lab1.dir/getTheShortestPath.cpp.o.requires:

.PHONY : CMakeFiles/lab1.dir/getTheShortestPath.cpp.o.requires

CMakeFiles/lab1.dir/getTheShortestPath.cpp.o.provides: CMakeFiles/lab1.dir/getTheShortestPath.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab1.dir/build.make CMakeFiles/lab1.dir/getTheShortestPath.cpp.o.provides.build
.PHONY : CMakeFiles/lab1.dir/getTheShortestPath.cpp.o.provides

CMakeFiles/lab1.dir/getTheShortestPath.cpp.o.provides.build: CMakeFiles/lab1.dir/getTheShortestPath.cpp.o


CMakeFiles/lab1.dir/FileSystem.cpp.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/FileSystem.cpp.o: ../FileSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chengu/git/Distributed/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lab1.dir/FileSystem.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab1.dir/FileSystem.cpp.o -c /Users/chengu/git/Distributed/lab2/FileSystem.cpp

CMakeFiles/lab1.dir/FileSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1.dir/FileSystem.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chengu/git/Distributed/lab2/FileSystem.cpp > CMakeFiles/lab1.dir/FileSystem.cpp.i

CMakeFiles/lab1.dir/FileSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1.dir/FileSystem.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chengu/git/Distributed/lab2/FileSystem.cpp -o CMakeFiles/lab1.dir/FileSystem.cpp.s

CMakeFiles/lab1.dir/FileSystem.cpp.o.requires:

.PHONY : CMakeFiles/lab1.dir/FileSystem.cpp.o.requires

CMakeFiles/lab1.dir/FileSystem.cpp.o.provides: CMakeFiles/lab1.dir/FileSystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab1.dir/build.make CMakeFiles/lab1.dir/FileSystem.cpp.o.provides.build
.PHONY : CMakeFiles/lab1.dir/FileSystem.cpp.o.provides

CMakeFiles/lab1.dir/FileSystem.cpp.o.provides.build: CMakeFiles/lab1.dir/FileSystem.cpp.o


# Object files for target lab1
lab1_OBJECTS = \
"CMakeFiles/lab1.dir/main.cpp.o" \
"CMakeFiles/lab1.dir/frozen.c.o" \
"CMakeFiles/lab1.dir/mongoose.c.o" \
"CMakeFiles/lab1.dir/Graph.cpp.o" \
"CMakeFiles/lab1.dir/candidateNode.cpp.o" \
"CMakeFiles/lab1.dir/getTheShortestPath.cpp.o" \
"CMakeFiles/lab1.dir/FileSystem.cpp.o"

# External object files for target lab1
lab1_EXTERNAL_OBJECTS =

lab1: CMakeFiles/lab1.dir/main.cpp.o
lab1: CMakeFiles/lab1.dir/frozen.c.o
lab1: CMakeFiles/lab1.dir/mongoose.c.o
lab1: CMakeFiles/lab1.dir/Graph.cpp.o
lab1: CMakeFiles/lab1.dir/candidateNode.cpp.o
lab1: CMakeFiles/lab1.dir/getTheShortestPath.cpp.o
lab1: CMakeFiles/lab1.dir/FileSystem.cpp.o
lab1: CMakeFiles/lab1.dir/build.make
lab1: CMakeFiles/lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chengu/git/Distributed/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable lab1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab1.dir/build: lab1

.PHONY : CMakeFiles/lab1.dir/build

CMakeFiles/lab1.dir/requires: CMakeFiles/lab1.dir/main.cpp.o.requires
CMakeFiles/lab1.dir/requires: CMakeFiles/lab1.dir/frozen.c.o.requires
CMakeFiles/lab1.dir/requires: CMakeFiles/lab1.dir/mongoose.c.o.requires
CMakeFiles/lab1.dir/requires: CMakeFiles/lab1.dir/Graph.cpp.o.requires
CMakeFiles/lab1.dir/requires: CMakeFiles/lab1.dir/candidateNode.cpp.o.requires
CMakeFiles/lab1.dir/requires: CMakeFiles/lab1.dir/getTheShortestPath.cpp.o.requires
CMakeFiles/lab1.dir/requires: CMakeFiles/lab1.dir/FileSystem.cpp.o.requires

.PHONY : CMakeFiles/lab1.dir/requires

CMakeFiles/lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab1.dir/clean

CMakeFiles/lab1.dir/depend:
	cd /Users/chengu/git/Distributed/lab2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chengu/git/Distributed/lab2 /Users/chengu/git/Distributed/lab2 /Users/chengu/git/Distributed/lab2/cmake-build-debug /Users/chengu/git/Distributed/lab2/cmake-build-debug /Users/chengu/git/Distributed/lab2/cmake-build-debug/CMakeFiles/lab1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab1.dir/depend
