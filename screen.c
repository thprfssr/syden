#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "config.h"
#include "general.h"
#include "tiles.h"

/* This function is tasked with calling all the necessary functions to draw
 * everything in the game screen. It is assumed that the surface has already
 * been overwritten with a solid color. */
void draw_game_screen(SDL_Surface *screen)
{
	SDL_Surface *tile_atlas = load_resource(TILE_ATLAS_PATH);
	SDL_Surface *tile = get_tile(tile_atlas, 0);

	SDL_BlitSurface(tile, NULL, screen, NULL);

	SDL_FreeSurface(tile_atlas);
	SDL_FreeSurface(tile);
}
