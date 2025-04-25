cmake_minimum_required(VERSION 3.15)
project(Numerical_Linear_Algebra LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 创建接口库
add_library(Numerical_Linear_Algebra INTERFACE)
target_include_directories(Numerical_Linear_Algebra INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 设置编译选项
target_compile_definitions(Numerical_Linear_Algebra INTERFACE
    -DHEADER_ONLY_LIBRARY=1
)

# Add GoogleTest as a submodule
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/third_party/google_test)
if(NOT EXISTS ${GOOGLETEST_DIR}/CMakeLists.txt)
    message(FATAL_ERROR "GoogleTest submodule not found. Please initialize submodules with 
    'git submodule update --init --recursive'.")
endif()
add_subdirectory(${GOOGLETEST_DIR} googletest)


add_executable(Test_Numerical_Linear_Algebra tests/test_main.cpp)
target_link_libraries(Test_Numerical_Linear_Algebra PRIVATE
    Numerical_Linear_Algebra
    GTest::gtest_main
)

# 示例：添加测试（可选）
enable_testing()
add_test(NAME NumericalLinearAlgebraTest COMMAND Test_Numerical_Linear_Algebra)

# 定义一个自定义目标，直接在根目录运行测试
add_custom_target(run_tests_root
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target run_tests
    COMMENT "Building and running tests from the root directory"
)