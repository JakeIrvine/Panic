# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /home/jake/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.6668.86/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jake/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.6668.86/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jake/PanicLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jake/PanicLib/cmake-build-debug

# Include any dependencies generated for this target.
include demo/CMakeFiles/Demo.dir/depend.make

# Include the progress variables for this target.
include demo/CMakeFiles/Demo.dir/progress.make

# Include the compile flags for this target's objects.
include demo/CMakeFiles/Demo.dir/flags.make

demo/CMakeFiles/Demo.dir/main.cpp.o: demo/CMakeFiles/Demo.dir/flags.make
demo/CMakeFiles/Demo.dir/main.cpp.o: ../demo/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jake/PanicLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object demo/CMakeFiles/Demo.dir/main.cpp.o"
	cd /home/jake/PanicLib/cmake-build-debug/demo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Demo.dir/main.cpp.o -c /home/jake/PanicLib/demo/main.cpp

demo/CMakeFiles/Demo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Demo.dir/main.cpp.i"
	cd /home/jake/PanicLib/cmake-build-debug/demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jake/PanicLib/demo/main.cpp > CMakeFiles/Demo.dir/main.cpp.i

demo/CMakeFiles/Demo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Demo.dir/main.cpp.s"
	cd /home/jake/PanicLib/cmake-build-debug/demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jake/PanicLib/demo/main.cpp -o CMakeFiles/Demo.dir/main.cpp.s

# Object files for target Demo
Demo_OBJECTS = \
"CMakeFiles/Demo.dir/main.cpp.o"

# External object files for target Demo
Demo_EXTERNAL_OBJECTS =

demo/Demo: demo/CMakeFiles/Demo.dir/main.cpp.o
demo/Demo: demo/CMakeFiles/Demo.dir/build.make
demo/Demo: libPanic.a
demo/Demo: demo/CMakeFiles/Demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jake/PanicLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Demo"
	cd /home/jake/PanicLib/cmake-build-debug/demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/CMakeFiles/Demo.dir/build: demo/Demo

.PHONY : demo/CMakeFiles/Demo.dir/build

demo/CMakeFiles/Demo.dir/clean:
	cd /home/jake/PanicLib/cmake-build-debug/demo && $(CMAKE_COMMAND) -P CMakeFiles/Demo.dir/cmake_clean.cmake
.PHONY : demo/CMakeFiles/Demo.dir/clean

demo/CMakeFiles/Demo.dir/depend:
	cd /home/jake/PanicLib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jake/PanicLib /home/jake/PanicLib/demo /home/jake/PanicLib/cmake-build-debug /home/jake/PanicLib/cmake-build-debug/demo /home/jake/PanicLib/cmake-build-debug/demo/CMakeFiles/Demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/CMakeFiles/Demo.dir/depend

