# sdl2 dependencies
find_package(SDL2 REQUIRED)

if(${SDL2_FOUND})
    message (STATUS "SDL2 was found in the system")
    message (STATUS "SDL2_INCLUDE_DIR " ${SDL2_INCLUDE_DIRS})
    message (STATUS "SDL2_LIBRARY " ${SDL2_LIBRARIES})

    file(GLOB_RECURSE MIRAGE_SDL "*.cpp" "*.h" "*.hpp")
    add_library(mirage_sdl SHARED ${MIRAGE_SDL})

    include_directories(mirage_sdl ${SDL2_INCLUDE_DIRS})
    target_link_libraries(mirage_sdl ${SDL2_LIBRARIES})

    # link "Mirage Engine" library to have an access to interfaces
    #include_directories(mirage_sdl ../)
    target_link_libraries(mirage_sdl mirage)
    target_include_directories(mirage_sdl PUBLIC ../)
else()
    message (STATUS "SDL2 was not found in the system")
endif()