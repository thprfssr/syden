#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "camera.h"
#include "config.h"
#include "controls.h"
#include "general.h"
#include "screen.h"
#include "tiles.h"

SDL_Surface *TILE_ATLAS = NULL;
char *MAP_CSV = NULL;
SDL_Surface *TEST_REGION = NULL;

/* Load resources. */
void load_screen_resources()
{
	TILE_ATLAS = load_resource(TILE_ATLAS_PATH);
	MAP_CSV = read_file("resources/test_map.csv");
	TEST_REGION = draw_region(TILE_ATLAS, MAP_CSV);
}


/* This function is tasked with calling all the necessary functions to draw
 * everything in the game screen. It is assumed that the surface has already
 * been overwritten with a solid color. */
void draw_game_screen(SDL_Surface *screen)
{
	/* Move the camera if a button is pressed. */
	//camera_movement_interface(1.5);

	/* Copy the region onto the screen. */
	int X = (int) round(CAMERA.position.x); //get_camera_position_x();
	int Y = (int) round(CAMERA.position.y); //get_camera_position_y();
	camera_view(TEST_REGION, screen, X, Y);
}
