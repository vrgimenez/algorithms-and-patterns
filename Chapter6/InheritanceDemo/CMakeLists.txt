cmake_minimum_required(VERSION 3.10)
project(InheritanceDemo)

set(CMAKE_CXX_STANDARD 17)

add_executable(inheritance_demo
    Base.cpp
    Derived.cpp
    main.cpp
)