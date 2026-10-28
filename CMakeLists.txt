cmake_minimum_required(VERSION 3.16)

project(sample_project CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_library(mymath lib/add.cpp)
target_include_directories(mymath PUBLIC include)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.18.0
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark
    GIT_TAG v1.9.4
)
FetchContent_MakeAvailable(googletest benchmark)

add_executable(main src/main.cpp)
target_link_libraries(main mymath)

enable_testing()
add_executable(tests tests/test_add.cpp)
target_link_libraries(tests gtest_main mymath)
include(GoogleTest)
gtest_discover_tests(tests)

add_executable(bench bench/bench_add.cpp)
target_link_libraries(bench benchmark::benchmark mymath)
