cmake_minimum_required(VERSION 3.2)

set (CMAKE_CXX_STANDART 17)

project(todocli LANGUAGES CXX)

include_directories("${CMAKE_SOURCE_DIR}/lib/")

add_executable("${PROJECT_NAME}"
                src/main.cpp                
                src/cc.cpp
                src/CommandHandlerer.cpp
                src/fs.cpp)
