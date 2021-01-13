file(GLOB_RECURSE MIRAGE_SDL "*.cpp" "*.h" "*.hpp")

add_library(mirage_sdl SHARED ${MIRAGE_SDL})

# sdl2 dependencies
find_package(SDL2 REQUIRED)
message (STATUS "SDL2_INCLUDE_DIR" ${SDL2_INCLUDE_DIRS})
message (STATUS "SDL2_LIBRARY" ${SDL2_LIBRARIES})
include_directories(mirage_sdl ${SDL2_INCLUDE_DIRS})
target_link_libraries(mirage_sdl ${SDL2_LIBRARIES})

# link "Mirage Engine" library to have an access to interfaces
target_link_libraries(mirage_sdl mirage)