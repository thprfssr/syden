#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
