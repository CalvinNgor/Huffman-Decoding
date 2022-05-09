cmake_minimum_required(VERSION 3.22)
project(HUFFMAN_DECOMP)

set(CMAKE_CXX_STANDARD 14)

add_executable(HUFFMAN_DECOMP main.cpp cmake-build-debug/Huffman.h cmake-build-debug/Huffman.cpp )
add_executable(TEST test.cpp)

