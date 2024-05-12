cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(hello_main LANGUAGES CXX)

add_subdirectory(task)

add_executable(macro_use main.cpp)

target_link_libraries(macro_use
PRIVATE
    task_obj
)