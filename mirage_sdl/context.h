#pragma once

#include <memory>
#include <mirage.h>

struct SDL_Window;

namespace Mirage
{
    namespace SDL
    {
        class Context : Mirage::IContext
        {
        public:
            Context(std::shared_ptr<SDL_Window> window);
            ~Context();

        private:
            /* data */
        };
    } // namespace SDL

} // namespace Mirage
