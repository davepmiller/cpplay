project( thread-tests )
cmake_minimum_required( VERSION 2.8 )

include_directories( . )
aux_source_directory( . SRC_LIST )

add_executable( ${PROJECT_NAME}
    ${SRC_LIST}
)

target_link_libraries( ${PROJECT_NAME}
    -pthread
)

target_compile_options( ${PROJECT_NAME}
    PRIVATE
        -std=c++14
        -Wall
        -Wextra
        -Wshadow
)
