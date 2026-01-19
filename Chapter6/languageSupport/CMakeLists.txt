cmake_minimum_required(VERSION 3.10)
project(languageSupport)

set(CMAKE_CXX_STANDARD 17)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/lang)

configure_file(
    ${CMAKE_SOURCE_DIR}/lang/es.json
    ${CMAKE_BINARY_DIR}/lang/en.json
    COPYONLY
)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/../../common
    )

add_executable(languageSupport
    main.cpp
)