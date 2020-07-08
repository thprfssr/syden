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
	rect->x = (int) round(c.x);
	rect->y = (int) round(c.y);
	rect->h = c.h;
	rect->w = c.w;

	SDL_FillRect(background, rect, SDL_MapRGB(background->format,
				0x00, 0x00, 0x00));
}

struct Character move_character(struct Character c, struct Vector v, double magnitude)
{
	c.x += v.x;
	c.y += v.y;

	return c;
}

struct Character character_movement_interface(struct Character c, double magnitude)
{
	struct Vector v = generate_vector();
	v = scale(v, magnitude);

	return move_character(c, v, magnitude);
}
