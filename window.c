#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.h"

SDL_Window* open_window(const char *name)
{
	SDL_Window *window = NULL;

	Uint32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	window = SDL_CreateWindow(name,
				  SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED,
				  300, 300, window_flags);
	SDL_SetWindowMinimumSize(window, 200, 200);
	
	int img_flags = IMG_INIT_PNG;

	return window;
}

/* Creates an SDL surface, with a height and width given in pixels. */
SDL_Surface* create_game_screen(int pixel_width, int pixel_height)
{
	SDL_Surface *surface = NULL;
	Uint32 rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	rmask = 0xff000000;
	gmask = 0x00ff0000;
	bmask = 0x0000ff00;
	amask = 0x000000ff;
#else
	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
#endif

	surface = SDL_CreateRGBSurface(0, pixel_width, pixel_height, 32,
				       rmask, gmask, bmask, amask);

	return surface;
}

/* This function takes an SDL Surface src, and scales it evenly so that it fits
 * snuggly within the surface dst. This function has no return value, so it has
 * to alter dst. */
void letterbox(SDL_Surface *src, SDL_Surface *dst)
{
	double w_src = (double) src->w;
	double h_src = (double) src->h;
	double w_dst = (double) dst->w;
	double h_dst = (double) dst->h;

	double ratio_src = w_src / h_src;
	double ratio_dst = w_dst / h_dst;

	double w_new, h_new;
	int x_new, y_new; // coordinates of the top-left corner of the surface

	if (ratio_dst == ratio_src) {
		w_new = w_dst;
		h_new = h_dst;

		x_new = 0;
		y_new = 0;
	} else if (ratio_dst < ratio_src) {
		w_new = w_dst;
		h_new = w_dst / ratio_src;

		int delta = h_dst - h_new;
		x_new = 0;
		y_new = (int) round(delta / 2);
	} else if (ratio_dst > ratio_src) {
		w_new = h_dst * ratio_src;
		h_new = h_dst;

		int delta = w_dst - w_new;
		x_new = (int) round(delta / 2);
		y_new = 0;
	}

	SDL_Rect rect;
	rect.x = x_new;
	rect.y = y_new;
	rect.w = w_new;
	rect.h = h_new;

	/* Null, because we're selecting the entirety of src and placing it
	 * within a portion of dst, defined by the rectangle rect. */
	SDL_BlitScaled(src, NULL, dst, &rect);
}
