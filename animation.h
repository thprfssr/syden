#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>

struct Animation {
	SDL_Surface *surface;
	int frame_count;
	int w;
	int h;
	char *filename;
};

extern struct Animation LINK_WALKING_FORWARD;

SDL_Surface* get_animation_frame(struct Animation animation, int index);


#endif
