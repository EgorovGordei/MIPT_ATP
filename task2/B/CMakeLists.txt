cmake_minimum_required(VERSION 2.7)

message("START")
project("lib_project")

set(SOURCES lib.cpp lib.h)
add_library(lib SHARED ${SOURCES})

message(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message("DONE")

