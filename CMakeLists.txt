# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled bst/main.c bst/BST.h bst/BST.c)