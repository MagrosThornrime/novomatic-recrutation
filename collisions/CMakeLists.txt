cmake_minimum_required(VERSION 3.20)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
project(collisions)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML REQUIRED)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml::sfml)