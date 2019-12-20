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
	char *map_csv = read_file("resources/test_map.csv");

	SDL_Surface *region = draw_region(tile_atlas, map_csv);
	SDL_BlitSurface(region, NULL, screen, NULL);

	SDL_FreeSurface(region);
}
