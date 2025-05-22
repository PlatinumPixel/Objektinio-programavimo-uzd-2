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
add_executable(ObjektinisProgramavimas ${MAIN_SOURCES})
target_link_libraries(ObjektinisProgramavimas gtest gtest_main)
