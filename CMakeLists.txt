cmake_minimum_required(VERSION 3.22)

project(order_book VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(order_book src/order.cpp src/order_book.cpp)

target_include_directories(order_book 
  PUBLIC 
    ${PROJECT_SOURCE_DIR}/include 
  )





















