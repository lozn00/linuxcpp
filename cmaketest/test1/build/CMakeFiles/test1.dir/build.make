# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/richard/test1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/richard/test1/build

# Include any dependencies generated for this target.
include CMakeFiles/test1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test1.dir/flags.make

CMakeFiles/test1.dir/src/main.o: CMakeFiles/test1.dir/flags.make
CMakeFiles/test1.dir/src/main.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test1.dir/src/main.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test1.dir/src/main.o   -c /home/richard/test1/src/main.c

CMakeFiles/test1.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test1.dir/src/main.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/test1/src/main.c > CMakeFiles/test1.dir/src/main.i

CMakeFiles/test1.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test1.dir/src/main.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/test1/src/main.c -o CMakeFiles/test1.dir/src/main.s

CMakeFiles/test1.dir/src/main.o.requires:

.PHONY : CMakeFiles/test1.dir/src/main.o.requires

CMakeFiles/test1.dir/src/main.o.provides: CMakeFiles/test1.dir/src/main.o.requires
	$(MAKE) -f CMakeFiles/test1.dir/build.make CMakeFiles/test1.dir/src/main.o.provides.build
.PHONY : CMakeFiles/test1.dir/src/main.o.provides

CMakeFiles/test1.dir/src/main.o.provides.build: CMakeFiles/test1.dir/src/main.o


# Object files for target test1
test1_OBJECTS = \
"CMakeFiles/test1.dir/src/main.o"

# External object files for target test1
test1_EXTERNAL_OBJECTS =

../bin/test1: CMakeFiles/test1.dir/src/main.o
../bin/test1: CMakeFiles/test1.dir/build.make
../bin/test1: ../lib/libmyMath.so
../bin/test1: CMakeFiles/test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/richard/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/test1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test1.dir/build: ../bin/test1

.PHONY : CMakeFiles/test1.dir/build

CMakeFiles/test1.dir/requires: CMakeFiles/test1.dir/src/main.o.requires

.PHONY : CMakeFiles/test1.dir/requires

CMakeFiles/test1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test1.dir/clean

CMakeFiles/test1.dir/depend:
	cd /home/richard/test1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/richard/test1 /home/richard/test1 /home/richard/test1/build /home/richard/test1/build /home/richard/test1/build/CMakeFiles/test1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test1.dir/depend
