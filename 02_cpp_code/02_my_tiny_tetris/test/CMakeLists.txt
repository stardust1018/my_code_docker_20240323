cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(num_test "")

target_sources(num_test
  PRIVATE
    num_test.cpp
)

find_package(GTest REQUIRED)
message(STATUS "GTest library path: ${GTEST_LIBRARIES}")

target_link_libraries(num_test
  PRIVATE
    ${GTEST_LIBRARIES}
    pthread
)

enable_testing()
add_test(NAME google_test COMMAND $<TARGET_FILE:num_test>)