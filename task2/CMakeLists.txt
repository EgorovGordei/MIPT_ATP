cmake_minimum_required(VERSION 2.7)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/)

# project's name
project(B)

# create executable
include_directories(${CMAKE_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/A/" "${CMAKE_SOURCE_DIR}/C/")
add_executable(C "${CMAKE_SOURCE_DIR}/C/main.h" "${CMAKE_SOURCE_DIR}/A/index.h" "${CMAKE_SOURCE_DIR}/C/main.cpp") 
add_executable(CTest ${CMAKE_SOURCE_DIR}/C/main_test.cpp)
add_dependencies(CTest preparing.py)

add_custom_target(make_header ALL DEPENDS "${CMAKE_SOURCE_DIR}/A/index.h")
add_custom_command(OUTPUT "${CMAKE_SOURCE_DIR}/A/index.h"
		   COMMAND python3 "${CMAKE_SOURCE_DIR}/A/preparing.py"
		   WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/A/")

# compile lib.h
add_subdirectory(./B/)
target_link_libraries(C lib)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(CTest GTest::GTest GTest::Main)
target_link_libraries(CTest lib)
add_test(Test1 CTest)

