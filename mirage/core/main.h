#pragma once

Mirage::Application *Mirage::CreateApplication();

int main(int argc, char **argv)
{
    auto app = Mirage::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
