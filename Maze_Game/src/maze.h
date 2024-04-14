#ifndef __Maze_H__

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define MAP_WIDTH FPS  60
#define  FRAME_TARGET_TIME (1000/FPS)

#define NORTH_SOUTH_COLOR "Red"
#define EAST_WEST_COLOR "Blue"


int initialize_window(void);
void process_input(void);
void setup(void);
void update(void);
void render(void);
void destroy_window(void);
void setWallColor(char orientation);
void rotateCamera(char direction);
void moveCamera(char direction);
void handleInput(SDL_Event* event);

#endif
