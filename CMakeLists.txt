cmake_minimum_required(VERSION 3.10)
project(RayMarching)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_package(glfw3 REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

add_executable(RayMarching src/main.cpp src/Shader.cpp src/RayMarching.cpp src/Window.cpp include/glad.c)

target_link_libraries(RayMarching glfw)