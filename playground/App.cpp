#include <iostream>
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

Mirage::Application *Mirage::CreateApplication()
{
    std::cout << "Hello";
    return new Sandbox();
}