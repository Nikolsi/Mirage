file(GLOB_RECURSE MIRAGE_SRC "*.cpp" "*.h")

add_library(mirage SHARED ${MIRAGE_SRC})

include_directories(../dependencies)
include_directories(../dependencies/glm)

target_include_directories(mirage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})