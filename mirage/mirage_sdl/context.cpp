#include <iostream>
#include "context.hpp"

#include <SDL.h>
#include <SDL_syswm.h>

namespace Mirage
{
    namespace SDL
    {
        Context::Context(std::shared_ptr<SDL_Window> window)
        {
            SDL_SysWMinfo info;         /* initialize System information object */
            SDL_VERSION(&info.version); /* read SDL version */

            auto raw_window = window.get();

            if (SDL_GetWindowWMInfo(raw_window, &info))
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