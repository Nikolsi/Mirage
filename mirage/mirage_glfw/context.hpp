#pragma once

#include <memory>
#include <mirage/context.hpp>

struct GLFWwindow;

namespace Mirage
{
    namespace GLFW
    {
        class Context : public IContext
        {
        public:
            static std::shared_ptr<Context> create(std::shared_ptr<GLFWwindow> window)
            {
                return std::shared_ptr<Context>(new Context(window));
            }

        public:
            ~Context() override;

        private:
            Context(std::shared_ptr<GLFWwindow> window);
            /* data */
        };
    } // namespace GLFW

} // namespace Mirage
