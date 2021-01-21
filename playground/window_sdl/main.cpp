#include <iostream>
#include <memory>

#include <mirage/context.hpp>     // Mirage Rendering context interface
#include <mirage_sdl/context.hpp> // SDL Rendering context -> Mirage Rendering context.

#include <SDL.h>

std::shared_ptr<SDL_Window> createApplicationSDL()
{
    // setup window
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    return std::shared_ptr<SDL_Window>(
        // window constructor
        SDL_CreateWindow("Mirage + SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags),
        // window destructor
        SDL_DestroyWindow);
}

int main(int argc, char **argv)
{
    // setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // create window
    auto window = createApplicationSDL();

    // create rendering context
    std::shared_ptr<Mirage::IContext> context = Mirage::SDL::Context::create(window);
    // // create rendering engine
    // auto engine = Mirage::Engine(context);

    // event loop
    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window.get()))
                done = true;
        }
    }

    // destroy rendering engine
    // engine.dispose();

    // destroy window
    window.reset(); // deletes managed SDL Window object

    // destroy SDL
    SDL_Quit();

    return 0;
}
