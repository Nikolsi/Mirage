include_directories(../dependencies)
include_directories(../dependencies/glm)

find_package(Vulkan REQUIRED)

# playground apps
add_subdirectory(engine)
add_subdirectory(vulkan)