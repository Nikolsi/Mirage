file(GLOB_RECURSE MIRAGE_SRC "*.cpp" "*.h")

add_library(mirage SHARED ${MIRAGE_SRC})

# Dependencies
include_directories(../dependencies)
include_directories(../dependencies/glm)

# Libraries
find_package(Vulkan REQUIRED)
set(LIBRARIES "Vulkan::Vulkan")
target_link_libraries(mirage Vulkan::Vulkan)

target_include_directories(mirage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})