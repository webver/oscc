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

# Include any dependencies generated for this target.
include null/CMakeFiles/null.dir/depend.make

# Include the progress variables for this target.
include null/CMakeFiles/null.dir/progress.make

# Include the compile flags for this target's objects.
include null/CMakeFiles/null.dir/flags.make

null/CMakeFiles/null.dir/main.cpp.obj: null/CMakeFiles/null.dir/flags.make
null/CMakeFiles/null.dir/main.cpp.obj: ../null/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roman/CLionProjects/oscc/firmware/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object null/CMakeFiles/null.dir/main.cpp.obj"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && /usr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/null.dir/main.cpp.obj -c /home/roman/CLionProjects/oscc/firmware/null/main.cpp

null/CMakeFiles/null.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/null.dir/main.cpp.i"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && /usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roman/CLionProjects/oscc/firmware/null/main.cpp > CMakeFiles/null.dir/main.cpp.i

null/CMakeFiles/null.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/null.dir/main.cpp.s"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && /usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roman/CLionProjects/oscc/firmware/null/main.cpp -o CMakeFiles/null.dir/main.cpp.s

null/CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.obj: null/CMakeFiles/null.dir/flags.make
null/CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.obj: ../common/libs/arduino_init/arduino_init.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roman/CLionProjects/oscc/firmware/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object null/CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.obj"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && /usr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.obj -c /home/roman/CLionProjects/oscc/firmware/common/libs/arduino_init/arduino_init.cpp

null/CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.i"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && /usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roman/CLionProjects/oscc/firmware/common/libs/arduino_init/arduino_init.cpp > CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.i

null/CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.s"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && /usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roman/CLionProjects/oscc/firmware/common/libs/arduino_init/arduino_init.cpp -o CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.s

# Object files for target null
null_OBJECTS = \
"CMakeFiles/null.dir/main.cpp.obj" \
"CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.obj"

# External object files for target null
null_EXTERNAL_OBJECTS =

null/null.elf: null/CMakeFiles/null.dir/main.cpp.obj
null/null.elf: null/CMakeFiles/null.dir/__/common/libs/arduino_init/arduino_init.cpp.obj
null/null.elf: null/CMakeFiles/null.dir/build.make
null/null.elf: brake/kia_soul_ev_niro/libuno_CORE.a
null/null.elf: null/CMakeFiles/null.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/roman/CLionProjects/oscc/firmware/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable null.elf"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/null.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating EEP image"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && /usr/bin/avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 /home/roman/CLionProjects/oscc/firmware/build/null/null.elf /home/roman/CLionProjects/oscc/firmware/build/null/null.eep
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating HEX image"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && /usr/bin/avr-objcopy -O ihex -R .eeprom /home/roman/CLionProjects/oscc/firmware/build/null/null.elf /home/roman/CLionProjects/oscc/firmware/build/null/null.hex
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Calculating image size"
	cd /home/roman/CLionProjects/oscc/firmware/build/null && /usr/bin/cmake -DFIRMWARE_IMAGE=/home/roman/CLionProjects/oscc/firmware/build/null/null.elf -DMCU=atmega328p -DEEPROM_IMAGE=/home/roman/CLionProjects/oscc/firmware/build/null/null.eep -P /home/roman/CLionProjects/oscc/firmware/build/CMakeFiles/FirmwareSize.cmake

# Rule to build all files generated by this target.
null/CMakeFiles/null.dir/build: null/null.elf

.PHONY : null/CMakeFiles/null.dir/build

null/CMakeFiles/null.dir/clean:
	cd /home/roman/CLionProjects/oscc/firmware/build/null && $(CMAKE_COMMAND) -P CMakeFiles/null.dir/cmake_clean.cmake
.PHONY : null/CMakeFiles/null.dir/clean

null/CMakeFiles/null.dir/depend:
	cd /home/roman/CLionProjects/oscc/firmware/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roman/CLionProjects/oscc/firmware /home/roman/CLionProjects/oscc/firmware/null /home/roman/CLionProjects/oscc/firmware/build /home/roman/CLionProjects/oscc/firmware/build/null /home/roman/CLionProjects/oscc/firmware/build/null/CMakeFiles/null.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : null/CMakeFiles/null.dir/depend

