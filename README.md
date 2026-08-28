# C++ Limit Order Book

A small C++ implementation of a **limit order book and matching engine**, built as a learning project to explore C++ systems programming, data structures, performance, testing, and build tooling.

## Goals

* Understand how a limit order book works
* Implement order matching and price-time priority
* Practice modern C++
* Learn CMake project structure
* Write unit tests with GoogleTest
* Benchmark and investigate performance

## Project Structure

```text
order-book/
├── CMakeLists.txt
├── README.md
├── LICENSE
├── .gitignore
│
├── apps/
│   └── main.cpp
│
├── include/
│   └── order_book/
│       ├── order.hpp
│       └── order_book.hpp
│
├── src/
│   ├── order.cpp
│   └── order_book.cpp
│
├── tests/
│   ├── CMakeLists.txt
│   ├── test_order.cpp
│   └── test_order_book.cpp
│
├── external/
│   └── googletest/
│
└── build/
```

## Building

```bash
cmake -S . -B build
cmake --build build
```

## Running Tests

```bash
ctest --test-dir build
```

## Current Status

 Work in progress.

The project is being built incrementally, starting with the basic order-book data structures and matching logic.

## Future Ideas

* Limit order matching
* Order cancellation
* Price-time priority
* Order-book visualization/output
* Performance benchmarks
* Memory/performance optimizations

## License

MIT
