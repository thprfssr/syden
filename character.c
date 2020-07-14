#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "animation.h"
#include "character.h"
#include "controls.h"
#include "general.h"
#include "vector.h"

#include "screen.h"

/* Define the character Nestor */
struct Character *LINK;
struct Character *TEST_CHARACTER;

void load_character(struct Character *c, char *filename)
{
	char *js = read_file(filename);

	c->w = atoi(get_json_entry(js, "width"));
	c->h = atoi(get_json_entry(js, "height"));
	c->position = ZERO;
	c->position.x = 277;
	c->position.y = 313;
	c->moving_direction = ZERO;
	c->facing_direction = VEC_S;

	c->walking_north = malloc(sizeof(struct Animation));
	c->walking_south = malloc(sizeof(struct Animation));
	c->walking_east = malloc(sizeof(struct Animation));
	c->walking_west = malloc(sizeof(struct Animation));
	c->idle_north = malloc(sizeof(struct Animation));
	c->idle_south = malloc(sizeof(struct Animation));
	c->idle_east = malloc(sizeof(struct Animation));
	c->idle_west = malloc(sizeof(struct Animation));

	load_animation(c->walking_north, js, "walking-north");
	load_animation(c->walking_south, js, "walking-south");
	load_animation(c->walking_east, js, "walking-east");
	load_animation(c->walking_west, js, "walking-west");
	load_animation(c->idle_north, js, "idle-north");
	load_animation(c->idle_south, js, "idle-south");
	load_animation(c->idle_east, js, "idle-east");
	load_animation(c->idle_west, js, "idle-west");
}

void draw_character(struct Character *c, SDL_Surface *frame, SDL_Surface *background)
{
	SDL_Rect *rect = malloc(sizeof(SDL_Rect));
	rect->x = (int) round(c->position.x);
	rect->y = (int) round(c->position.y);
	rect->h = c->h;
	rect->w = c->w;

	/*
	SDL_FillRect(background, rect, SDL_MapRGB(background->format,
				0x00, 0x00, 0x00));
	*/
	SDL_BlitSurface(frame, NULL, background, rect);
}

void move_character(struct Character *c, struct Vector v, double magnitude)
{
	/* Round the coordinates if the direction of movement changes. */
	struct Vector N = {signum(v.x), signum(v.y)};
	if (!equal(c->moving_direction, N))
		c->position = round_vector(c->position);
	c->moving_direction = N;
	c->is_moving = !equal(N, ZERO);

	if (c->is_moving) {
		if (dot_product(N, VEC_N) == 0 || dot_product(N, VEC_E) == 0) {
			c->facing_direction = N;
		} else {
			c->facing_direction = normalize(projection(N, VEC_E));
		}
	}



	c->position = add(c->position, v);

	set_character_animation(c);
}

void character_movement_interface(struct Character *c, double magnitude)
{
	struct Vector v = generate_direction();
	v = scale(v, magnitude);

	move_character(c, v, magnitude);
}

struct Vector get_character_center(struct Character *c)
{
	struct Vector v = ZERO;
	v.x = c->position.x + (double) c->w / 2;
	v.y = c->position.y + (double) c->h / 2;

	return v;
}

void set_character_animation(struct Character *c)
{
	//struct Vector m = normalize(c.moving_direction);
	struct Vector f = normalize(c->facing_direction);

	if (c->is_moving) {
		if (equal(f, VEC_N))
			c->animation = c->walking_north;
		else if (equal(f, VEC_S))
			c->animation = c->walking_south;
		else if (equal(f, VEC_E))
			c->animation = c->walking_east;
		else if (equal(f, VEC_W))
			c->animation = c->walking_west;
	} else {
		if (equal(f, VEC_N))
			c->animation = c->idle_north;
		else if (equal(f, VEC_S))
			c->animation = c->idle_south;
		else if (equal(f, VEC_E))
			c->animation = c->idle_east;
		else if (equal(f, VEC_W))
			c->animation = c->idle_west;
	}
}
