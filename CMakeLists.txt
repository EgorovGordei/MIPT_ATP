set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-c++) #STEP1: SETTING COMPILER
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

cmake_minimum_required(VERSION 3.0)

#set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY") #STEP1: NEEDS SO CMAKE WON'T TRY TO COMPILE SOMETHING HARD
project(SimpleLibrary)

include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

set_target_properties(buffer PROPERTIES PUBLIC_HEADER buffer.h)
install(TARGETS Main MainLib buffer
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")

