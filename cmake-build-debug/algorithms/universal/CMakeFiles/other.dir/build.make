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
include algorithms/universal/CMakeFiles/other.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include algorithms/universal/CMakeFiles/other.dir/compiler_depend.make

# Include the progress variables for this target.
include algorithms/universal/CMakeFiles/other.dir/progress.make

# Include the compile flags for this target's objects.
include algorithms/universal/CMakeFiles/other.dir/flags.make

algorithms/universal/CMakeFiles/other.dir/universal.c.obj: algorithms/universal/CMakeFiles/other.dir/flags.make
algorithms/universal/CMakeFiles/other.dir/universal.c.obj: ../algorithms/universal/universal.c
algorithms/universal/CMakeFiles/other.dir/universal.c.obj: algorithms/universal/CMakeFiles/other.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\_Work\_GitHub\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object algorithms/universal/CMakeFiles/other.dir/universal.c.obj"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\algorithms\universal && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT algorithms/universal/CMakeFiles/other.dir/universal.c.obj -MF CMakeFiles\other.dir\universal.c.obj.d -o CMakeFiles\other.dir\universal.c.obj -c D:\_Work\_GitHub\main\algorithms\universal\universal.c

algorithms/universal/CMakeFiles/other.dir/universal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/other.dir/universal.c.i"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\algorithms\universal && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\_Work\_GitHub\main\algorithms\universal\universal.c > CMakeFiles\other.dir\universal.c.i

algorithms/universal/CMakeFiles/other.dir/universal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/other.dir/universal.c.s"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\algorithms\universal && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\_Work\_GitHub\main\algorithms\universal\universal.c -o CMakeFiles\other.dir\universal.c.s

# Object files for target other
other_OBJECTS = \
"CMakeFiles/other.dir/universal.c.obj"

# External object files for target other
other_EXTERNAL_OBJECTS =

algorithms/universal/libother.a: algorithms/universal/CMakeFiles/other.dir/universal.c.obj
algorithms/universal/libother.a: algorithms/universal/CMakeFiles/other.dir/build.make
algorithms/universal/libother.a: algorithms/universal/CMakeFiles/other.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\_Work\_GitHub\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libother.a"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\algorithms\universal && $(CMAKE_COMMAND) -P CMakeFiles\other.dir\cmake_clean_target.cmake
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\algorithms\universal && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\other.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
algorithms/universal/CMakeFiles/other.dir/build: algorithms/universal/libother.a
.PHONY : algorithms/universal/CMakeFiles/other.dir/build

algorithms/universal/CMakeFiles/other.dir/clean:
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\algorithms\universal && $(CMAKE_COMMAND) -P CMakeFiles\other.dir\cmake_clean.cmake
.PHONY : algorithms/universal/CMakeFiles/other.dir/clean

algorithms/universal/CMakeFiles/other.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\_Work\_GitHub\main D:\_Work\_GitHub\main\algorithms\universal D:\_Work\_GitHub\main\cmake-build-debug D:\_Work\_GitHub\main\cmake-build-debug\algorithms\universal D:\_Work\_GitHub\main\cmake-build-debug\algorithms\universal\CMakeFiles\other.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : algorithms/universal/CMakeFiles/other.dir/depend

