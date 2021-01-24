#define GLFW_INCLUDE_VULKAN

#include <iostream>

#include <mirage/context.hpp>      // Mirage Rendering context interface
#include <mirage_glfw/context.hpp> // GLFW Rendering context -> Mirage Rendering context.

#include <GLFW/glfw3.h>

std::shared_ptr<GLFWwindow> createApplicationGLFW()
{
    // do not create OpenGL(or ES) context
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    return std::shared_ptr<GLFWwindow>(
        // window constructor
        glfwCreateWindow(1280, 720, "Mirage + GLFW", NULL, NULL),
        // window destructor
        glfwDestroyWindow);
}

int main(int argc, char **argv)
{
    // setup GLFW
    if (!glfwInit())
    {
        printf("Error: %s\n", "Initialization failed");
        return -1;
    }

    // window
    auto window = createApplicationGLFW();

    // rendering context
    std::shared_ptr<Mirage::IContext> context = Mirage::GLFW::Context::create(window);

    // // rendering engine
    // auto engine = Mirage::Engine(context);

    glfwSetKeyCallback(window.get(), [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    });

    // event loop
    while (!glfwWindowShouldClose(window.get()))
    {
        glfwPollEvents();
    }

    // destroy rendering engine
    // engine.dispose();

    // destroy window
    window.reset(); // deletes managed GLFW Window object

    // destroy GLFW
    glfwTerminate();

    return 0;
}
