# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "D:\JetBrains\CLion 2024.3.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\JetBrains\CLion 2024.3.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Defend_The_Spire.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Defend_The_Spire.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Defend_The_Spire.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Defend_The_Spire.dir/flags.make

CMakeFiles/Defend_The_Spire.dir/main.c.obj: CMakeFiles/Defend_The_Spire.dir/flags.make
CMakeFiles/Defend_The_Spire.dir/main.c.obj: CMakeFiles/Defend_The_Spire.dir/includes_C.rsp
CMakeFiles/Defend_The_Spire.dir/main.c.obj: C:/Users/LENOVO-2022/Documents/GitHub/Defend_The_Spire/main.c
CMakeFiles/Defend_The_Spire.dir/main.c.obj: CMakeFiles/Defend_The_Spire.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Defend_The_Spire.dir/main.c.obj"
	D:\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Defend_The_Spire.dir/main.c.obj -MF CMakeFiles\Defend_The_Spire.dir\main.c.obj.d -o CMakeFiles\Defend_The_Spire.dir\main.c.obj -c C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire\main.c

CMakeFiles/Defend_The_Spire.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Defend_The_Spire.dir/main.c.i"
	D:\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire\main.c > CMakeFiles\Defend_The_Spire.dir\main.c.i

CMakeFiles/Defend_The_Spire.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Defend_The_Spire.dir/main.c.s"
	D:\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire\main.c -o CMakeFiles\Defend_The_Spire.dir\main.c.s

# Object files for target Defend_The_Spire
Defend_The_Spire_OBJECTS = \
"CMakeFiles/Defend_The_Spire.dir/main.c.obj"

# External object files for target Defend_The_Spire
Defend_The_Spire_EXTERNAL_OBJECTS =

Defend_The_Spire.exe: CMakeFiles/Defend_The_Spire.dir/main.c.obj
Defend_The_Spire.exe: CMakeFiles/Defend_The_Spire.dir/build.make
Defend_The_Spire.exe: CMakeFiles/Defend_The_Spire.dir/linkLibs.rsp
Defend_The_Spire.exe: CMakeFiles/Defend_The_Spire.dir/objects1.rsp
Defend_The_Spire.exe: CMakeFiles/Defend_The_Spire.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Defend_The_Spire.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Defend_The_Spire.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Defend_The_Spire.dir/build: Defend_The_Spire.exe
.PHONY : CMakeFiles/Defend_The_Spire.dir/build

CMakeFiles/Defend_The_Spire.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Defend_The_Spire.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Defend_The_Spire.dir/clean

CMakeFiles/Defend_The_Spire.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire\cmake-build-debug C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire\cmake-build-debug C:\Users\LENOVO-2022\Documents\GitHub\Defend_The_Spire\cmake-build-debug\CMakeFiles\Defend_The_Spire.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Defend_The_Spire.dir/depend

