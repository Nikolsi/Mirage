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
            static std::shared_ptr<Context> create(std::shared_ptr<SDL_Window> window)
            {
                return std::shared_ptr<Context>(new Context(window));
            }

        public:
            ~Context() override;

        private:
            Context(std::shared_ptr<SDL_Window> window);
            /* data */
        };
    } // namespace SDL

} // namespace Mirage
