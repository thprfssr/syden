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

	struct Animation *animation;



	struct Animation *walking_north;
	struct Animation *walking_south;
	struct Animation *walking_east;
	struct Animation *walking_west;
	struct Animation *idle_north;
	struct Animation *idle_south;
	struct Animation *idle_east;
	struct Animation *idle_west;
};

extern struct Character *LINK;
extern struct Character *TEST_CHARACTER;

void load_character(struct Character *c, char *filename);
void draw_character(struct Character *c, SDL_Surface *frame, SDL_Surface *background);
void move_character(struct Character *c, struct Vector v, double magnitude);
void character_movement_interface(struct Character *c, double magnitude);
struct Vector get_character_center(struct Character *c);
void set_character_animation(struct Character *c);

#endif
