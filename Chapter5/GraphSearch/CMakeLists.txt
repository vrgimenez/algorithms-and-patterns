cmake_minimum_required(VERSION 3.16)
project(GraphSearchDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/../../common
    )

# Copy required files to build folder
configure_file(graph.conf graph.conf)

add_executable(GraphSearchDemo
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/graphSearch.cpp
    ${CMAKE_CURRENT_LIST_DIR}/graphSearch.h
    ${CMAKE_CURRENT_LIST_DIR}/../../common/graphicsConsole.cpp
)

target_link_libraries(GraphSearchDemo PRIVATE Qt6::Widgets)