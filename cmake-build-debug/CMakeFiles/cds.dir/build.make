# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\home\opt\CLion\CLion 2020.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\home\opt\CLion\CLion 2020.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\home\code\c\cds

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\home\code\c\cds\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cds.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cds.dir/flags.make

CMakeFiles/cds.dir/tree/bst/main.c.obj: CMakeFiles/cds.dir/flags.make
CMakeFiles/cds.dir/tree/bst/main.c.obj: ../tree/bst/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\home\code\c\cds\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cds.dir/tree/bst/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cds.dir\tree\bst\main.c.obj   -c D:\home\code\c\cds\tree\bst\main.c

CMakeFiles/cds.dir/tree/bst/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cds.dir/tree/bst/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\home\code\c\cds\tree\bst\main.c > CMakeFiles\cds.dir\tree\bst\main.c.i

CMakeFiles/cds.dir/tree/bst/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cds.dir/tree/bst/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\home\code\c\cds\tree\bst\main.c -o CMakeFiles\cds.dir\tree\bst\main.c.s

CMakeFiles/cds.dir/tree/avl/AVL.c.obj: CMakeFiles/cds.dir/flags.make
CMakeFiles/cds.dir/tree/avl/AVL.c.obj: ../tree/avl/AVL.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\home\code\c\cds\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cds.dir/tree/avl/AVL.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cds.dir\tree\avl\AVL.c.obj   -c D:\home\code\c\cds\tree\avl\AVL.c

CMakeFiles/cds.dir/tree/avl/AVL.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cds.dir/tree/avl/AVL.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\home\code\c\cds\tree\avl\AVL.c > CMakeFiles\cds.dir\tree\avl\AVL.c.i

CMakeFiles/cds.dir/tree/avl/AVL.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cds.dir/tree/avl/AVL.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\home\code\c\cds\tree\avl\AVL.c -o CMakeFiles\cds.dir\tree\avl\AVL.c.s

CMakeFiles/cds.dir/tree/avl/main.c.obj: CMakeFiles/cds.dir/flags.make
CMakeFiles/cds.dir/tree/avl/main.c.obj: ../tree/avl/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\home\code\c\cds\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cds.dir/tree/avl/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cds.dir\tree\avl\main.c.obj   -c D:\home\code\c\cds\tree\avl\main.c

CMakeFiles/cds.dir/tree/avl/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cds.dir/tree/avl/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\home\code\c\cds\tree\avl\main.c > CMakeFiles\cds.dir\tree\avl\main.c.i

CMakeFiles/cds.dir/tree/avl/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cds.dir/tree/avl/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\home\code\c\cds\tree\avl\main.c -o CMakeFiles\cds.dir\tree\avl\main.c.s

# Object files for target cds
cds_OBJECTS = \
"CMakeFiles/cds.dir/tree/bst/main.c.obj" \
"CMakeFiles/cds.dir/tree/avl/AVL.c.obj" \
"CMakeFiles/cds.dir/tree/avl/main.c.obj"

# External object files for target cds
cds_EXTERNAL_OBJECTS =

cds.exe: CMakeFiles/cds.dir/tree/bst/main.c.obj
cds.exe: CMakeFiles/cds.dir/tree/avl/AVL.c.obj
cds.exe: CMakeFiles/cds.dir/tree/avl/main.c.obj
cds.exe: CMakeFiles/cds.dir/build.make
cds.exe: CMakeFiles/cds.dir/linklibs.rsp
cds.exe: CMakeFiles/cds.dir/objects1.rsp
cds.exe: CMakeFiles/cds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\home\code\c\cds\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable cds.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cds.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cds.dir/build: cds.exe

.PHONY : CMakeFiles/cds.dir/build

CMakeFiles/cds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cds.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cds.dir/clean

CMakeFiles/cds.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\home\code\c\cds D:\home\code\c\cds D:\home\code\c\cds\cmake-build-debug D:\home\code\c\cds\cmake-build-debug D:\home\code\c\cds\cmake-build-debug\CMakeFiles\cds.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cds.dir/depend

