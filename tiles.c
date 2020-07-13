#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "config.h"
#include "general.h"
#include "tiles.h"

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

	SDL_Surface *tile = SDL_CreateRGBSurface(0, S, S, 32,
			RMASK, GMASK, BMASK, AMASK);
	SDL_BlitSurface(tile_atlas, &src, tile, NULL);

	return tile;
}

SDL_Surface* draw_region(SDL_Surface *tile_atlas, char *map_csv)
{

	/* Obtain region dimensions and other parameters. */
	int H = 32; //count_lines(map_csv);
	int W = 32; //count_first_line_entries(map_csv);
	int S = TILE_SIDE_LENGTH;

	/* Get first entry from csv-formatted string. We copy `map_csv` because
	 * the `strtok()` function alters its input. */
	int L = strlen(map_csv);
	char *copy = malloc(L * sizeof(char));
	strcpy(copy, map_csv);
	char *delim = ",\n";
	char *entry = strtok(copy, delim);

	/* Create region surface, and start the tile-fetching loop. */
	SDL_Surface *region = SDL_CreateRGBSurface(0, S*W, S*H, 32,
			RMASK, GMASK, BMASK, AMASK);
	for (int i = 0; i < H * W; i++) {
		/* Create destination rectangle. */
		SDL_Rect dst;
		dst.x = S * (i % W);
		dst.y = S * (i / W);
		dst.w = S;
		dst.h = S;

		/* Get tile code. */
		int code = atoi(entry);

		/* Copy tile onto region. */
		SDL_Surface *tile = get_tile(tile_atlas, code);
		SDL_BlitSurface(tile, NULL, region, &dst);

		/* Free resources, and update the `entry` variable. */
		SDL_FreeSurface(tile);
		entry = strtok(NULL, delim);
	}


	/* Free the resources, and return the region. */
	//SDL_FreeSurface(tile_atlas);
	free(copy);

	return region;
}
