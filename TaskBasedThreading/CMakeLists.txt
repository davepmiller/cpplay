project( thread-tests )

cmake_minimum_required( VERSION 2.8 )

set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread" )

include_directories( . )

aux_source_directory( . SRC_LIST )

add_executable( ${PROJECT_NAME} ${SRC_LIST} )

target_link_libraries( ${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} )


