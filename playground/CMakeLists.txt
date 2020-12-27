# function for building single example: buildExample(getting_started)
function(buildExample EXAMPLE_NAME)

    set(EXAMPLE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_NAME})
	message(STATUS "Generating project file for example in ${EXAMPLE_FOLDER}")

    set(RESOURCES_FOLDER "${EXAMPLE_FOLDER}/resources")
    if(NOT EXISTS ${RESOURCES_FOLDER})
        message(STATUS "No resources folder was found in the project")
    else()
        message(STATUS "Resources folder was found in the project")
    endif()

    # link all source files
    file(GLOB_RECURSE EXAMPLE_APP_SOURCE ${EXAMPLE_FOLDER}/*.cpp ${EXAMPLE_FOLDER}/*.h)

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
    # <---- add more examples here
)

buildExamples()