# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/roman/CLionProjects/oscc/firmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roman/CLionProjects/oscc/firmware/build

# Utility rule file for steering-monitor.

# Include the progress variables for this target.
include steering/CMakeFiles/steering-monitor.dir/progress.make

steering/CMakeFiles/steering-monitor:
	cd /home/roman/CLionProjects/oscc/firmware/build/steering && screen /dev/ttyACM0 115200

steering-monitor: steering/CMakeFiles/steering-monitor
steering-monitor: steering/CMakeFiles/steering-monitor.dir/build.make

.PHONY : steering-monitor

# Rule to build all files generated by this target.
steering/CMakeFiles/steering-monitor.dir/build: steering-monitor

.PHONY : steering/CMakeFiles/steering-monitor.dir/build

steering/CMakeFiles/steering-monitor.dir/clean:
	cd /home/roman/CLionProjects/oscc/firmware/build/steering && $(CMAKE_COMMAND) -P CMakeFiles/steering-monitor.dir/cmake_clean.cmake
.PHONY : steering/CMakeFiles/steering-monitor.dir/clean

steering/CMakeFiles/steering-monitor.dir/depend:
	cd /home/roman/CLionProjects/oscc/firmware/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roman/CLionProjects/oscc/firmware /home/roman/CLionProjects/oscc/firmware/steering /home/roman/CLionProjects/oscc/firmware/build /home/roman/CLionProjects/oscc/firmware/build/steering /home/roman/CLionProjects/oscc/firmware/build/steering/CMakeFiles/steering-monitor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : steering/CMakeFiles/steering-monitor.dir/depend

