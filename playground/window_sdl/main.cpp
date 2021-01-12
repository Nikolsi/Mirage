#include <iostream>
// #include <memory>

// #include <mirage.h> // core
// #include <mirage_sdl.hpp> // sdl specific

#include <SDL.h>

SDL_Window *createApplicationSDL();

void destroyApplicationSDL(SDL_Window *window);

int main(int argc, char **argv)
{
    // create window
    auto window = createApplicationSDL();

    // // create rendering context
    // auto context = Mirage::SDL::Context(window);

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
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;
        }
    }

    // destroy rendering engine
    // engine.dispose();

    // destroy window
    destroyApplicationSDL(window);

    return 0;
}

SDL_Window *createApplicationSDL()
{
    // setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        // return -1;
    }

    // setup window
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    return SDL_CreateWindow("Mirage + SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
}

void destroyApplicationSDL(SDL_Window *window)
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}