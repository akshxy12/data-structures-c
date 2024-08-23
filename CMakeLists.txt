cmake_minimum_required(VERSION 3.22)

if(WIN32)
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_CXX_COMPILER g++)
endif(WIN32)
if(UNIX)
    set(CMAKE_C_COMPILER /usr/bin/gcc)
    set(CMAKE_CXX_COMPILER /usr/bin/g++)
endif(UNIX)

message(CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_NAME DataStructures)
file(GLOB SOURCES_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
set(ALL_SOURCES ${SOURCES_SRC} ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
set(CMAKE_C_FLAGS "-g")

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ${ALL_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
