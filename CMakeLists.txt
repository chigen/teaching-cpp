cmake_minimum_required(VERSION 3.10)
project(TeachingCPP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    first.cpp
    main.cpp
)#创建一个变量，名字叫SOURCE。它包含了所有的cpp文件。


add_executable(TeachingCPP ${SOURCES})

target_include_directories(TeachingCPP
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)#设置这个可执行文件hello_headers需要包含的库的路径