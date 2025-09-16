cmake_minimum_required(VERSION 3.14)
project(wordle-sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Engine library
add_library(wordle_engine
    src/engine/wordle_engine.cpp
    src/engine/utils.cpp
    src/dictionary.cpp
)
target_include_directories(wordle_engine PUBLIC include)

# Solver library
add_library(wordle_solver
    src/solver/random_solver.cpp
    src/solver/frequency_solver.cpp
)
target_include_directories(wordle_solver PUBLIC include)
target_link_libraries(wordle_solver PRIVATE wordle_engine)

# Simulator library
add_library(wordle_simulator
    src/simulator/simulator.cpp
)
target_include_directories(wordle_simulator PUBLIC include)
target_link_libraries(wordle_simulator PRIVATE wordle_engine wordle_solver)

# Main executable
add_executable(wordle_sim src/main.cpp)
target_link_libraries(wordle_sim PRIVATE wordle_engine wordle_solver wordle_simulator)

# Wordle Executable
add_executable(wordle_cli src/wordle.cpp)
target_link_libraries(wordle_cli PRIVATE wordle_engine)

## Testing framework
include(FetchContent)

# Fetch GoogleTest from GitHub
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Prevent gtest from overriding our compiler flags
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test target
enable_testing()
add_executable(test_wordle_engine tests/test_wordle_engine.cpp)
target_link_libraries(test_wordle_engine PRIVATE wordle_engine gtest_main)

include(GoogleTest)
gtest_discover_tests(test_wordle_engine)
