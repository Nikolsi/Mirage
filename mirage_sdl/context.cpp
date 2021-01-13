#include <iostream>

#include "context.h"

#include <SDL.h>

namespace Mirage
{
    namespace SDL
    {
        Context::Context(std::shared_ptr<SDL_Window> window) : IContext()
        {
            std::cout << "SDL rendering context initialized\n";
        }

        Context::~Context()
        {
        }
    } // namespace SDL

} // namespace Mirage