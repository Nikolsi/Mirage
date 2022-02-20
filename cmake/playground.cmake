# function for building single example: build_example(getting_started)
function(build_example EXAMPLE_NAME)

    set(EXAMPLE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_NAME})
    if(NOT EXISTS ${EXAMPLE_FOLDER})
        message(FATAL_ERROR "Project ${EXAMPLE_NAME} was not found")
    endif()
	message(STATUS "Generating project file for example in ${EXAMPLE_FOLDER}")

    set(RESOURCES_FOLDER "${EXAMPLE_FOLDER}/resources")
    if(NOT EXISTS ${RESOURCES_FOLDER})
        message(STATUS "No resources folder was found in the project")
    else()
        message(STATUS "Resources folder was found in the project")
    endif()

    # link all source files
    file(GLOB_RECURSE EXAMPLE_APP_SOURCE ${EXAMPLE_FOLDER}/*.cpp ${EXAMPLE_FOLDER}/*.mm ${EXAMPLE_FOLDER}/*.h ${EXAMPLE_FOLDER}/*.hpp)
    # main() entry point
    if(NOT EXISTS ${EXAMPLE_FOLDER}/main.cpp AND NOT EXISTS ${EXAMPLE_FOLDER}/${EXAMPLE_NAME}.cpp AND NOT EXISTS ${EXAMPLE_FOLDER}/main.mm AND NOT EXISTS ${EXAMPLE_FOLDER}/${EXAMPLE_NAME}.mm)
        message(FATAL_ERROR "Project must contain either main.cpp or ${EXAMPLE_NAME}.cpp with the main() function")
    endif()

    # link libraries
    find_package(Vulkan REQUIRED)

    # add resources: Shaders
    set(RESOURCES_SHADER_FOLDER "${RESOURCES_FOLDER}/shaders")
    file(GLOB_RECURSE SHADERS "${RESOURCES_SHADER_FOLDER}/*.vert" "${RESOURCES_SHADER_FOLDER}/*.frag")
    source_group("shaders" FILES ${SHADERS})

    # add resources: Textures
    set(RESOURCES_TEXTURES_FOLDER "${RESOURCES_FOLDER}/textures")
    file(GLOB_RECURSE TEXTURES "${RESOURCES_TEXTURES_FOLDER}/*.png" "${RESOURCES_TEXTURES_FOLDER}/*.jpeg")
    source_group("textures" FILES ${TEXTURES})

    # add resources: Models
    set(RESOURCES_MODELS_FOLDER "${RESOURCES_FOLDER}/models")
    file(GLOB_RECURSE MODELS "${RESOURCES_MODELS_FOLDER}/*.gltf")
    source_group("models" FILES ${MODELS})

    # add readme / tutorial
	file(GLOB READMES "${EXAMPLE_FOLDER}/*.md")

    # create executable application
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_APP_SOURCE} ${SHADERS} ${TEXTURES} ${MODELS} ${READMES})

    # target_compile_definitions(${EXAMPLE_NAME}
    #     INTERFACE
    #         USE_VK=1
    # )

    # include dependencies
    target_include_directories(${EXAMPLE_NAME}
        PRIVATE
            ../dependencies/glm
            application
    )

    # link dependencies
    target_link_libraries(${EXAMPLE_NAME}
        PRIVATE
            mirage                  # link Mirage to access public interfaces
    )

    # link SDL-related libraries
    if (EXAMPLE_FOLDER MATCHES "([Ss][Dd][Ll])")
        message(STATUS "Folder requires SDL lib to be linked")

        find_package(SDL2 REQUIRED)

        target_include_directories(${EXAMPLE_NAME}
            PRIVATE
                ${SDL2_INCLUDE_DIRS}
        )
        
        target_link_libraries(${EXAMPLE_NAME}
            PRIVATE
                ${SDL2_LIBRARIES}   # link SDL2
                mirage_sdl          # link Mirage SDL utility library
        )

    endif()

    # link GLFW-related libraries
    if (EXAMPLE_FOLDER MATCHES "([Gg][Ll][Ff][Ww])")
        message(STATUS "Folder requires GLFW lib to be linked")

        find_package(glfw3 REQUIRED)

        target_link_libraries(${EXAMPLE_NAME}
            PRIVATE
                glfw                  # link GLFW
                mirage_glfw           # link Mirage GLFW utility library
        )

    endif()

    if (APPLE)
        if(EXAMPLE_FOLDER MATCHES "([Mm][Ee][Tt][Aa][Ll])")
            message(STATUS "Folder requires Metal and Apple Frameworks")
            # find_library(COCOA_FRAMEWORK Cocoa)
            find_library(METAL_FRAMEWORK Metal)
            find_library(QUARTZ_FRAMEWORK QuartzCore)

            target_link_libraries(${EXAMPLE_NAME}
                PRIVATE
                ${METAL_FRAMEWORK}
                ${QUARTZ_FRAMEWORK}
            )
        endif()
    endif()

endfunction(build_example)

# build all examples: build_playground()
function(build_playground)
	foreach(EXAMPLE ${EXAMPLES})
		build_example(${EXAMPLE})
	endforeach(EXAMPLE)
endfunction(build_playground)
