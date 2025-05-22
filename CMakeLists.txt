cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(MyProject)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Main executable (exclude unit_test.cpp)
file(GLOB MAIN_SOURCES "*.cpp")
list(REMOVE_ITEM MAIN_SOURCES "${CMAKE_SOURCE_DIR}/unit_test.cpp")
add_executable(ObjektinisProgramavimas ${MAIN_SOURCES})

# Unit test executable
add_executable(unit_test unit_test.cpp)
target_link_libraries(unit_test gtest gtest_main)

# Optionally, add tests for CTest
add_test(NAME unit_test COMMAND unit_test)