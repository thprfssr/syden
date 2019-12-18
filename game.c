#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"
#include "window.h"

void play()
{
	SDL_Window *window = open_window("Test Window");
	SDL_Surface *window_surface = NULL;

	/* This is the representation of the game screen. It has the proper
	 * pixel dimensions. We will scale this surface to fit within the
	 * window. */
	SDL_Surface *game_screen = create_game_screen(100, 100);


	while (true) {

		/* Overwrite every pixel in the window surface and in the game
		 * screen with a solid color. */
		window_surface = SDL_GetWindowSurface(window);
		SDL_FillRect(window_surface, NULL,
			     SDL_MapRGB(window_surface->format,
					0x00, 0x00, 0x00));
		SDL_FillRect(game_screen, NULL,
			     SDL_MapRGB(game_screen->format,
					0xff, 0xff, 0xff));

		SDL_UpdateWindowSurface(window);
		SDL_Delay(16); // Sleep for however many milliseconds.
	}
}
