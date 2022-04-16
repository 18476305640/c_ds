# cmake_minimum_required(VERSION <specify CMake version here>)
project(cds C)

set(CMAKE_C_STANDARD 99)

add_executable(cds bst/main.c bst/BST.h avl/AVL.c avl/main.c avl/AVL.h avl/AVL.c)