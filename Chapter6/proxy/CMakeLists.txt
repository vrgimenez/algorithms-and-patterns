cmake_minimum_required(VERSION 3.10)
project(proxCalculator)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

add_executable(proxCalculator 
CalculatorProxy.cpp
RemoteMathJsCalculator.cpp
main.cpp)

target_link_libraries(proxCalculator CURL::libcurl)