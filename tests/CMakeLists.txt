cmake_minimum_required(VERSION 3.15)
project(Tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()
add_executable(${PROJECT_NAME} test_main.cpp)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
