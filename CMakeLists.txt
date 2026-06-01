cmake_minimum_required(VERSION 3.14)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Logic Library
add_library(tic_tac_toe_logic src/tic_tac_toe_logic.cpp)
target_include_directories(tic_tac_toe_logic PUBLIC include)

# Main Executable
add_executable(tic_tac_toe src/tic_tac_toe.cpp)
target_link_libraries(tic_tac_toe PRIVATE tic_tac_toe_logic)

# Tests
enable_testing()
add_executable(tic_tac_toe_tests tests/tic_tac_toe_tests.cpp)
target_link_libraries(tic_tac_toe_tests PRIVATE tic_tac_toe_logic GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tic_tac_toe_tests)
