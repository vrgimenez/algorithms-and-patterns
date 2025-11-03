cmake_minimum_required(VERSION 3.10)
project(invertedIndexSearch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(doc1.txt doc1.txt COPYONLY)
configure_file(doc2.txt doc2.txt COPYONLY)
configure_file(doc3.txt doc3.txt COPYONLY)

add_executable(invertedIndexSearch main.cpp)