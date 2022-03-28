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

# Utility rule file for brake-size.

# Include the progress variables for this target.
include brake/kia_soul_ev_niro/CMakeFiles/brake-size.dir/progress.make

brake/kia_soul_ev_niro/CMakeFiles/brake-size: brake/kia_soul_ev_niro/brake.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/roman/CLionProjects/oscc/firmware/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Calculating brake image size"
	cd /home/roman/CLionProjects/oscc/firmware/build/brake/kia_soul_ev_niro && /usr/bin/cmake -DFIRMWARE_IMAGE=/home/roman/CLionProjects/oscc/firmware/build/brake/kia_soul_ev_niro/brake.elf -DMCU=atmega328p -DEEPROM_IMAGE=/home/roman/CLionProjects/oscc/firmware/build/brake/kia_soul_ev_niro/brake.eep -P /home/roman/CLionProjects/oscc/firmware/build/CMakeFiles/FirmwareSize.cmake

brake-size: brake/kia_soul_ev_niro/CMakeFiles/brake-size
brake-size: brake/kia_soul_ev_niro/CMakeFiles/brake-size.dir/build.make

.PHONY : brake-size

# Rule to build all files generated by this target.
brake/kia_soul_ev_niro/CMakeFiles/brake-size.dir/build: brake-size

.PHONY : brake/kia_soul_ev_niro/CMakeFiles/brake-size.dir/build

brake/kia_soul_ev_niro/CMakeFiles/brake-size.dir/clean:
	cd /home/roman/CLionProjects/oscc/firmware/build/brake/kia_soul_ev_niro && $(CMAKE_COMMAND) -P CMakeFiles/brake-size.dir/cmake_clean.cmake
.PHONY : brake/kia_soul_ev_niro/CMakeFiles/brake-size.dir/clean

brake/kia_soul_ev_niro/CMakeFiles/brake-size.dir/depend:
	cd /home/roman/CLionProjects/oscc/firmware/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roman/CLionProjects/oscc/firmware /home/roman/CLionProjects/oscc/firmware/brake/kia_soul_ev_niro /home/roman/CLionProjects/oscc/firmware/build /home/roman/CLionProjects/oscc/firmware/build/brake/kia_soul_ev_niro /home/roman/CLionProjects/oscc/firmware/build/brake/kia_soul_ev_niro/CMakeFiles/brake-size.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : brake/kia_soul_ev_niro/CMakeFiles/brake-size.dir/depend

