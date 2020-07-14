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
	c = malloc(sizeof(struct Character));
	char *js = read_file(filename);

	c->w = atoi(get_json_entry(js, "width"));
	c->h = atoi(get_json_entry(js, "height"));


	c->walking_north = load_animation(js, "walking-north");
	c->walking_south = load_animation(js, "walking-south");
	c->walking_east = load_animation(js, "walking-east");
	c->walking_west = load_animation(js, "walking-west");
	c->idle_north = load_animation(js, "idle-north");
	c->idle_south = load_animation(js, "idle-south");
	c->idle_east = load_animation(js, "idle-east");
	c->idle_west = load_animation(js, "idle-west");
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
			c->animation = LINK_WALKING_NORTH;
		else if (equal(f, VEC_S))
			c->animation = LINK_WALKING_SOUTH;
		else if (equal(f, VEC_E))
			c->animation = LINK_WALKING_EAST;
		else if (equal(f, VEC_W))
			c->animation = LINK_WALKING_WEST;
	} else {
		if (equal(f, VEC_N))
			c->animation = LINK_IDLE_NORTH;
		else if (equal(f, VEC_S))
			c->animation = LINK_IDLE_SOUTH;
		else if (equal(f, VEC_E))
			c->animation = LINK_IDLE_EAST;
		else if (equal(f, VEC_W))
			c->animation = LINK_IDLE_WEST;
	}
}
