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
