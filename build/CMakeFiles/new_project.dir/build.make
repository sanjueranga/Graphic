# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/build"

# Include any dependencies generated for this target.
include CMakeFiles/new_project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/new_project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/new_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/new_project.dir/flags.make

CMakeFiles/new_project.dir/src/main.cpp.o: CMakeFiles/new_project.dir/flags.make
CMakeFiles/new_project.dir/src/main.cpp.o: /mnt/sda2/Academics/2\ SEM/Graphic/programming/Code/src/main.cpp
CMakeFiles/new_project.dir/src/main.cpp.o: CMakeFiles/new_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/new_project.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/new_project.dir/src/main.cpp.o -MF CMakeFiles/new_project.dir/src/main.cpp.o.d -o CMakeFiles/new_project.dir/src/main.cpp.o -c "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/src/main.cpp"

CMakeFiles/new_project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/new_project.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/src/main.cpp" > CMakeFiles/new_project.dir/src/main.cpp.i

CMakeFiles/new_project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/new_project.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/src/main.cpp" -o CMakeFiles/new_project.dir/src/main.cpp.s

# Object files for target new_project
new_project_OBJECTS = \
"CMakeFiles/new_project.dir/src/main.cpp.o"

# External object files for target new_project
new_project_EXTERNAL_OBJECTS =

new_project: CMakeFiles/new_project.dir/src/main.cpp.o
new_project: CMakeFiles/new_project.dir/build.make
new_project: /usr/lib/x86_64-linux-gnu/libGL.so
new_project: /usr/lib/x86_64-linux-gnu/libglut.so
new_project: CMakeFiles/new_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable new_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/new_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/new_project.dir/build: new_project
.PHONY : CMakeFiles/new_project.dir/build

CMakeFiles/new_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/new_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/new_project.dir/clean

CMakeFiles/new_project.dir/depend:
	cd "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code" "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code" "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/build" "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/build" "/mnt/sda2/Academics/2 SEM/Graphic/programming/Code/build/CMakeFiles/new_project.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/new_project.dir/depend
