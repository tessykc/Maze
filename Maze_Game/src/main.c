#include <stdio.h>
#include <stdbool.h>
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
    char input; 
    char maze[5]; /* Declare the array without initializing it here */
    int i; /* Declare the loop counter variable here */

    /* Initialize the maze array */
    maze[0] = 'N';
    maze[1] = 'S';
    maze[2] = 'E';
    maze[3] = 'W';
    maze[4] = 'N';

    game_up = initialize_window();

    setup();
    

    while (game_up) {
        process_input();
        update();
        render();
        input = getchar();
        moveCamera(input);
        /*
        * Rotate camera based on arrow key input
        */
        if (input == 'L') { /* Left arrow key */ 
            rotateCamera('L');
        } else if (input == 'R') { /* Right arrow key */
            rotateCamera('R');
        }
    }

            
    /*
    * Render the maze
    */
    for (i = 0; i < 5; i++) {
        setWallColor(maze[i]);
    }
    
    return 0;

    destroy_window();

    return 0;
}
