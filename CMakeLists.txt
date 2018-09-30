#### i8080 CMAKE FILE
cmake_minimum_required(VERSION 3.0)
project(i8080)

## I8080 C++11 SUPPORT
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

## I8080 HEADER FILES
set(I8080_SRC "${CMAKE_SOURCE_DIR}/src")
set(I8080_INC "${CMAKE_SOURCE_DIR}/include")
include_directories(${I8080_INC})
add_subdirectory(${I8080_SRC})

## I8080 EXECUTABLE
add_executable(i8080 ${I8080_SRC})

## Copy game assets over
add_custom_command(TARGET i8080 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/test/ $<TARGET_FILE_DIR:i8080>/test/)


## I8080 FLAGS
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -DDEBUG_BUILD")
