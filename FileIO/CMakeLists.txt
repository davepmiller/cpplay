project(
    textfile-io-cpp
    )

cmake_minimum_required(
    VERSION 2.8
    )

add_definitions(
    -std=c++11
    )

add_executable(
    ${PROJECT_NAME}
    FileIO.cpp
    )
