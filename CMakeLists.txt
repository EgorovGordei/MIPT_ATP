set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-c++) #STEP1: SETTING COMPILER
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib") 	   #STEP2: SETTING INSTALLATION PATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE) 		   #STEP2: CMAKE WILL NOW USE RPATH

cmake_minimum_required(VERSION 3.0)
project(SimpleLibrary)

include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

install(TARGETS Main MainLib buffer # STEP3: INSTALL ALL TARGETS	
	RUNTIME DESTINATION bin     #        TO THE DESTINATION BIN
	LIBRARY DESTINATION lib)    #	     TO THE DESTINATION LIB

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/" 
	DESTINATION "${CMAKE_INSTALL_PREFIX}/include") #STEP4: INSTALL EVERYTHINK FROM INCLUDE SO OTHERS CAN INCLUDE IT

