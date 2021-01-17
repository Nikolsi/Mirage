#pragma once

#include <memory>
#include <mirage/context.hpp>

struct SDL_Window;

namespace Mirage
{
    namespace SDL
    {
        class Context : public IContext
        {
        public:
            Context(std::shared_ptr<SDL_Window> window);
            ~Context();

        private:
            /* data */
        };
    } // namespace SDL

} // namespace Mirage
