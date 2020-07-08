#include <math.h>
#include <SDL2/SDL.h>

#include "character.h"
#include "general.h"
#include "vector.h"

/* Define the character Nestor */
struct Character Nestor = {0, 0, 16, 16};



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

void move_character(struct Character c, struct Vector v, double magnitude)
{
	c.x += v.x;
	c.y += v.y;
}
