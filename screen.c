#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "animation.h"
#include "camera.h"
#include "character.h"
#include "config.h"
#include "controls.h"
#include "general.h"
#include "screen.h"
#include "tiles.h"

SDL_Surface *TILE_ATLAS = NULL;
char *MAP_CSV = NULL;
SDL_Surface *TEST_REGION = NULL;
SDL_Surface *CANVAS = NULL;

/* Load resources. */
void load_screen_resources()
{

	LINK_WALKING_SOUTH = malloc(sizeof(struct Animation));
	LINK_WALKING_NORTH = malloc(sizeof(struct Animation));
	LINK_WALKING_WEST = malloc(sizeof(struct Animation));
	LINK_WALKING_EAST = malloc(sizeof(struct Animation));
	LINK_IDLE_SOUTH = malloc(sizeof(struct Animation));
	LINK_IDLE_NORTH = malloc(sizeof(struct Animation));
	LINK_IDLE_WEST = malloc(sizeof(struct Animation));
	LINK_IDLE_EAST = malloc(sizeof(struct Animation));

	LINK_WALKING_SOUTH->frame_count = 10;
	LINK_WALKING_NORTH->frame_count = 10;
	LINK_WALKING_WEST->frame_count = 10;
	LINK_WALKING_EAST->frame_count = 10;
	LINK_IDLE_SOUTH->frame_count = 1;
	LINK_IDLE_NORTH->frame_count = 1;
	LINK_IDLE_WEST->frame_count = 1;
	LINK_IDLE_EAST->frame_count = 1;

	LINK_WALKING_SOUTH->w = 32;
	LINK_WALKING_NORTH->w = 32;
	LINK_WALKING_WEST->w = 32;
	LINK_WALKING_EAST->w = 32;
	LINK_IDLE_SOUTH->w = 32;
	LINK_IDLE_NORTH->w = 32;
	LINK_IDLE_WEST->w = 32;
	LINK_IDLE_EAST->w = 32;

	LINK_WALKING_SOUTH->h = 32;
	LINK_WALKING_NORTH->h = 32;
	LINK_WALKING_WEST->h = 32;
	LINK_WALKING_EAST->h = 32;
	LINK_IDLE_SOUTH->h = 32;
	LINK_IDLE_NORTH->h = 32;
	LINK_IDLE_WEST->h = 32;
	LINK_IDLE_EAST->h = 32;

	LINK_WALKING_SOUTH->current_frame = 0;
	LINK_WALKING_NORTH->current_frame = 0;
	LINK_WALKING_WEST->current_frame = 0;
	LINK_WALKING_EAST->current_frame = 0;
	LINK_IDLE_SOUTH->current_frame = 0;
	LINK_IDLE_NORTH->current_frame = 0;
	LINK_IDLE_WEST->current_frame = 0;
	LINK_IDLE_EAST->current_frame = 0;

	LINK_WALKING_SOUTH->filename = "resources/link_walking_south.png";
	LINK_WALKING_NORTH->filename = "resources/link_walking_north.png";
	LINK_WALKING_WEST->filename = "resources/link_walking_west.png";
	LINK_WALKING_EAST->filename = "resources/link_walking_east.png";
	LINK_IDLE_SOUTH->filename = "resources/link_idle_south.png";
	LINK_IDLE_NORTH->filename = "resources/link_idle_north.png";
	LINK_IDLE_WEST->filename = "resources/link_idle_west.png";
	LINK_IDLE_EAST->filename = "resources/link_idle_east.png";

	TILE_ATLAS = load_resource(TILE_ATLAS_PATH);
	MAP_CSV = read_file("resources/test_map.csv");
	TEST_REGION = draw_region(TILE_ATLAS, MAP_CSV);
	CANVAS = draw_region(TILE_ATLAS, MAP_CSV);
	//SDL_BlitSurface(TILE_ATLAS, NULL, CANVAS, NULL);
	LINK_WALKING_SOUTH->surface = load_resource(LINK_WALKING_SOUTH->filename);
	LINK_WALKING_NORTH->surface = load_resource(LINK_WALKING_NORTH->filename);
	LINK_WALKING_WEST->surface = load_resource(LINK_WALKING_WEST->filename);
	LINK_WALKING_EAST->surface = load_resource(LINK_WALKING_EAST->filename);

	LINK_IDLE_SOUTH->surface = load_resource(LINK_IDLE_SOUTH->filename);
	LINK_IDLE_NORTH->surface = load_resource(LINK_IDLE_NORTH->filename);
	LINK_IDLE_WEST->surface = load_resource(LINK_IDLE_WEST->filename);
	LINK_IDLE_EAST->surface = load_resource(LINK_IDLE_EAST->filename);

	load_character(TEST_CHARACTER, "resources/link.json");
}


/* This function is tasked with calling all the necessary functions to draw
 * everything in the game screen. It is assumed that the surface has already
 * been overwritten with a solid color. */
void draw_game_screen(SDL_Surface *screen)
{
	/* Move the camera if a button is pressed. */
	//camera_movement_interface(1.5);
	
	/* Copy the region onto the canvas. */
	SDL_BlitSurface(TEST_REGION, NULL, CANVAS, NULL);

	/* Draw the character on the canvas. */
	//draw_character(LINK, CANVAS);

	/* Draw link. */
	SDL_Surface *frame = get_animation_frame(LINK->animation, (TIME / 3) % LINK->animation->frame_count);
	draw_character(LINK, frame, CANVAS);

	//SDL_BlitSurface(frame, NULL, CANVAS, NULL);
	SDL_FreeSurface(frame);

	/* Copy the canvas onto the screen. */
	int X = (int) round(CAMERA->position.x); //get_camera_position_x();
	int Y = (int) round(CAMERA->position.y); //get_camera_position_y();

	camera_view(CAMERA, screen);
}
