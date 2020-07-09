#include <math.h>
#include <SDL2/SDL.h>

#include "animation.h"
#include "character.h"
#include "controls.h"
#include "general.h"
#include "vector.h"

/* Define the character Nestor */
struct Character Nestor;



void draw_character(struct Character c, SDL_Surface *frame, SDL_Surface *background)
{
	SDL_Rect *rect = malloc(sizeof(SDL_Rect));
	rect->x = (int) round(c.position.x);
	rect->y = (int) round(c.position.y);
	rect->h = c.h;
	rect->w = c.w;

	/*
	SDL_FillRect(background, rect, SDL_MapRGB(background->format,
				0x00, 0x00, 0x00));
	*/
	SDL_BlitSurface(frame, NULL, background, rect);
}

struct Character move_character(struct Character c, struct Vector v, double magnitude)
{
	/* Round the coordinates if the direction of movement changes. */
	struct Vector N = {signum(v.x), signum(v.y)};
	if (!equal(c.direction, N))
		c.position = round_vector(c.position);
	c.direction = N;

	c.position = add(c.position, v);

	return set_character_animation(c);
}

struct Character character_movement_interface(struct Character c, double magnitude)
{
	struct Vector v = generate_direction();
	v = scale(v, magnitude);

	return move_character(c, v, magnitude);
}

struct Vector get_character_center(struct Character c)
{
	struct Vector v = ZERO;
	v.x = c.position.x + (double) c.w / 2;
	v.y = c.position.y + (double) c.h / 2;

	return v;
}

struct Character set_character_animation(struct Character c)
{
	struct Vector v = normalize(c.direction);
	if (equal(v, VEC_N))
		c.animation = LINK_WALKING_NORTH;
	else if (equal(v, VEC_S))
		c.animation = LINK_WALKING_SOUTH;
	else if (equal(v, VEC_E))
		c.animation = LINK_WALKING_EAST;
	else if (equal(v, VEC_W))
		c.animation = LINK_WALKING_WEST;
	else
		c.animation = LINK_IDLE_SOUTH;

	return c;
}
