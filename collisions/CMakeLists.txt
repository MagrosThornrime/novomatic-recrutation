cmake_minimum_required(VERSION 3.20)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
project(collisions)

set(CMAKE_CXX_STANDARD 20)

set(GAME_SOURCES
        src/Player.cpp
        src/Triangle.cpp
        src/GameObject.cpp
        src/Application.cpp
        src/Collisions.cpp
        src/Vec2.cpp
        src/Vec3.cpp
)

set(GAME_HEADERS
        include/Player.h
        include/Triangle.h
        include/GameObject.h
        include/Application.h
        include/Collisions.h
        include/Vec2.h
        include/Vec3.h
)

set(TEST_SOURCES
        src/Triangle.cpp
        src/Collisions.cpp
        src/Vec2.cpp
        src/Vec3.cpp
)

set(TEST_HEADERS
        include/Triangle.h
        include/Collisions.h
        include/Vec2.h
        include/Vec3.h
)

find_package(SFML REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(GTest REQUIRED)

enable_testing()

add_executable(game game.cpp ${GAME_SOURCES} ${GAME_HEADERS})
target_include_directories(game PRIVATE include)
target_link_libraries(game PRIVATE sfml::sfml JsonCpp::JsonCpp)

add_executable(tests tests.cpp ${TEST_SOURCES} ${TEST_HEADERS})
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)