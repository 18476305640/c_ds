# cmake_minimum_required(VERSION <specify CMake version here>)
project(cds C)

set(CMAKE_C_STANDARD 99)

add_executable(cds tree/bst/main.c tree/bst/BST.h tree/avl/AVL.c tree/avl/main.c tree/avl/AVL.h tree/avl/AVL.c)