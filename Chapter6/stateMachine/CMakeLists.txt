cmake_minimum_required(VERSION 3.10)
project(stateMachine)

set(CMAKE_CXX_STANDARD 17)

add_executable(stateMachine
    PausedState.cpp
    PlayingState.cpp
    StoppedState.cpp
    main.cpp
)