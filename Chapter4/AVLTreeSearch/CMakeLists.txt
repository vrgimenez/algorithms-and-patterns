cmake_minimum_required(VERSION 3.10)
project(AVLTreeConsole LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AVLTreeConsole
    main.cpp
    student.h
    AVLTree.h
    AVLTree.cpp
    NodeTree.h
)

target_include_directories(AVLTreeConsole PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})