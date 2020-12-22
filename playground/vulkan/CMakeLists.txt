file(GLOB_RECURSE VULKAN_APP_SOURCE "*.cpp" "*.h")

add_executable(vkapp ${VULKAN_APP_SOURCE})

target_link_libraries(vkapp LINK_PUBLIC mirage)