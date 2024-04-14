#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
 * Defining speed for camera and player movement
 */

#define MOVE_SPEED 0.1f

/*
 * Global variables for camera position and direction
 */

double cameraX = 0.0; /* Initial X position */
double cameraY = 0.0; /* Initial Y position*/
double cameraAngle = 0.0; /* Initial camera angle (in radians)*/

/*
 * Global variables for player position and direction
 */

double playerX;
double playerY;
double playerAngle;

void handleInput(SDL_Event* event) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
        case SDLK_w:
            playerX += MOVE_SPEED * cos(playerAngle);
            playerY += MOVE_SPEED * sin(playerAngle);
            break;
        case SDLK_a:
            playerX -= MOVE_SPEED * cos(playerAngle + M_PI / 2);
            playerY -= MOVE_SPEED * sin(playerAngle + M_PI / 2);
            break;
        case SDLK_s:
            playerX -= MOVE_SPEED * cos(playerAngle);
            playerY -= MOVE_SPEED * sin(playerAngle);
            break;
        case SDLK_d:
            playerX += MOVE_SPEED * cos(playerAngle + M_PI / 2);
            playerY += MOVE_SPEED * sin(playerAngle + M_PI / 2);
            break;
        case SDLK_LEFT:
            playerAngle -= 0.1f;
            break;
        case SDLK_RIGHT:
            playerAngle += 0.1f;
            break;
        case SDLK_UP:
            playerAngle -= 0.1f;
            break;
        case SDLK_DOWN:
            playerAngle += 0.1f;
            break;
	}
        switch (event->key.keysym.sym) {
        case SDLK_LEFT:
            cameraAngle -= 0.05; /*Adjust rotation angle (e.g., 5 degrees)*/
            break;
        case SDLK_RIGHT:
            cameraAngle += 0.05;
            break;
        case SDLK_UP:
            cameraAngle += 0.05;
            break;
        case SDLK_DOWN:
            cameraAngle += 0.05;
            break;
        }
    }
}
