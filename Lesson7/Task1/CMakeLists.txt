cmake_minimum_required(VERSION 3.10)
project(prog)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/StaticLibGreeter)

add_executable(${PROJECT_NAME} "src/main.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE StaticLibGreeter)

