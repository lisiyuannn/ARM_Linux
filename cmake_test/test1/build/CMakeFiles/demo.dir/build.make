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
CMAKE_SOURCE_DIR = /home/siyuan/ARM_Linux/cmake_test/test1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/siyuan/ARM_Linux/cmake_test/test1/build

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/add.c.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/add.c.o: /home/siyuan/ARM_Linux/cmake_test/test1/add.c
CMakeFiles/demo.dir/add.c.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/siyuan/ARM_Linux/cmake_test/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/demo.dir/add.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/demo.dir/add.c.o -MF CMakeFiles/demo.dir/add.c.o.d -o CMakeFiles/demo.dir/add.c.o -c /home/siyuan/ARM_Linux/cmake_test/test1/add.c

CMakeFiles/demo.dir/add.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/demo.dir/add.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siyuan/ARM_Linux/cmake_test/test1/add.c > CMakeFiles/demo.dir/add.c.i

CMakeFiles/demo.dir/add.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/demo.dir/add.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siyuan/ARM_Linux/cmake_test/test1/add.c -o CMakeFiles/demo.dir/add.c.s

CMakeFiles/demo.dir/div.c.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/div.c.o: /home/siyuan/ARM_Linux/cmake_test/test1/div.c
CMakeFiles/demo.dir/div.c.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/siyuan/ARM_Linux/cmake_test/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/demo.dir/div.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/demo.dir/div.c.o -MF CMakeFiles/demo.dir/div.c.o.d -o CMakeFiles/demo.dir/div.c.o -c /home/siyuan/ARM_Linux/cmake_test/test1/div.c

CMakeFiles/demo.dir/div.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/demo.dir/div.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siyuan/ARM_Linux/cmake_test/test1/div.c > CMakeFiles/demo.dir/div.c.i

CMakeFiles/demo.dir/div.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/demo.dir/div.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siyuan/ARM_Linux/cmake_test/test1/div.c -o CMakeFiles/demo.dir/div.c.s

CMakeFiles/demo.dir/main.c.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/main.c.o: /home/siyuan/ARM_Linux/cmake_test/test1/main.c
CMakeFiles/demo.dir/main.c.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/siyuan/ARM_Linux/cmake_test/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/demo.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/demo.dir/main.c.o -MF CMakeFiles/demo.dir/main.c.o.d -o CMakeFiles/demo.dir/main.c.o -c /home/siyuan/ARM_Linux/cmake_test/test1/main.c

CMakeFiles/demo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/demo.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siyuan/ARM_Linux/cmake_test/test1/main.c > CMakeFiles/demo.dir/main.c.i

CMakeFiles/demo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/demo.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siyuan/ARM_Linux/cmake_test/test1/main.c -o CMakeFiles/demo.dir/main.c.s

CMakeFiles/demo.dir/mul.c.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/mul.c.o: /home/siyuan/ARM_Linux/cmake_test/test1/mul.c
CMakeFiles/demo.dir/mul.c.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/siyuan/ARM_Linux/cmake_test/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/demo.dir/mul.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/demo.dir/mul.c.o -MF CMakeFiles/demo.dir/mul.c.o.d -o CMakeFiles/demo.dir/mul.c.o -c /home/siyuan/ARM_Linux/cmake_test/test1/mul.c

CMakeFiles/demo.dir/mul.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/demo.dir/mul.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siyuan/ARM_Linux/cmake_test/test1/mul.c > CMakeFiles/demo.dir/mul.c.i

CMakeFiles/demo.dir/mul.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/demo.dir/mul.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siyuan/ARM_Linux/cmake_test/test1/mul.c -o CMakeFiles/demo.dir/mul.c.s

CMakeFiles/demo.dir/sub.c.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/sub.c.o: /home/siyuan/ARM_Linux/cmake_test/test1/sub.c
CMakeFiles/demo.dir/sub.c.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/siyuan/ARM_Linux/cmake_test/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/demo.dir/sub.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/demo.dir/sub.c.o -MF CMakeFiles/demo.dir/sub.c.o.d -o CMakeFiles/demo.dir/sub.c.o -c /home/siyuan/ARM_Linux/cmake_test/test1/sub.c

CMakeFiles/demo.dir/sub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/demo.dir/sub.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siyuan/ARM_Linux/cmake_test/test1/sub.c > CMakeFiles/demo.dir/sub.c.i

CMakeFiles/demo.dir/sub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/demo.dir/sub.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siyuan/ARM_Linux/cmake_test/test1/sub.c -o CMakeFiles/demo.dir/sub.c.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/add.c.o" \
"CMakeFiles/demo.dir/div.c.o" \
"CMakeFiles/demo.dir/main.c.o" \
"CMakeFiles/demo.dir/mul.c.o" \
"CMakeFiles/demo.dir/sub.c.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

/home/siyuan/ARM_Linux/cmake_test/test1/demo: CMakeFiles/demo.dir/add.c.o
/home/siyuan/ARM_Linux/cmake_test/test1/demo: CMakeFiles/demo.dir/div.c.o
/home/siyuan/ARM_Linux/cmake_test/test1/demo: CMakeFiles/demo.dir/main.c.o
/home/siyuan/ARM_Linux/cmake_test/test1/demo: CMakeFiles/demo.dir/mul.c.o
/home/siyuan/ARM_Linux/cmake_test/test1/demo: CMakeFiles/demo.dir/sub.c.o
/home/siyuan/ARM_Linux/cmake_test/test1/demo: CMakeFiles/demo.dir/build.make
/home/siyuan/ARM_Linux/cmake_test/test1/demo: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/siyuan/ARM_Linux/cmake_test/test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable /home/siyuan/ARM_Linux/cmake_test/test1/demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: /home/siyuan/ARM_Linux/cmake_test/test1/demo
.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd /home/siyuan/ARM_Linux/cmake_test/test1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/siyuan/ARM_Linux/cmake_test/test1 /home/siyuan/ARM_Linux/cmake_test/test1 /home/siyuan/ARM_Linux/cmake_test/test1/build /home/siyuan/ARM_Linux/cmake_test/test1/build /home/siyuan/ARM_Linux/cmake_test/test1/build/CMakeFiles/demo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/demo.dir/depend

