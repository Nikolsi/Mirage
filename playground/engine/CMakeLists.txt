file(GLOB_RECURSE ENGINE_APP_SOURCE "*.cpp" "*.h")

add_executable(mirageapp ${ENGINE_APP_SOURCE})

target_link_libraries(mirageapp LINK_PUBLIC mirage)