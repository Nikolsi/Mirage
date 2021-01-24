# GLFW dependency
find_package(glfw3 REQUIRED)

if(${glfw3_FOUND})
    message (STATUS "GLFW was found in the system")
    message (STATUS "GLFW_VERSION " ${glfw3_VERSION})
    message (STATUS "GLFW_DIR " ${glfw3_DIR})

    file(GLOB_RECURSE MIRAGE_GLFW "*.cpp" "*.h" "*.hpp")
    add_library(mirage_glfw SHARED ${MIRAGE_GLFW})

    target_include_directories(mirage_glfw
        PUBLIC
            ../
    )

    target_link_libraries(mirage_glfw
        PUBLIC
            mirage              # link Mirage to access public interfaces
            glfw                # link GLFW
    )
    
else()
    message (STATUS "GLFW3 was not found in the system")
endif()