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

	/* Obtain region dimensions and other parameters. */
	int H = count_lines(map_csv);
	int W = count_first_line_entries(map_csv);
	int S = TILE_SIDE_LENGTH;

	/* Get first entry from csv-formatted string. */
	char *delim = ",\n";
	char *entry = strtok(map_csv, delim);

	for (int i = 0; i < H * W; i++) {
		/* Create destination rectangle. */
		SDL_Rect dst;
		dst.x = S * (i % W);
		dst.y = S * (i / W);
		dst.w = S;
		dst.h = S;

		/* Get tile code. */
		int code = atoi(entry);

		/* Copy tile onto screen. */
		SDL_Surface *tile = get_tile(tile_atlas, code);
		SDL_BlitSurface(tile, NULL, screen, &dst);

		/* Free resources, and update the `entry` variable. */
		SDL_FreeSurface(tile);
		entry = strtok(NULL, delim);
	}


	/* Free the resources. */
	SDL_FreeSurface(tile_atlas);
	free(map_csv);
}
