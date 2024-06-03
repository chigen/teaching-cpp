cmake_minimum_required(VERSION 3.10)
project(TeachingCPP)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -fdiagnostics-color=always")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -v")

set(SOURCES
    first.cpp
    main.cpp
)

add_executable(TeachingCPP ${SOURCES})

target_include_directories(TeachingCPP
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)
