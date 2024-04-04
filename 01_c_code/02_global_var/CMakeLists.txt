cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(main_cpp)

add_executable(${PROJECT_NAME} main.cpp)
message("当前项目的名称是: ${PROJECT_NAME}")