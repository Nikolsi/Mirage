
file(GLOB_RECURSE MIRAGE_SRC "*.cpp" "*.h" "*.hpp")
add_library(mirage SHARED ${MIRAGE_SRC})

# Vulkan API dependency
find_package(Vulkan REQUIRED)

if(${Vulkan_FOUND})
    message (STATUS "Vulkan was found in the system")
    message (STATUS "Vulkan_INCLUDE_DIRS " ${Vulkan_INCLUDE_DIRS})
    message (STATUS "Vulkan_LIBRARIES " ${Vulkan_LIBRARIES})

    target_include_directories(mirage
        PUBLIC
            ../dependencies/glm
    )

    target_include_directories(mirage
        PUBLIC
            ../
    )

    target_link_libraries(mirage
        Vulkan::Vulkan
    )

else()
    message (STATUS "Vulkan was not found in the system")
endif()
