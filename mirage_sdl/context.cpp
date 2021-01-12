#include <iostream>

#include "context.h"

#include <SDL.h>

namespace Mirage
{
    namespace SDL
    {
        Context::Context(std::shared_ptr<SDL_Window> window)
        {
            printf("SDL rendering context initialized");
        }

        Context::~Context()
        {
        }
    } // namespace SDL

} // namespace Mirage