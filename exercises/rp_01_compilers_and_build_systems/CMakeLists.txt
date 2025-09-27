cmake_minimum_required(VERSION 2.8.3)
project(mini_core)

# Added -O3 optimization flag
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -pedantic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add project source code
add_subdirectory(src)

# add executables directory
add_subdirectory(executables)

# -> Moved Eigen3-related configuration to src/CMakeLists.txt
