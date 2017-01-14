project( palindrome )

cmake_minimum_required( VERSION 2.8 )

aux_source_directory( . SRC_LIST )

add_executable( ${PROJECT_NAME} ${SRC_LIST} )

target_compile_options( ${PROJECT_NAME} PRIVATE -std=c++11 -Wall -Wextra )
