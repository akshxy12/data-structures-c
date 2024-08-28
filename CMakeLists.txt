cmake_minimum_required(VERSION 3.22)

if(WIN32)
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_CXX_COMPILER g++)
endif(WIN32)
if(UNIX)
    set(CMAKE_C_COMPILER /usr/bin/gcc)
    set(CMAKE_CXX_COMPILER /usr/bin/g++)
endif(UNIX)

set(PROJECT_NAME DataStructures)

file(GLOB_RECURSE SOURCES_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
# file(GLOB SOURCES_DATA_STRUCTURES_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/data-structures/*.c)
# file(GLOB SOURCES_SEARCH_ALGORITHMS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/search/*.c)
# file(GLOB SOURCES_SORT_ALGORITHMS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/sort/*.c)
# file(GLOB SOURCES_OTHER_ALGORITHMS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/*.c)
# file(GLOB SOURCES_ADDITIONAL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
# set(ALL_SOURCES ${SOURCES_DATA_STRUCTURES_SRC} ${SOURCES_SEARCH_ALGORITHMS_SRC} ${SOURCES_SORT_ALGORITHMS_SRC} ${SOURCES_OTHER_ALGORITHMS_SRC} ${SOURCES_ADDITIONAL_SRC} ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
set(ALL_SOURCES ${SOURCES_SRC} ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

set(CMAKE_C_FLAGS "-g")

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ${ALL_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/
    ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/search/
    ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/sort/
    ${CMAKE_CURRENT_SOURCE_DIR}/data-structures/
    ${CMAKE_CURRENT_SOURCE_DIR}/data-structures/linear-ds/
    ${CMAKE_CURRENT_SOURCE_DIR}/data-structures/non-linear-ds/
    ${CMAKE_CURRENT_SOURCE_DIR}/data-structures/non-linear-ds/trees
)
