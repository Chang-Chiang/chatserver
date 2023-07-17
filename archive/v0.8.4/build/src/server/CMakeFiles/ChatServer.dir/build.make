# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build

# Include any dependencies generated for this target.
include src/server/CMakeFiles/ChatServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/server/CMakeFiles/ChatServer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/server/CMakeFiles/ChatServer.dir/progress.make

# Include the compile flags for this target's objects.
include src/server/CMakeFiles/ChatServer.dir/flags.make

src/server/CMakeFiles/ChatServer.dir/chatserver.cpp.o: src/server/CMakeFiles/ChatServer.dir/flags.make
src/server/CMakeFiles/ChatServer.dir/chatserver.cpp.o: ../src/server/chatserver.cpp
src/server/CMakeFiles/ChatServer.dir/chatserver.cpp.o: src/server/CMakeFiles/ChatServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/server/CMakeFiles/ChatServer.dir/chatserver.cpp.o"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/ChatServer.dir/chatserver.cpp.o -MF CMakeFiles/ChatServer.dir/chatserver.cpp.o.d -o CMakeFiles/ChatServer.dir/chatserver.cpp.o -c /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/chatserver.cpp

src/server/CMakeFiles/ChatServer.dir/chatserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatServer.dir/chatserver.cpp.i"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/chatserver.cpp > CMakeFiles/ChatServer.dir/chatserver.cpp.i

src/server/CMakeFiles/ChatServer.dir/chatserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatServer.dir/chatserver.cpp.s"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/chatserver.cpp -o CMakeFiles/ChatServer.dir/chatserver.cpp.s

src/server/CMakeFiles/ChatServer.dir/chatservice.cpp.o: src/server/CMakeFiles/ChatServer.dir/flags.make
src/server/CMakeFiles/ChatServer.dir/chatservice.cpp.o: ../src/server/chatservice.cpp
src/server/CMakeFiles/ChatServer.dir/chatservice.cpp.o: src/server/CMakeFiles/ChatServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/server/CMakeFiles/ChatServer.dir/chatservice.cpp.o"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/ChatServer.dir/chatservice.cpp.o -MF CMakeFiles/ChatServer.dir/chatservice.cpp.o.d -o CMakeFiles/ChatServer.dir/chatservice.cpp.o -c /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/chatservice.cpp

src/server/CMakeFiles/ChatServer.dir/chatservice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatServer.dir/chatservice.cpp.i"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/chatservice.cpp > CMakeFiles/ChatServer.dir/chatservice.cpp.i

src/server/CMakeFiles/ChatServer.dir/chatservice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatServer.dir/chatservice.cpp.s"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/chatservice.cpp -o CMakeFiles/ChatServer.dir/chatservice.cpp.s

src/server/CMakeFiles/ChatServer.dir/main.cpp.o: src/server/CMakeFiles/ChatServer.dir/flags.make
src/server/CMakeFiles/ChatServer.dir/main.cpp.o: ../src/server/main.cpp
src/server/CMakeFiles/ChatServer.dir/main.cpp.o: src/server/CMakeFiles/ChatServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/server/CMakeFiles/ChatServer.dir/main.cpp.o"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/ChatServer.dir/main.cpp.o -MF CMakeFiles/ChatServer.dir/main.cpp.o.d -o CMakeFiles/ChatServer.dir/main.cpp.o -c /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/main.cpp

src/server/CMakeFiles/ChatServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatServer.dir/main.cpp.i"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/main.cpp > CMakeFiles/ChatServer.dir/main.cpp.i

src/server/CMakeFiles/ChatServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatServer.dir/main.cpp.s"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/main.cpp -o CMakeFiles/ChatServer.dir/main.cpp.s

src/server/CMakeFiles/ChatServer.dir/db/db.cpp.o: src/server/CMakeFiles/ChatServer.dir/flags.make
src/server/CMakeFiles/ChatServer.dir/db/db.cpp.o: ../src/server/db/db.cpp
src/server/CMakeFiles/ChatServer.dir/db/db.cpp.o: src/server/CMakeFiles/ChatServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/server/CMakeFiles/ChatServer.dir/db/db.cpp.o"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/ChatServer.dir/db/db.cpp.o -MF CMakeFiles/ChatServer.dir/db/db.cpp.o.d -o CMakeFiles/ChatServer.dir/db/db.cpp.o -c /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/db/db.cpp

src/server/CMakeFiles/ChatServer.dir/db/db.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatServer.dir/db/db.cpp.i"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/db/db.cpp > CMakeFiles/ChatServer.dir/db/db.cpp.i

src/server/CMakeFiles/ChatServer.dir/db/db.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatServer.dir/db/db.cpp.s"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/db/db.cpp -o CMakeFiles/ChatServer.dir/db/db.cpp.s

src/server/CMakeFiles/ChatServer.dir/model/usermodel.cpp.o: src/server/CMakeFiles/ChatServer.dir/flags.make
src/server/CMakeFiles/ChatServer.dir/model/usermodel.cpp.o: ../src/server/model/usermodel.cpp
src/server/CMakeFiles/ChatServer.dir/model/usermodel.cpp.o: src/server/CMakeFiles/ChatServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/server/CMakeFiles/ChatServer.dir/model/usermodel.cpp.o"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/ChatServer.dir/model/usermodel.cpp.o -MF CMakeFiles/ChatServer.dir/model/usermodel.cpp.o.d -o CMakeFiles/ChatServer.dir/model/usermodel.cpp.o -c /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/model/usermodel.cpp

src/server/CMakeFiles/ChatServer.dir/model/usermodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatServer.dir/model/usermodel.cpp.i"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/model/usermodel.cpp > CMakeFiles/ChatServer.dir/model/usermodel.cpp.i

src/server/CMakeFiles/ChatServer.dir/model/usermodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatServer.dir/model/usermodel.cpp.s"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server/model/usermodel.cpp -o CMakeFiles/ChatServer.dir/model/usermodel.cpp.s

# Object files for target ChatServer
ChatServer_OBJECTS = \
"CMakeFiles/ChatServer.dir/chatserver.cpp.o" \
"CMakeFiles/ChatServer.dir/chatservice.cpp.o" \
"CMakeFiles/ChatServer.dir/main.cpp.o" \
"CMakeFiles/ChatServer.dir/db/db.cpp.o" \
"CMakeFiles/ChatServer.dir/model/usermodel.cpp.o"

# External object files for target ChatServer
ChatServer_EXTERNAL_OBJECTS =

../bin/ChatServer: src/server/CMakeFiles/ChatServer.dir/chatserver.cpp.o
../bin/ChatServer: src/server/CMakeFiles/ChatServer.dir/chatservice.cpp.o
../bin/ChatServer: src/server/CMakeFiles/ChatServer.dir/main.cpp.o
../bin/ChatServer: src/server/CMakeFiles/ChatServer.dir/db/db.cpp.o
../bin/ChatServer: src/server/CMakeFiles/ChatServer.dir/model/usermodel.cpp.o
../bin/ChatServer: src/server/CMakeFiles/ChatServer.dir/build.make
../bin/ChatServer: src/server/CMakeFiles/ChatServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../../../bin/ChatServer"
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChatServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/server/CMakeFiles/ChatServer.dir/build: ../bin/ChatServer
.PHONY : src/server/CMakeFiles/ChatServer.dir/build

src/server/CMakeFiles/ChatServer.dir/clean:
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server && $(CMAKE_COMMAND) -P CMakeFiles/ChatServer.dir/cmake_clean.cmake
.PHONY : src/server/CMakeFiles/ChatServer.dir/clean

src/server/CMakeFiles/ChatServer.dir/depend:
	cd /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4 /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/src/server /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server /mnt/e/_cc/GitHub/chatserver/archive/v0.8.4/build/src/server/CMakeFiles/ChatServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/server/CMakeFiles/ChatServer.dir/depend

