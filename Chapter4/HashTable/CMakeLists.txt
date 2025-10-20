cmake_minimum_required(VERSION 3.10)
project(HashTableConsole)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashTableConsole
    main.cpp
    node.cpp
    hashTable.cpp
)