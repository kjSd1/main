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
include data_structures/bitset/CMakeFiles/bitset.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include data_structures/bitset/CMakeFiles/bitset.dir/compiler_depend.make

# Include the progress variables for this target.
include data_structures/bitset/CMakeFiles/bitset.dir/progress.make

# Include the compile flags for this target's objects.
include data_structures/bitset/CMakeFiles/bitset.dir/flags.make

data_structures/bitset/CMakeFiles/bitset.dir/bitset.c.obj: data_structures/bitset/CMakeFiles/bitset.dir/flags.make
data_structures/bitset/CMakeFiles/bitset.dir/bitset.c.obj: ../data_structures/bitset/bitset.c
data_structures/bitset/CMakeFiles/bitset.dir/bitset.c.obj: data_structures/bitset/CMakeFiles/bitset.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\_Work\_GitHub\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object data_structures/bitset/CMakeFiles/bitset.dir/bitset.c.obj"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\bitset && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT data_structures/bitset/CMakeFiles/bitset.dir/bitset.c.obj -MF CMakeFiles\bitset.dir\bitset.c.obj.d -o CMakeFiles\bitset.dir\bitset.c.obj -c D:\_Work\_GitHub\main\data_structures\bitset\bitset.c

data_structures/bitset/CMakeFiles/bitset.dir/bitset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bitset.dir/bitset.c.i"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\bitset && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\_Work\_GitHub\main\data_structures\bitset\bitset.c > CMakeFiles\bitset.dir\bitset.c.i

data_structures/bitset/CMakeFiles/bitset.dir/bitset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bitset.dir/bitset.c.s"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\bitset && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\_Work\_GitHub\main\data_structures\bitset\bitset.c -o CMakeFiles\bitset.dir\bitset.c.s

# Object files for target bitset
bitset_OBJECTS = \
"CMakeFiles/bitset.dir/bitset.c.obj"

# External object files for target bitset
bitset_EXTERNAL_OBJECTS =

data_structures/bitset/libbitset.a: data_structures/bitset/CMakeFiles/bitset.dir/bitset.c.obj
data_structures/bitset/libbitset.a: data_structures/bitset/CMakeFiles/bitset.dir/build.make
data_structures/bitset/libbitset.a: data_structures/bitset/CMakeFiles/bitset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\_Work\_GitHub\main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libbitset.a"
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\bitset && $(CMAKE_COMMAND) -P CMakeFiles\bitset.dir\cmake_clean_target.cmake
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\bitset && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bitset.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
data_structures/bitset/CMakeFiles/bitset.dir/build: data_structures/bitset/libbitset.a
.PHONY : data_structures/bitset/CMakeFiles/bitset.dir/build

data_structures/bitset/CMakeFiles/bitset.dir/clean:
	cd /d D:\_Work\_GitHub\main\cmake-build-debug\data_structures\bitset && $(CMAKE_COMMAND) -P CMakeFiles\bitset.dir\cmake_clean.cmake
.PHONY : data_structures/bitset/CMakeFiles/bitset.dir/clean

data_structures/bitset/CMakeFiles/bitset.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\_Work\_GitHub\main D:\_Work\_GitHub\main\data_structures\bitset D:\_Work\_GitHub\main\cmake-build-debug D:\_Work\_GitHub\main\cmake-build-debug\data_structures\bitset D:\_Work\_GitHub\main\cmake-build-debug\data_structures\bitset\CMakeFiles\bitset.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : data_structures/bitset/CMakeFiles/bitset.dir/depend
