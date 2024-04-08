#pragma once
#ifdef MAZE_H
#define MAZE_H

void render(SDL_Renderer* renderer);
void SDL_Quit(void);
void castRays();
void handleInput(SDL_Event* event);
bool isWallCollision(float x, float y);

#endif // MAZE_H
