cmake_minimum_required(VERSION 3.21)

project(Sierpinsky LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# The example applications
set(EXECUTABLES
    main
    SierpinskyWirth
)

# Build the example apps
foreach(EXECUTABLE ${EXECUTABLES})
    include_directories(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/../../common
        )

    # Create the executable
    add_executable(${EXECUTABLE}
        ${CMAKE_CURRENT_LIST_DIR}/../../common/graphicsConsole.cpp
        ${CMAKE_CURRENT_LIST_DIR}/${EXECUTABLE}.cpp
        )

    # Link Qt libraries
    target_link_libraries(${EXECUTABLE} PRIVATE Qt6::Core Qt6::Widgets)

    # Enable automatic MOC, UIC, and RCC
    set_target_properties(${EXECUTABLE} PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        AUTORCC ON
    )
endforeach()
