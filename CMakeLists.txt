cmake_minimum_required(VERSION 3.15)
project(Numerical_Linear_Algebra LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add src directory
add_subdirectory(src)

# Add GoogleTest as a submodule
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/third_party/google_test)
if(NOT EXISTS ${GOOGLETEST_DIR}/CMakeLists.txt)
    message(FATAL_ERROR "GoogleTest submodule not found. Please initialize submodules with 'git submodule update --init --recursive'.")
endif()
add_subdirectory(${GOOGLETEST_DIR} googletest)

# Add tests directory
enable_testing()
add_subdirectory(tests)