//
// TODO: add CMake build support ObjectiveC/C++
// see: https://stackoverflow.com/questions/20962869/cmakelists-txt-for-an-objective-c-project
// original: https://gist.github.com/gcatlin/b89e0efed78dd91364609ca4095da346
// cc main.mm `sdl2-config --cflags --libs` -framework Metal -framework QuartzCore && ./a.out
//
#include <SDL.h>
#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>

int main (int argc, char *args[])
{
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "metal");
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL Metal", -1, -1, 640, 480, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    const CAMetalLayer *swapchain = (__bridge CAMetalLayer *)SDL_RenderGetMetalLayer(renderer);
    const id<MTLDevice> gpu = swapchain.device;
    const id<MTLCommandQueue> queue = [gpu newCommandQueue];

    MTLClearColor color = MTLClearColorMake(0, 0, 0, 1);
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT: quit = true; break;
            }
        }

        @autoreleasepool {
            id<CAMetalDrawable> surface = [swapchain nextDrawable];

            color.red = (color.red > 1.0) ? 0 : color.red + 0.01;

            MTLRenderPassDescriptor *pass = [MTLRenderPassDescriptor renderPassDescriptor];
            pass.colorAttachments[0].clearColor = color;
            pass.colorAttachments[0].loadAction  = MTLLoadActionClear;
            pass.colorAttachments[0].storeAction = MTLStoreActionStore;
            pass.colorAttachments[0].texture = surface.texture;

            id<MTLCommandBuffer> buffer = [queue commandBuffer];
            id<MTLRenderCommandEncoder> encoder = [buffer renderCommandEncoderWithDescriptor:pass];
            [encoder endEncoding];
            [buffer presentDrawable:surface];
            [buffer commit];
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}