cmake_minimum_required(VERSION 3.16)

project(sample_project CXX)
add_library(mymath lib/add.cpp)
include_directories(include)
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.18.0
)
FetchContent_MakeAvailable(googletest)
add_executable(main main.cpp)
target_link_libraries(main mymath)
enable_testing()
add_executable(tests tests/test_add.cpp)
target_link_libraries(tests gtest_main mymath)
include(GoogleTest)
gtest_discover_tests(tests)