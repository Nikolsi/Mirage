file(GLOB_RECURSE MIRAGE_SRC "*.cpp" "*.h")

add_library(mirage SHARED ${MIRAGE_SRC})

target_include_directories(mirage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})