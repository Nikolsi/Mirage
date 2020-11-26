file(GLOB_RECURSE PLAYGROUND_SOURCE "*.cpp")

add_executable(playground ${PLAYGROUND_SOURCE})

include_directories(../dependencies)
include_directories(../dependencies/glm)

target_link_libraries(playground LINK_PUBLIC mirage)