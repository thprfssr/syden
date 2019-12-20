#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "config.h"
#include "general.h"

/* This function accepts a given tile atlas and an integer, and returns the n-th
 * tile within the tile atlas. */
SDL_Surface* get_tile(SDL_Surface *tile_atlas, int n)
{
	int W = NUMBER_OF_TILES_HORIZONTALLY_LAID_IN_TILE_ATLAS;
	int S = TILE_SIDE_LENGTH;
	int x = S * (n % W);
	int y = S * (n / W);

	SDL_Rect src;
	src.x = x;
	src.y = y;
	src.w = S;
	src.h = S;

	SDL_Surface *tile = SDL_CreateRGBSurface(0, S, S, 32, 0, 0, 0, 0);
	SDL_BlitSurface(tile_atlas, &src, tile, NULL);

	return tile;
}
