#include <SDL2/SDL.h>

#include "animation.h"

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
