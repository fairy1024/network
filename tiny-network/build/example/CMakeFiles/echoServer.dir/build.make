# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shang/code/C++/github-project/student-work-project/my-muduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shang/code/C++/github-project/student-work-project/my-muduo/build

# Include any dependencies generated for this target.
include example/CMakeFiles/echoServer.dir/depend.make

# Include the progress variables for this target.
include example/CMakeFiles/echoServer.dir/progress.make

# Include the compile flags for this target's objects.
include example/CMakeFiles/echoServer.dir/flags.make

example/CMakeFiles/echoServer.dir/echoServer.cc.o: example/CMakeFiles/echoServer.dir/flags.make
example/CMakeFiles/echoServer.dir/echoServer.cc.o: ../example/echoServer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shang/code/C++/github-project/student-work-project/my-muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/CMakeFiles/echoServer.dir/echoServer.cc.o"
	cd /home/shang/code/C++/github-project/student-work-project/my-muduo/build/example && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/echoServer.dir/echoServer.cc.o -c /home/shang/code/C++/github-project/student-work-project/my-muduo/example/echoServer.cc

example/CMakeFiles/echoServer.dir/echoServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/echoServer.dir/echoServer.cc.i"
	cd /home/shang/code/C++/github-project/student-work-project/my-muduo/build/example && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shang/code/C++/github-project/student-work-project/my-muduo/example/echoServer.cc > CMakeFiles/echoServer.dir/echoServer.cc.i

example/CMakeFiles/echoServer.dir/echoServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/echoServer.dir/echoServer.cc.s"
	cd /home/shang/code/C++/github-project/student-work-project/my-muduo/build/example && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shang/code/C++/github-project/student-work-project/my-muduo/example/echoServer.cc -o CMakeFiles/echoServer.dir/echoServer.cc.s

example/CMakeFiles/echoServer.dir/echoServer.cc.o.requires:

.PHONY : example/CMakeFiles/echoServer.dir/echoServer.cc.o.requires

example/CMakeFiles/echoServer.dir/echoServer.cc.o.provides: example/CMakeFiles/echoServer.dir/echoServer.cc.o.requires
	$(MAKE) -f example/CMakeFiles/echoServer.dir/build.make example/CMakeFiles/echoServer.dir/echoServer.cc.o.provides.build
.PHONY : example/CMakeFiles/echoServer.dir/echoServer.cc.o.provides

example/CMakeFiles/echoServer.dir/echoServer.cc.o.provides.build: example/CMakeFiles/echoServer.dir/echoServer.cc.o


# Object files for target echoServer
echoServer_OBJECTS = \
"CMakeFiles/echoServer.dir/echoServer.cc.o"

# External object files for target echoServer
echoServer_EXTERNAL_OBJECTS =

../example/echoServer: example/CMakeFiles/echoServer.dir/echoServer.cc.o
../example/echoServer: example/CMakeFiles/echoServer.dir/build.make
../example/echoServer: ../lib/libtiny_network.so
../example/echoServer: example/CMakeFiles/echoServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shang/code/C++/github-project/student-work-project/my-muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../example/echoServer"
	cd /home/shang/code/C++/github-project/student-work-project/my-muduo/build/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echoServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/CMakeFiles/echoServer.dir/build: ../example/echoServer

.PHONY : example/CMakeFiles/echoServer.dir/build

example/CMakeFiles/echoServer.dir/requires: example/CMakeFiles/echoServer.dir/echoServer.cc.o.requires

.PHONY : example/CMakeFiles/echoServer.dir/requires

example/CMakeFiles/echoServer.dir/clean:
	cd /home/shang/code/C++/github-project/student-work-project/my-muduo/build/example && $(CMAKE_COMMAND) -P CMakeFiles/echoServer.dir/cmake_clean.cmake
.PHONY : example/CMakeFiles/echoServer.dir/clean

example/CMakeFiles/echoServer.dir/depend:
	cd /home/shang/code/C++/github-project/student-work-project/my-muduo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shang/code/C++/github-project/student-work-project/my-muduo /home/shang/code/C++/github-project/student-work-project/my-muduo/example /home/shang/code/C++/github-project/student-work-project/my-muduo/build /home/shang/code/C++/github-project/student-work-project/my-muduo/build/example /home/shang/code/C++/github-project/student-work-project/my-muduo/build/example/CMakeFiles/echoServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/CMakeFiles/echoServer.dir/depend

