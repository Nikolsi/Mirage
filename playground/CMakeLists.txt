# function for building single example: buildExample(getting_started)
function(buildExample EXAMPLE_NAME)

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
    file(GLOB_RECURSE EXAMPLE_APP_SOURCE ${EXAMPLE_FOLDER}/*.cpp ${EXAMPLE_FOLDER}/*.h)
    # main() entry point
    if(NOT EXISTS ${EXAMPLE_FOLDER}/main.cpp AND NOT EXISTS ${EXAMPLE_FOLDER}/${EXAMPLE_NAME}.cpp)
        message(FATAL_ERROR "Project must contain either main.cpp or ${EXAMPLE_NAME}.cpp with the main() function")
    endif()

    # link forked dependencies
    include_directories(../dependencies)
    include_directories(../dependencies/glm)

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

    # link "Mirage Engine" library
    target_link_libraries(${EXAMPLE_NAME} LINK_PUBLIC mirage)

    # link additional libraries
    if (EXAMPLE_FOLDER MATCHES "([Ss][Dd][Ll])")
        message(STATUS "sdl folder requires SDL lib to be linked")

        # sdl2 dependencies
        find_package(SDL2 REQUIRED)
        message (STATUS "SDL2_INCLUDE_DIR" ${SDL2_INCLUDE_DIRS})
        message (STATUS "SDL2_LIBRARY" ${SDL2_LIBRARIES})
        include_directories(${SDL2_INCLUDE_DIRS})
        target_link_libraries(${EXAMPLE_NAME} LINK_PUBLIC ${SDL2_LIBRARIES})

        # TODO: add mirage_sdl library
        # target_link_libraries(${EXAMPLE_NAME} LINK_PUBLIC mirage_sdl)
    endif()
    if (EXAMPLE_FOLDER MATCHES "([Gg][Ll][Ff][Ww])")
        message(STATUS "glfw folder requires GLFW lib to be linked")

        # TODO: add mirage_glfw library
        # target_link_libraries(${EXAMPLE_NAME} LINK_PUBLIC mirage_glfw)
    endif()


endfunction(buildExample)

# build all examples: buildExamples()
function(buildExamples)
	foreach(EXAMPLE ${EXAMPLES})
		buildExample(${EXAMPLE})
	endforeach(EXAMPLE)
endfunction(buildExamples)


# playground apps
set(EXAMPLES
    engine
    vulkan
    window_sdl
    # <---- add more examples here
)

buildExamples()