#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"
#include "window.h"

/* If this function returns true, then the game loop continues. If it returns
 * false, then the game loop is broken. */
bool handle_event(SDL_Event event)
{
	bool loop_condition = true;
	switch (event.type) {
		case SDL_QUIT:
			loop_condition = false;
			break;
		default:
			break;
	}

	return loop_condition;
}

void play()
{
	SDL_Window *window = open_window("Test Window");
	SDL_Surface *window_surface = NULL;

	/* This is the representation of the game screen. It has the proper
	 * pixel dimensions. We will scale this surface to fit within the
	 * window. */
	SDL_Surface *game_screen = create_game_screen(100, 100);

	bool loop_condition = true;
	while (loop_condition) {

		/* Handle any events, like a close request, a key press, or a
		 * key release. If a close request is given, then the game loop
		 * is broken. */
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
			loop_condition = handle_event(event);

		/* Overwrite every pixel in the window surface and in the game
		 * screen with a solid color. */
		window_surface = SDL_GetWindowSurface(window);
		SDL_FillRect(window_surface, NULL,
			     SDL_MapRGB(window_surface->format,
					0x00, 0x00, 0x00));
		SDL_FillRect(game_screen, NULL,
			     SDL_MapRGB(game_screen->format,
					0xff, 0xff, 0xff));

		/* Evenly scale the game screen to fit snuggly within the main
		 * window screen. */
		letterbox(game_screen, window_surface);

		/* Update the main window surface to reflect changes, and sleep
		 * for a specified amount of milliseconds. */
		SDL_UpdateWindowSurface(window);
		SDL_Delay(16); // Sleep for however many milliseconds.
	}
}
