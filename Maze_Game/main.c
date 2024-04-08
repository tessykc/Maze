#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "maze.h"
#include "renderer.c"


int main(void) {
    /*
    * Initialize SDL2 or any other graphics library
    */

	int SDL_Init(Uint32 flags);
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }
    if (SDL_Init(SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "SDl Timer initialization failed: %s\n", SDL_GetError());
        return 1;
    }
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "SDl Audio initialization failed: %s\n", SDL_GetError());
        return 1;
    }
    // Game loop
    while (1) {
        // Handle input (e.g., player movement)
        // ...

        // Cast rays and render the scene
        castRays();
        // ...

        // Present the frame
        // ...
    }

    // Cleanup and exit
    // ...

    return 0;

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            handleInput(&event);
        }

        render(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
