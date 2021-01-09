#pragma once

#include <string>
#include <memory>

namespace Mirage
{
    struct ContextProps
    {
        std::string title;
        unsigned int width;
        unsigned int height;
        ContextProps(
            const std::string &title,
            unsigned int width,
            unsigned int height) : title(title), width(width), height(height) {}

    private:
        ContextProps() {}
    };

    /**
     * Rendering context interface.
     */
    class IContext
    {
    public:
        IContext();
        virtual ~IContext();

    private:
        /* data */
    };

} // namespace Mirage