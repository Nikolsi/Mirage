cmake_minimum_required(VERSION 3.18)

project(Mirage CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(mirage)
add_subdirectory(playground)