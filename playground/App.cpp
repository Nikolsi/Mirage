#include "Engine.h"

class Sandbox : public Engine::Application
{
private:
    /* data */
public:
    Sandbox(/* args */)
    {
    }
    ~Sandbox()
    {
    }
};

Engine::Application *Engine::CreateApplication()
{
    return new Sandbox();
}
