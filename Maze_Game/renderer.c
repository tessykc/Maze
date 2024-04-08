#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL_render.h>


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

SDL_Window* window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
if (!window) {
    fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
}
int map[SCREEN_WIDTH][SCREEN_HEIGHT] = {
    // Initializing map (e.g., walls, empty spaces)
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

// Player position and viewing direction
double playerX = 5.0;
double playerY = 5.0;
double playerAngle = M_PI / 3.0; // 60 degrees

//Global declaration
double rayAngle;
double rayDirX;
double rayDirY;

void castRays() {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate ray direction
        double rayAngle = playerAngle - M_PI / 6.0 + (x * M_PI / 3.0) / SCREEN_WIDTH;
        double rayDirX = cos(rayAngle);
        double rayDirY = sin(rayAngle);

        // DDA algorithm to find distance to wall
        double distanceToWall = 0.0;
        while (map[(int)playerX][(int)playerY] == 0) {
            playerX += rayDirX;
            playerY += rayDirY;
            distanceToWall += 1.0;
        }

        // Draw vertical line based on distance and wall height
        double wallHeight = SCREEN_HEIGHT / distanceToWall;
        // Render the wall segment at column x with height wallHeight
        int SDL_SetRenderTarget(SDL_Renderer * renderer, SDL_Texture * texture);
            return 0;
        
    }
}

int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

float playerX = 3.0f;
float playerY = 3.0f;
float playerAngle = 0.0f;


void render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int x;
    int y;
    for (x = 0; x < SCREEN_WIDTH; x++) {
        float rayAngle = playerAngle - M_PI / 6 + ((float)x / SCREEN_WIDTH) * (M_PI / 3);
        float distanceToWall = 0;
        bool hitWall = false;
        float rayX = playerX;
        float rayY = playerY;

        float dx = cos(rayAngle);
        float dy = sin(rayAngle);

        while (!hitWall && distanceToWall < 16) {
            distanceToWall += 0.1;
            int testX = rayX + distanceToWall * dx;
            int testY = rayY + distanceToWall * dy;

            if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT) {
                hitWall = true;
                distanceToWall = 16;
            }
            else {
                if (map[testX][testY] == 1) {
                    hitWall = true;
                }
            }

        }

        int lineHeight = (int)(SCREEN_HEIGHT / distanceToWall);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, x, SCREEN_HEIGHT / 2 - lineHeight / 2, x, SCREEN_HEIGHT / 2 + lineHeight / 2);
    
        // Example color constants 
        #define COLOR_NORTH_SOUTH 0x0000FF // Blue
        #define COLOR_EAST_WEST 0xFF0000   // Red

        // Determine wall orientation (NORTH/SOUTH or EAST/WEST)
        bool isNorthSouthWall = (fabs(rayDirY) > fabs(rayDirX));

        // Choose color based on orientation
        uint32_t wallColor = isNorthSouthWall ? COLOR_NORTH_SOUTH : COLOR_EAST_WEST;

       // Draw vertical line with wallColor
        SDL_RenderDrawLine(renderer, y, SCREEN_HEIGHT / 2 - lineHeight / 2, x, SCREEN_HEIGHT / 2 + lineHeight / 2);
            }
    SDL_RenderPresent(renderer);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
