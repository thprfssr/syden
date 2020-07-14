#include <SDL2/SDL.h>

#include "animation.h"
#include "general.h"



struct Animation *LINK_WALKING_SOUTH;
struct Animation *LINK_WALKING_NORTH;
struct Animation *LINK_WALKING_WEST;
struct Animation *LINK_WALKING_EAST;
struct Animation *LINK_IDLE_SOUTH;
struct Animation *LINK_IDLE_NORTH;
struct Animation *LINK_IDLE_WEST;
struct Animation *LINK_IDLE_EAST;

SDL_Surface* get_animation_frame(struct Animation *animation, int index)
{
	SDL_Rect src;
	src.w = animation->w;
	src.h = animation->h;
	src.x = index * animation->w;
	src.y = 0;

	SDL_Surface *frame = SDL_CreateRGBSurface(0, src.w, src.h, 32,
			RMASK, GMASK, BMASK, AMASK);
	SDL_BlitSurface(animation->surface, &src, frame, NULL);

	return frame;
}




void load_animation(struct Animation *animation, char *json_str, char *key)
{
	char *obj = get_json_entry(json_str, key);

	animation->frame_count = atoi(get_json_entry(obj, "frame-count"));

	char *filename = get_json_entry(obj, "filename");
	animation->surface = load_resource(filename);

	animation->w = atoi(get_json_entry(json_str, "width"));
	animation->h = atoi(get_json_entry(json_str, "height"));
	animation->current_frame = 0;
}
