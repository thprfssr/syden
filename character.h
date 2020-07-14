#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "animation.h"
#include "vector.h"

struct Character
{
	int w;
	int h;
	struct Vector position;

	bool is_moving;
	struct Vector moving_direction;
	struct Vector facing_direction;

	struct Animation animation;
};

extern struct Character LINK;


void draw_character(struct Character c, SDL_Surface *frame, SDL_Surface *background);
struct Character move_character(struct Character c, struct Vector v, double magnitude);
struct Character character_movement_interface(struct Character c, double magnitude);
struct Vector get_character_center(struct Character c);
struct Character set_character_animation(struct Character c);

#endif
