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
include mod1/CMakeFiles/myMath.dir/depend.make

# Include the progress variables for this target.
include mod1/CMakeFiles/myMath.dir/progress.make

# Include the compile flags for this target's objects.
include mod1/CMakeFiles/myMath.dir/flags.make

mod1/CMakeFiles/myMath.dir/add.o: mod1/CMakeFiles/myMath.dir/flags.make
mod1/CMakeFiles/myMath.dir/add.o: ../mod1/add.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object mod1/CMakeFiles/myMath.dir/add.o"
	cd /home/richard/test1/build/mod1 && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myMath.dir/add.o   -c /home/richard/test1/mod1/add.c

mod1/CMakeFiles/myMath.dir/add.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myMath.dir/add.i"
	cd /home/richard/test1/build/mod1 && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/test1/mod1/add.c > CMakeFiles/myMath.dir/add.i

mod1/CMakeFiles/myMath.dir/add.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myMath.dir/add.s"
	cd /home/richard/test1/build/mod1 && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/test1/mod1/add.c -o CMakeFiles/myMath.dir/add.s

mod1/CMakeFiles/myMath.dir/add.o.requires:

.PHONY : mod1/CMakeFiles/myMath.dir/add.o.requires

mod1/CMakeFiles/myMath.dir/add.o.provides: mod1/CMakeFiles/myMath.dir/add.o.requires
	$(MAKE) -f mod1/CMakeFiles/myMath.dir/build.make mod1/CMakeFiles/myMath.dir/add.o.provides.build
.PHONY : mod1/CMakeFiles/myMath.dir/add.o.provides

mod1/CMakeFiles/myMath.dir/add.o.provides.build: mod1/CMakeFiles/myMath.dir/add.o


# Object files for target myMath
myMath_OBJECTS = \
"CMakeFiles/myMath.dir/add.o"

# External object files for target myMath
myMath_EXTERNAL_OBJECTS =

../lib/libmyMath.so: mod1/CMakeFiles/myMath.dir/add.o
../lib/libmyMath.so: mod1/CMakeFiles/myMath.dir/build.make
../lib/libmyMath.so: mod1/CMakeFiles/myMath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/richard/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library ../../lib/libmyMath.so"
	cd /home/richard/test1/build/mod1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myMath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mod1/CMakeFiles/myMath.dir/build: ../lib/libmyMath.so

.PHONY : mod1/CMakeFiles/myMath.dir/build

mod1/CMakeFiles/myMath.dir/requires: mod1/CMakeFiles/myMath.dir/add.o.requires

.PHONY : mod1/CMakeFiles/myMath.dir/requires

mod1/CMakeFiles/myMath.dir/clean:
	cd /home/richard/test1/build/mod1 && $(CMAKE_COMMAND) -P CMakeFiles/myMath.dir/cmake_clean.cmake
.PHONY : mod1/CMakeFiles/myMath.dir/clean

mod1/CMakeFiles/myMath.dir/depend:
	cd /home/richard/test1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/richard/test1 /home/richard/test1/mod1 /home/richard/test1/build /home/richard/test1/build/mod1 /home/richard/test1/build/mod1/CMakeFiles/myMath.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mod1/CMakeFiles/myMath.dir/depend
