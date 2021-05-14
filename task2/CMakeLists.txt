cmake_minimum_required(VERSION 2.7)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/)
#set(CMAKE_BINARY_OUTPUT_DIRECTORY bin)

# project's name
project(B)

# step 2
# run .py file
#execute_process(COMMAND python3 "${CMAKE_SOURCE_DIR}/A/preparing.py"
#	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/A/")
add_custom_target(create_header COMMAND python3 "${CMAKE_SOURCE_DIR}/A/preparing.py"
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/A/")

# step 4
# hard way
#message(${CMAKE_SOURCE_DIR})

# step 6
# create executable
include_directories(${CMAKE_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/A/" "${CMAKE_SOURCE_DIR}/C/")
#include_directories("${CMAKE_SOURCE_DIR}/B")
add_executable(C "${CMAKE_SOURCE_DIR}/C/main.h" "${CMAKE_SOURCE_DIR}/A/index.h" "${CMAKE_SOURCE_DIR}/C/main.cpp") 
add_executable(CTest ${CMAKE_SOURCE_DIR}/C/main_test.cpp)
add_dependencies(CTest preparing.py)

# step 3
# compile lib.h
add_subdirectory(./B/)
target_link_libraries(C lib)

#message("!!!!!!!!!!!!!!!1")
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(CTest GTest::GTest GTest::Main)#${GTEST_LIBRARIES})
target_link_libraries(CTest lib)
add_test(Test1 CTest)

