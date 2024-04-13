cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 将文件列表添加到 SRC_FILES 变量中
aux_source_directory(. SRC_FILES)

project(my_tiny_tetris LANGUAGES CXX)

# 导入 ncurses 库
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SRC_FILES})
message("当前项目的名称是: ${PROJECT_NAME}")

add_subdirectory(test)

# 链接 ncurses 库
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})