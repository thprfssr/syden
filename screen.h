#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Surface *TILE_ATLAS;
extern char *MAP_CSV;
extern SDL_Surface *TEST_REGION;

void load_screen_resources();
void draw_game_screen(SDL_Surface *screen);

#endif
