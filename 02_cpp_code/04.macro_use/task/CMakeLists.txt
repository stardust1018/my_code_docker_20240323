add_library(task_obj SHARED "")

target_sources(task_obj
PRIVATE
  task.cpp
PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/task.h
)

target_include_directories(task_obj
PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)