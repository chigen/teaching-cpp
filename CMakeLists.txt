cmake_minimum_required(VERSION 3.10)
project(TeachingCPP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    first.cpp
    main.cpp
)


add_executable(TeachingCPP ${SOURCES})

target_include_directories(TeachingCPP
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)