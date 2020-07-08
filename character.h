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
struct Character move_character(struct Character c, struct Vector v, double magnitude);
struct Character character_movement_interface(struct Character c, double magnitude);
double get_character_center_x(struct Character c);
double get_character_center_y(struct Character c);

#endif
