#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>

#include "vector.h"

struct Character
{
	double x;
	double y;
	int w;
	int h;
};

extern struct Character Nestor;


void draw_character(struct Character c, SDL_Surface *background);
void move_character(struct Character c, struct Vector v, double magnitude);

#endif
