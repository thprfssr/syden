#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "camera.h"
#include "config.h"
#include "controls.h"
#include "general.h"
#include "screen.h"
#include "tiles.h"


/* This function is tasked with calling all the necessary functions to draw
 * everything in the game screen. It is assumed that the surface has already
 * been overwritten with a solid color. */
void draw_game_screen(SDL_Surface *screen)
{
	/* Load resources. */
	SDL_Surface *tile_atlas = load_resource(TILE_ATLAS_PATH);
	char *map_csv = read_file("resources/test_map.csv");

	/* Move the camera if a button is pressed. */
	camera_movement_interface(2.5);

	/* Copy the region onto the screen. */
	SDL_Surface *region = draw_region(tile_atlas, map_csv);
	int X = round(CAMERA_POSITION_X);
	int Y = round(CAMERA_POSITION_Y);
	camera_view(region, screen, X, Y);

	/* Free resources. */
	SDL_FreeSurface(region);
	free(map_csv);
}
