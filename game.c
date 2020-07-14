#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "audio.h"
#include "camera.h"
#include "character.h"
#include "config.h"
#include "controls.h"
#include "game.h"
#include "general.h"
#include "screen.h"
#include "vector.h"
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
		case SDL_KEYDOWN:
			handle_input(event.key);
			break;
		case SDL_KEYUP:
			handle_input(event.key);
		default:
			break;
	}

	return loop_condition;
}

void play()
{
	/* Play music. */
	play_soundtrack("resources/sacredwar.mp3");


	SDL_Window *window = open_window(MAIN_WINDOW_TITLE);
	SDL_Surface *window_surface = NULL;



	TTF_Init();

	TTF_Font *Mono = TTF_OpenFont("resources/m5x7.ttf", 24);
	SDL_Color White = {255, 255, 255};
	SDL_Color Black = {0, 0, 0};
	SDL_Surface *message;
	//SDL_Surface *message = TTF_RenderText_Solid(Mono, "59.9 fps", White);




	/* This is the representation of the game screen. It has the proper
	 * pixel dimensions. We will scale this surface to fit within the
	 * window. */
	SDL_Surface *game_screen = create_game_screen(GAME_SCREEN_WIDTH,
						      GAME_SCREEN_HEIGHT);

	/* Load screen resources. */
	load_screen_resources();

	/* Define the character. */
	LINK.position.x = 330;
	LINK.position.y = 247;
	LINK.w = 32;
	LINK.h = 32;
	LINK.animation = LINK_IDLE_SOUTH;

	char s[100];

	bool loop_condition = true;
	while (loop_condition) {

		/* Handle any events, like a close request, a key press, or a
		 * key release. If a close request is given, then the game loop
		 * is broken. */
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
			loop_condition = handle_event(event);



		/* Move character and draw it. */
		LINK = character_movement_interface(LINK, 1.5);
		//struct Vector v_N = {LINK.x, LINK.y};
		struct Vector v_N = get_character_center(LINK);
		struct Vector v_C = get_camera_center(CAMERA);
		struct Vector v = subtract(v_N, v_C);
		CAMERA = move_camera(CAMERA, v);
		//draw_character(LINK, TEST_REGION);



		/* Overwrite every pixel in the window surface and in the game
		 * screen with a solid color, and draw the game screen. */
		window_surface = SDL_GetWindowSurface(window);
		SDL_FillRect(window_surface, NULL,
			     SDL_MapRGB(window_surface->format,
					0x00, 0x00, 0x00));
		SDL_FillRect(game_screen, NULL,
			     SDL_MapRGB(game_screen->format,
					0xff, 0xff, 0xff));
		draw_game_screen(game_screen);



		/* Evenly scale the game screen to fit snuggly within the main
		 * window screen. */
		letterbox(game_screen, window_surface);




		sprintf(s, "%d", TIME);
		message = TTF_RenderText_Solid(Mono, s, White);
		SDL_BlitSurface(message, NULL, window_surface, NULL);

		/* Update the main window surface to reflect changes, and sleep
		 * for a specified amount of milliseconds. */
		SDL_UpdateWindowSurface(window);
		SDL_Delay(1000 / DESIRED_FPS);
		TIME++;
	}
}
