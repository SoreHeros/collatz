# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Heros\CLionProjects\3n+1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Heros\CLionProjects\3n+1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3n_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/3n_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/3n_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3n_1.dir/flags.make

CMakeFiles/3n_1.dir/main.c.obj: CMakeFiles/3n_1.dir/flags.make
CMakeFiles/3n_1.dir/main.c.obj: C:/Users/Heros/CLionProjects/3n+1/main.c
CMakeFiles/3n_1.dir/main.c.obj: CMakeFiles/3n_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Heros\CLionProjects\3n+1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/3n_1.dir/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/3n_1.dir/main.c.obj -MF CMakeFiles\3n_1.dir\main.c.obj.d -o CMakeFiles\3n_1.dir\main.c.obj -c C:\Users\Heros\CLionProjects\3n+1\main.c

CMakeFiles/3n_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/3n_1.dir/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Heros\CLionProjects\3n+1\main.c > CMakeFiles\3n_1.dir\main.c.i

CMakeFiles/3n_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/3n_1.dir/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Heros\CLionProjects\3n+1\main.c -o CMakeFiles\3n_1.dir\main.c.s

CMakeFiles/3n_1.dir/ABB.c.obj: CMakeFiles/3n_1.dir/flags.make
CMakeFiles/3n_1.dir/ABB.c.obj: C:/Users/Heros/CLionProjects/3n+1/ABB.c
CMakeFiles/3n_1.dir/ABB.c.obj: CMakeFiles/3n_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Heros\CLionProjects\3n+1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/3n_1.dir/ABB.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/3n_1.dir/ABB.c.obj -MF CMakeFiles\3n_1.dir\ABB.c.obj.d -o CMakeFiles\3n_1.dir\ABB.c.obj -c C:\Users\Heros\CLionProjects\3n+1\ABB.c

CMakeFiles/3n_1.dir/ABB.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/3n_1.dir/ABB.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Heros\CLionProjects\3n+1\ABB.c > CMakeFiles\3n_1.dir\ABB.c.i

CMakeFiles/3n_1.dir/ABB.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/3n_1.dir/ABB.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Heros\CLionProjects\3n+1\ABB.c -o CMakeFiles\3n_1.dir\ABB.c.s

# Object files for target 3n_1
3n_1_OBJECTS = \
"CMakeFiles/3n_1.dir/main.c.obj" \
"CMakeFiles/3n_1.dir/ABB.c.obj"

# External object files for target 3n_1
3n_1_EXTERNAL_OBJECTS =

3n_1.exe: CMakeFiles/3n_1.dir/main.c.obj
3n_1.exe: CMakeFiles/3n_1.dir/ABB.c.obj
3n_1.exe: CMakeFiles/3n_1.dir/build.make
3n_1.exe: CMakeFiles/3n_1.dir/linkLibs.rsp
3n_1.exe: CMakeFiles/3n_1.dir/objects1.rsp
3n_1.exe: CMakeFiles/3n_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Heros\CLionProjects\3n+1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 3n_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\3n_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3n_1.dir/build: 3n_1.exe
.PHONY : CMakeFiles/3n_1.dir/build

CMakeFiles/3n_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3n_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/3n_1.dir/clean

CMakeFiles/3n_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Heros\CLionProjects\3n+1 C:\Users\Heros\CLionProjects\3n+1 C:\Users\Heros\CLionProjects\3n+1\cmake-build-debug C:\Users\Heros\CLionProjects\3n+1\cmake-build-debug C:\Users\Heros\CLionProjects\3n+1\cmake-build-debug\CMakeFiles\3n_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3n_1.dir/depend

