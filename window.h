#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window* open_window(const char *name);
SDL_Surface* create_game_screen(int pixel_width, int pixel_height);
void letterbox(SDL_Surface *src, SDL_Surface *dst);
