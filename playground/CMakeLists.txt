include(playground)

# define playground apps
set(EXAMPLES
    glm         # glm test
    
    engine      # no window Mirage API

    vulkan      # no window Vulkan API

    vulkan_glfw # glfw + Vulkan API
    vulkan_sdl  # sdl + Vulkan API

    metal_glfw  # glfw + Metal API (Apple only)
    metal_sdl   # sdl + Metal API (Apple only)

    window_glfw # glfw + Mirage API
    window_sdl  # sdl + Mirage API

    # <---- add more examples here
)

build_playground()