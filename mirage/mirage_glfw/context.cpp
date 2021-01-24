#include <iostream>
#include "context.hpp"

#include <GLFW/glfw3.h>

namespace Mirage
{
    namespace GLFW
    {
        Context::Context(std::shared_ptr<GLFWwindow> window)
        {
            printf("GLFW rendering context initialized\n");
        }

        Context::~Context()
        {
        }
    } // namespace GLFW

} // namespace Mirage