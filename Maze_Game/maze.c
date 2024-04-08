#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
SDL_Rect playerRect = { (int)(playerX * SCREEN_WIDTH / MAP_WIDTH), (int)(playerY * SCREEN_HEIGHT / MAP_HEIGHT), 5, 5 };
SDL_RenderFillRect(renderer, &playerRect);

SDL_RenderPresent(renderer);

bool isWallCollision(float x, float y) {
    int mapX = (int)(x * MAP_WIDTH / SCREEN_WIDTH);
    int mapY = (int)(y * MAP_HEIGHT / SCREEN_HEIGHT);
    return map[mapX][mapY] == 1;
}
void handleInput(SDL_Event* event) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
        case SDLK_w:
            if (!isWallCollision(playerX + MOVE_SPEED * cos(playerAngle), playerY + MOVE_SPEED * sin(playerAngle))) {
                playerX += MOVE_SPEED * cos(playerAngle);
                playerY += MOVE_SPEED * sin(playerAngle);
            }
            break;
        case SDLK_a:
            if (!isWallCollision(playerX - MOVE_SPEED * cos(playerAngle + M_PI / 2), playerY - MOVE_SPEED * sin(playerAngle + M_PI / 2))) {
                playerX -= MOVE_SPEED * cos(playerAngle + M_PI / 2);
                playerY -= MOVE_SPEED * sin(playerAngle + M_PI / 2);
            }
            break;
        case SDLK_s:
            if (!isWallCollision(playerX - MOVE_SPEED * cos(playerAngle), playerY - MOVE_SPEED * sin(playerAngle))) {
                playerX -= MOVE_SPEED * cos(playerAngle);
                playerY -= MOVE_SPEED * sin(playerAngle);
            }
            break;
        case SDLK_d:
            if (!isWallCollision(playerX + MOVE_SPEED * cos(playerAngle + M_PI / 2), playerY + MOVE_SPEED * sin(playerAngle + M_PI / 2))) {
                playerX += MOVE_SPEED * cos(playerAngle + M_PI / 2);
                playerY += MOVE_SPEED * sin(playerAngle + M_PI / 2);
            }
            break;
        }
    }
}


