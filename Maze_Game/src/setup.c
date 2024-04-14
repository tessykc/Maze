#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "maze.h"


void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            game_up = FALSE;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                game_up = FALSE;
            break;
        default:
            break;
    }
}

void setup(void) {
    ball.x = 20;
    ball.y = 20;
    ball.width = 15;
    ball.height = 15;
}

void update(void) {
    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();

    ball.x += 30 * delta_time;
    ball.y += 40 * delta_time;
}