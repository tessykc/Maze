#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "maze.h"

#define TRUE 1
#define FALSE 0

int game_up = FALSE;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int last_frame_time = 0;

struct ball {
    float x;
    float y;
    float width;
    float height;
} ball;


int initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	    printf("SDL Error: %s\n", SDL_GetError());
	    return -1;
	}
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );

    if (!window) {
        fprintf(stderr, "Error creating SDL Window.\n");
        return FALSE;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        return FALSE;
    }
    return TRUE;
}

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

void render(void) {
    SDL_Rect ball_rect;

    ball_rect.x = (int)ball.x;
    ball_rect.y = (int)ball.y;
    ball_rect.w = (int)ball.width;
    ball_rect.h = (int)ball.height;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball_rect);

    SDL_RenderPresent(renderer);
}

void destroy_window(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(void) {
    game_up = initialize_window();

    setup();

    while (game_up) {
        process_input();
        update();
        render();
    }

    destroy_window();

    return 0;
}
