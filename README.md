# 🚀 KVStoreProject – Modern C++ Key-Value Store

A modern, lightweight key-value store built using C++17 that demonstrates clean architecture, RAII, unit testing, benchmarking, and a CLI — all managed through CMake.

## 📚 What I Learned

This project helped me learn and apply key software engineering concepts:

- ✅ RAII (Resource Acquisition Is Initialization) for safe memory and resource management.
- 🚚 Move semantics and ownership handling in C++.
- 🧪 Google Test for robust, automated unit testing.
- 📊 Google Benchmark for performance analysis.
- ⚙️ CMake for project builds and dependency management with FetchContent.
- 💻 VS Code configuration with manual IntelliSense fixes and include path setup.
- 🧩 Command-line interface development to interact with the store.

## 🧱 Project Structure

kvstore-cpp/
├── kvstore.h / kvstore.cpp         # Core KVStore class logic  
├── test/kvstore_test.cpp           # Unit tests using Google Test  
├── benchmark/kvstore_bench.cpp     # Benchmarks using Google Benchmark  
├── main.cpp                        # CLI for interacting with KVStore  
├── CMakeLists.txt                  # CMake build script  
└── README.md                       # Project overview and instructions  

## 📦 Dependencies

- CMake ≥ 3.14
- C++17
- GoogleTest
- Google Benchmark

These are auto-downloaded using CMake’s FetchContent.

## 🔨 How to Build and Run

1. Build the project:  
cmake -S . -B build  
cmake --build build

2. Run tests:  
./build/kvstore_test

3. Run benchmarks:  
./build/kvstore_bench

4. Run CLI:  
./build/kvstore_cli


## 🧪 Unit Testing

Located in `test/kvstore_test.cpp`.

Tests include:

- Insertion and retrieval
- Overwriting values
- Handling missing keys
- Removing keys

## 📊 Benchmarking

Located in `benchmark/kvstore_bench.cpp`.

Benchmarks include:

- `put()`
- `get()`
- `remove()`

In addition to basic performance testing, I implemented a multithreaded benchmark using `std::async` to simulate concurrent access. This allows `KVStore` operations like `put()` and `get()` to run in parallel threads, testing how the store behaves under simultaneous usage.

The purpose was to:

- Explore **modern C++ concurrency tools** like `std::async`
- Measure how `KVStore` handles parallel inserts and lookups
- Simulate real-world usage patterns where multiple clients access the store at once

This deepened my understanding of concurrency and performance tradeoffs in systems programming.

## 💻 CLI Usage

Located in `main.cpp`.

Run:
./build/kvstore_cli

Commands:
put apple red
get apple
remove apple
exit


## 🛠 VS Code IntelliSense Setup

If using VS Code:

1. Add `.vscode/c_cpp_properties.json`
2. Use an include path like:

"${workspaceFolder}/**",
"${workspaceFolder}/build/_deps/googletest-src/googletest/include"


3. Set `"compilerPath"` to your compiler (e.g., `cl.exe` or `g++.exe`)

## ✨ Future Work

- Save/load store to/from file
- Add command history
- Support value types beyond strings
- Track benchmark output to file

## 🙌 Final Thoughts

This project helped me deeply understand C++ architecture, tools, and design. I now feel more confident building modern, testable, extensible C++ systems.

