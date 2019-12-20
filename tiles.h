#ifndef TILES_H
#define TILES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* This function accepts a given tile atlas and an integer, and returns the n-th
 * tile within the tile atlas. */
SDL_Surface* get_tile(SDL_Surface *tile_atlas, int n);
SDL_Surface* draw_region(SDL_Surface *tile_atlas, char *map_csv);

#endif
