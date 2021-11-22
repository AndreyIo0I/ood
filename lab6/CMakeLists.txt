cmake_minimum_required(VERSION 3.14)
project(oop)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

include_directories(src)
add_subdirectory(src)

target_link_libraries(main src_lib)

add_subdirectory(tests)
