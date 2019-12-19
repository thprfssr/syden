#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define MAIN_WINDOW_TITLE "Syden"
#define GAME_SCREEN_WIDTH 256
#define GAME_SCREEN_HEIGHT 144
#define DESIRED_FPS 60

bool handle_event(SDL_Event event);
void play();

#endif
