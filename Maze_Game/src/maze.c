#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "maze.h"

/*
* Function to set wall color based on orientation
*/
void setWallColor(char orientation) {
    if (orientation == 'N' || orientation == 'S') {
        printf("Set wall color to %s\n", NORTH_SOUTH_COLOR);
    } else if (orientation == 'E' || orientation == 'W') {
        printf("Set wall color to %s\n", EAST_WEST_COLOR);
    }
}

/*
* Function to rotate camera based on input
*/
void rotateCamera(char direction) {
    /* Rotate camera based on the direction */
    if (direction == 'L') {
        /* Rotate camera to the left */
        printf("Camera rotated to the left\n");
    } else if (direction == 'R') {
        /* Rotate camera to the right */
        printf("Camera rotated to the right\n");
    }
}

/*
* Function to move camera based on input
*/
void moveCamera(char direction) {
    switch (direction) {
        case 'W':
            printf("Move camera forward\n");
            break;
        case 'A':
            printf("Move camera left\n");
            break;
        case 'S':
            printf("Move camera backward\n");
            break;
        case 'D':
            printf("Move camera right\n");
            break;
        default:
            printf("Invalid input\n");
    }
}

