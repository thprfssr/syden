#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>

struct Character
{
	double x;
	double y;
	int w;
	int h;
};

extern struct Character Nestor;


void draw_character(struct Character c, SDL_Surface *background);

#endif
