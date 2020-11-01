#pragma once

namespace Engine
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

} // namespace Engine
