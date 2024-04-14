#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "maze.h"

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

void initialize_window(void) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "Error initializing SDL.\n");
		return FALSE;
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
void process_input() {
    /*
    * Processess input
    */
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_Quit:
        game_up = FALSE;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        game_up = FALSE;
        break;
    }
    }
void setup() {
    /*
    * Initialize ball struct
    */
    
    ball.x = 20;
    ball.y = 20;
    ball.width = 15;
    ball.height = 15;
}

void update(void) {
    /*
    * Logic to keep a fixed timestep
    * Waste some time /sleep untill we reach the frame target
    */


    /* Get a delta time factor converted to seconds to be used to update my objects */
    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

    last_frame_time = SDL_GetTicks();

    ball.x += 30 * delta_time;
    ball.y += 40 * delta_time;

    }

void render() {
    /*
    * Renders input
    */

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /*
    * Start drawing
    */
    SDL_Rect ball_rect = {
        (int)ball.x,
        (int)ball.y,
        (int)ball.width,
        (int)ball.height
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball_rect);

    SDL_RenderPresent(renderer);
}
void destroy_window(){
    /* 
    * Destroys all that was created or initialize
    */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_QUIT();
}
int main() {
    game_up = initialize_window();

    setup();

    /* Game loop*/
    while (game_up) {
        /* 
        * Handle input (e.g., player movement)
        */
        process_input();
        update();
        render();
        }

    /* Cleanup and exit */

    destroy_window();

    return 0;
}
