# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jayesh\ClionProjects\FibHeap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jayesh\ClionProjects\FibHeap\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/keywordcounter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/keywordcounter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/keywordcounter.dir/flags.make

CMakeFiles/keywordcounter.dir/main.cpp.obj: CMakeFiles/keywordcounter.dir/flags.make
CMakeFiles/keywordcounter.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jayesh\ClionProjects\FibHeap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/keywordcounter.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\keywordcounter.dir\main.cpp.obj -c C:\Users\jayesh\ClionProjects\FibHeap\main.cpp

CMakeFiles/keywordcounter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/keywordcounter.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jayesh\ClionProjects\FibHeap\main.cpp > CMakeFiles\keywordcounter.dir\main.cpp.i

CMakeFiles/keywordcounter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/keywordcounter.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jayesh\ClionProjects\FibHeap\main.cpp -o CMakeFiles\keywordcounter.dir\main.cpp.s

CMakeFiles/keywordcounter.dir/fibheap.cpp.obj: CMakeFiles/keywordcounter.dir/flags.make
CMakeFiles/keywordcounter.dir/fibheap.cpp.obj: ../fibheap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jayesh\ClionProjects\FibHeap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/keywordcounter.dir/fibheap.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\keywordcounter.dir\fibheap.cpp.obj -c C:\Users\jayesh\ClionProjects\FibHeap\fibheap.cpp

CMakeFiles/keywordcounter.dir/fibheap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/keywordcounter.dir/fibheap.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jayesh\ClionProjects\FibHeap\fibheap.cpp > CMakeFiles\keywordcounter.dir\fibheap.cpp.i

CMakeFiles/keywordcounter.dir/fibheap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/keywordcounter.dir/fibheap.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jayesh\ClionProjects\FibHeap\fibheap.cpp -o CMakeFiles\keywordcounter.dir\fibheap.cpp.s

# Object files for target keywordcounter
keywordcounter_OBJECTS = \
"CMakeFiles/keywordcounter.dir/main.cpp.obj" \
"CMakeFiles/keywordcounter.dir/fibheap.cpp.obj"

# External object files for target keywordcounter
keywordcounter_EXTERNAL_OBJECTS =

keywordcounter.exe: CMakeFiles/keywordcounter.dir/main.cpp.obj
keywordcounter.exe: CMakeFiles/keywordcounter.dir/fibheap.cpp.obj
keywordcounter.exe: CMakeFiles/keywordcounter.dir/build.make
keywordcounter.exe: CMakeFiles/keywordcounter.dir/linklibs.rsp
keywordcounter.exe: CMakeFiles/keywordcounter.dir/objects1.rsp
keywordcounter.exe: CMakeFiles/keywordcounter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jayesh\ClionProjects\FibHeap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable keywordcounter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\keywordcounter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/keywordcounter.dir/build: keywordcounter.exe

.PHONY : CMakeFiles/keywordcounter.dir/build

CMakeFiles/keywordcounter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\keywordcounter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/keywordcounter.dir/clean

CMakeFiles/keywordcounter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jayesh\ClionProjects\FibHeap C:\Users\jayesh\ClionProjects\FibHeap C:\Users\jayesh\ClionProjects\FibHeap\cmake-build-debug C:\Users\jayesh\ClionProjects\FibHeap\cmake-build-debug C:\Users\jayesh\ClionProjects\FibHeap\cmake-build-debug\CMakeFiles\keywordcounter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/keywordcounter.dir/depend

