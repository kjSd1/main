# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\_Work\_GitHub\main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\_Work\_GitHub\main\cmake-build-debug

# Include any dependencies generated for this target.
include data_structures/matrix/CMakeFiles/matrix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include data_structures/matrix/CMakeFiles/matrix.dir/compiler_depend.make

# Include the progress variables for this target.
include data_structures/matrix/CMakeFiles/matrix.dir/progress.make

# Include the compile flags for this target's objects.
include data_structures/matrix/CMakeFiles/matrix.dir/flags.make

data_structures/matrix/CMakeFiles/matrix.dir/matrix.c.obj: data_structures/matrix/CMakeFiles/matrix.dir/flags.make
data_structures/matrix/CMakeFiles/matrix.dir/matrix.c.obj: ../data_structures/matrix/matrix.c
data_structures/matrix/CMakeFiles/matrix.dir/matrix.c.obj: data_structures/matrix/CMakeFiles/matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\_Work\_GitHub\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object data_structures/matrix/CMakeFiles/matrix.dir/matrix.c.obj"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\matrix && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT data_structures/matrix/CMakeFiles/matrix.dir/matrix.c.obj -MF CMakeFiles\matrix.dir\matrix.c.obj.d -o CMakeFiles\matrix.dir\matrix.c.obj -c D:\_Work\_GitHub\main\data_structures\matrix\matrix.c

data_structures/matrix/CMakeFiles/matrix.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/matrix.dir/matrix.c.i"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\matrix && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\_Work\_GitHub\main\data_structures\matrix\matrix.c > CMakeFiles\matrix.dir\matrix.c.i

data_structures/matrix/CMakeFiles/matrix.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/matrix.dir/matrix.c.s"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\matrix && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\_Work\_GitHub\main\data_structures\matrix\matrix.c -o CMakeFiles\matrix.dir\matrix.c.s

# Object files for target matrix
matrix_OBJECTS = \
"CMakeFiles/matrix.dir/matrix.c.obj"

# External object files for target matrix
matrix_EXTERNAL_OBJECTS =

data_structures/matrix/libmatrix.a: data_structures/matrix/CMakeFiles/matrix.dir/matrix.c.obj
data_structures/matrix/libmatrix.a: data_structures/matrix/CMakeFiles/matrix.dir/build.make
data_structures/matrix/libmatrix.a: data_structures/matrix/CMakeFiles/matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\_Work\_GitHub\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libmatrix.a"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\matrix && $(CMAKE_COMMAND) -P CMakeFiles\matrix.dir\cmake_clean_target.cmake
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\matrix && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\matrix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
data_structures/matrix/CMakeFiles/matrix.dir/build: data_structures/matrix/libmatrix.a
.PHONY : data_structures/matrix/CMakeFiles/matrix.dir/build

data_structures/matrix/CMakeFiles/matrix.dir/clean:
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\matrix && $(CMAKE_COMMAND) -P CMakeFiles\matrix.dir\cmake_clean.cmake
.PHONY : data_structures/matrix/CMakeFiles/matrix.dir/clean

data_structures/matrix/CMakeFiles/matrix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\_Work\_GitHub\main D:\_Work\_GitHub\main\data_structures\matrix D:\_Work\_GitHub\main\cmake-build-debug D:\_Work\_GitHub\main\cmake-build-debug\data_structures\matrix D:\_Work\_GitHub\main\cmake-build-debug\data_structures\matrix\CMakeFiles\matrix.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : data_structures/matrix/CMakeFiles/matrix.dir/depend

