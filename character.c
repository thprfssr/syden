#include <math.h>
#include <SDL2/SDL.h>

#include "character.h"
#include "controls.h"
#include "general.h"
#include "vector.h"

/* Define the character Nestor */
struct Character Nestor;



void draw_character(struct Character c, SDL_Surface *background)
{
	SDL_Rect *rect = malloc(sizeof(SDL_Rect));
	rect->x = (int) round(c.position.x);
	rect->y = (int) round(c.position.y);
	rect->h = c.h;
	rect->w = c.w;

	SDL_FillRect(background, rect, SDL_MapRGB(background->format,
				0x00, 0x00, 0x00));
}

struct Character move_character(struct Character c, struct Vector v, double magnitude)
{
	/* Round the coordinates if the direction of movement changes. */
	struct Vector N = {signum(c.position.x), signum(c.position.y)};
	if (!equal(c.direction, N)) {
		c.position.x = round(c.position.x);
		c.position.y = round(c.position.y);
	}


	c.position = add(c.position, v);

	return c;
}

struct Character character_movement_interface(struct Character c, double magnitude)
{
	struct Vector v = generate_vector();
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
