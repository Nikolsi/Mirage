#pragma once

namespace Mirage
{

    class Application
    {
    private:
        /* data */
    public:
        Application(/* const std::string &name */);
        virtual ~Application();
        void Run();
    };

    Application *CreateApplication();

} // namespace Mirage
