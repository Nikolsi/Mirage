#include <iostream>
#include "context.hpp"

#include <SDL.h>
#include <SDL_syswm.h>

namespace Mirage
{
    namespace SDL
    {
        Context::Context(std::shared_ptr<SDL_Window> window) : IContext()
        {
            SDL_SysWMinfo info;         /* initialize System information object */
            SDL_VERSION(&info.version); /* read SDL version */

            if (SDL_GetWindowWMInfo(window.get(), &info))
            {
                printf("SDL rendering context initialized\n");
            }
            else
            {
                SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Couldn't get window information: %s\n", SDL_GetError());
            }
        }

        Context::~Context()
        {
        }
    } // namespace SDL

} // namespace Mirage