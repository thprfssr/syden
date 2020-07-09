#include <SDL2/SDL.h>

#include "animation.h"


struct Animation LINK_WALKING_SOUTH = {NULL, 10, 32, 32,
	"resources/link_walking_south.png"};
struct Animation LINK_WALKING_NORTH = {NULL, 10, 32, 32,
	"resources/link_walking_north.png"};
struct Animation LINK_WALKING_WEST = {NULL, 10, 32, 32,
	"resources/link_walking_west.png"};
struct Animation LINK_WALKING_EAST = {NULL, 10, 32, 32,
	"resources/link_walking_east.png"};
struct Animation LINK_IDLE_SOUTH = {NULL, 1, 32, 32,
	"resources/link_idle_south.png"};
struct Animation LINK_IDLE_NORTH = {NULL, 1, 32, 32,
	"resources/link_idle_north.png"};
struct Animation LINK_IDLE_WEST = {NULL, 1, 32, 32,
	"resources/link_idle_west.png"};
struct Animation LINK_IDLE_EAST = {NULL, 1, 32, 32,
	"resources/link_idle_east.png"};

SDL_Surface* get_animation_frame(struct Animation animation, int index)
{
	SDL_Rect src;
	src.w = animation.w;
	src.h = animation.h;
	src.x = index * animation.w;
	src.y = 0;

	SDL_Surface *frame = SDL_CreateRGBSurface(0, src.w, src.h,
			32, 0, 0, 0, 0);
	SDL_BlitSurface(animation.surface, &src, frame, NULL);

	return frame;
}
