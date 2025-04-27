cmake_minimum_required(VERSION 3.20)
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(binary_operation)

set(CMAKE_CXX_STANDARD 20)

#find_package(GTest REQUIRED)

enable_testing()

add_executable(main main.cpp calculate.hpp)
#add_executable(tests tests.cpp calculate.hpp)
#target_link_libraries(tests PRIVATE GTest::gtest_main)

#include(GoogleTest)
#gtest_discover_tests(tests)