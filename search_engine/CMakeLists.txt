cmake_minimum_required(VERSION 3.20)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(search_engine)

set(CMAKE_CXX_STANDARD 20)

set(ENGINE_SOURCES
        src/Trie.cpp
        src/TrieNode.cpp
)

set(ENGINE_HEADERS
        include/Trie.h
        include/TrieNode.h
)

set(TEST_SOURCES
        src/Trie.cpp
        src/TrieNode.cpp
)

set(TEST_HEADERS
        include/Trie.h
        include/TrieNode.h
)

find_package(GTest REQUIRED)

enable_testing()

add_executable(engine engine.cpp ${ENGINE_SOURCES} ${ENGINE_HEADERS})
target_include_directories(engine PRIVATE include)

add_executable(tests tests.cpp ${TEST_SOURCES} ${TEST_HEADERS})
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)