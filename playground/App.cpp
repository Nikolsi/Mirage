#include <mirage.h>

class Sandbox : public Mirage::Application
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
