cmake_minimum_required(VERSION 3.14)
project(KVStoreProject)

set(CMAKE_CXX_STANDARD 17)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Google Benchmark
FetchContent_Declare(
  benchmark
  URL https://github.com/google/benchmark/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(benchmark)

# KVStore library
add_library(kvstore kvstore.cpp)

# Unit Tests
enable_testing()
add_executable(kvstore_test test/kvstore_test.cpp)
target_link_libraries(kvstore_test kvstore gtest_main)
include(GoogleTest)
gtest_discover_tests(kvstore_test)

# Benchmark
add_executable(kvstore_bench benchmark/kvstore_bench.cpp)
target_link_libraries(kvstore_bench kvstore benchmark::benchmark)

# CLI Application
add_executable(kvstore_cli main.cpp)
target_link_libraries(k)
