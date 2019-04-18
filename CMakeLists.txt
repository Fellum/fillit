cmake_minimum_required(VERSION 3.13)
project(fillit C)

set(CMAKE_C_STANDARD 99)
add_subdirectory("${PROJECT_SOURCE_DIR}/libft")
include_directories("${PROJECT_SOURCE_DIR}/libft/includes")
add_executable(fillit main.c)
target_link_libraries(fillit libft)