cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 将文件列表添加到 SRC_FILES 变量中
file(GLOB_RECURSE SRC_FILES *.c *.cpp)

project(ncurses_use_main LANGUAGES CXX)

# 导入 ncurses 库
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp)
message("当前项目的名称是: ${PROJECT_NAME}")

# 链接 ncurses 库
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})