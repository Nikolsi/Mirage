#pragma once

Mirage::Application *Mirage::CreateApplication();

int main(int argc, char **argv)
{
    auto app = Mirage::CreateApplication();
    // TODO:
    // app->Run();
    delete app;

    return 0;
}
