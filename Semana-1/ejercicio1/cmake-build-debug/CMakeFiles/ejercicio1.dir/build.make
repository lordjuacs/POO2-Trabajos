# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\J\CLionProjects\POOII\ejercicio1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\J\CLionProjects\POOII\ejercicio1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ejercicio1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ejercicio1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ejercicio1.dir/flags.make

CMakeFiles/ejercicio1.dir/main.cpp.obj: CMakeFiles/ejercicio1.dir/flags.make
CMakeFiles/ejercicio1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\J\CLionProjects\POOII\ejercicio1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ejercicio1.dir/main.cpp.obj"
	C:\Mingw-w64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ejercicio1.dir\main.cpp.obj -c C:\Users\J\CLionProjects\POOII\ejercicio1\main.cpp

CMakeFiles/ejercicio1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejercicio1.dir/main.cpp.i"
	C:\Mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\J\CLionProjects\POOII\ejercicio1\main.cpp > CMakeFiles\ejercicio1.dir\main.cpp.i

CMakeFiles/ejercicio1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejercicio1.dir/main.cpp.s"
	C:\Mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\J\CLionProjects\POOII\ejercicio1\main.cpp -o CMakeFiles\ejercicio1.dir\main.cpp.s

# Object files for target ejercicio1
ejercicio1_OBJECTS = \
"CMakeFiles/ejercicio1.dir/main.cpp.obj"

# External object files for target ejercicio1
ejercicio1_EXTERNAL_OBJECTS =

ejercicio1.exe: CMakeFiles/ejercicio1.dir/main.cpp.obj
ejercicio1.exe: CMakeFiles/ejercicio1.dir/build.make
ejercicio1.exe: CMakeFiles/ejercicio1.dir/linklibs.rsp
ejercicio1.exe: CMakeFiles/ejercicio1.dir/objects1.rsp
ejercicio1.exe: CMakeFiles/ejercicio1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\J\CLionProjects\POOII\ejercicio1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ejercicio1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ejercicio1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ejercicio1.dir/build: ejercicio1.exe

.PHONY : CMakeFiles/ejercicio1.dir/build

CMakeFiles/ejercicio1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ejercicio1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ejercicio1.dir/clean

CMakeFiles/ejercicio1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\J\CLionProjects\POOII\ejercicio1 C:\Users\J\CLionProjects\POOII\ejercicio1 C:\Users\J\CLionProjects\POOII\ejercicio1\cmake-build-debug C:\Users\J\CLionProjects\POOII\ejercicio1\cmake-build-debug C:\Users\J\CLionProjects\POOII\ejercicio1\cmake-build-debug\CMakeFiles\ejercicio1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ejercicio1.dir/depend

