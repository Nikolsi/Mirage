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

Engine::Application *CreateApplication()
{
    return new Sandbox();
}

int main()
{
    return 0;
}