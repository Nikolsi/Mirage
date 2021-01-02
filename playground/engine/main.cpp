#include <iostream>
#include <mirage.h>

class Template : public Mirage::Application
{
private:
    /* data */
public:
    Template(/* args */)
    {
        std::cout << "Mirage Application\n";
    }
    ~Template()
    {
    }
};

Mirage::Application *Mirage::CreateApplication()
{
    return new Template();
}