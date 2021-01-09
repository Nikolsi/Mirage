#include <iostream>

#include "context_sdl.h"

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