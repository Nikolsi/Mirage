file(GLOB_RECURSE PLAYGROUND_SOURCE "*.cpp")

add_executable(playground ${PLAYGROUND_SOURCE})

target_link_libraries(playground LINK_PUBLIC mirage)