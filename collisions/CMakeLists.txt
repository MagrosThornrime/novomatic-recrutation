cmake_minimum_required(VERSION 3.20)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
project(collisions)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        src/Player.cpp
        src/Triangle.cpp
        src/GameObject.cpp
        src/Application.cpp
)

set(HEADERS
        include/Player.h
        include/Triangle.h
        include/GameObject.h
        include/Application.h
)

find_package(SFML REQUIRED)
find_package(jsoncpp REQUIRED)
add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml::sfml JsonCpp::JsonCpp)