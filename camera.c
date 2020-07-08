#include <math.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "camera.h"
#include "controls.h"
#include "general.h"
#include "vector.h"

double CAMERA_POSITION_X = 0;
double CAMERA_POSITION_Y = 0;


/* This function takes a large surface `src`, and draws it onto `dst`. However,
 * it only draws as much of `src` as fits in `dst`. The coordinates passed to
 * this function simply correspond to the point within `src` at which you wish
 * the view to be centered. */
void camera_view(SDL_Surface *src, SDL_Surface *dst, int x_center, int y_center)
{
	int w_src = src->w;
	int h_src = src->h;
	int w_dst = dst->w;
	int h_dst = dst->h;

	/* Create the source rectangle. */
	SDL_Rect rect;
	rect.x = x_center - w_dst / 2;
	rect.y = y_center - h_dst / 2;
	rect.w = w_dst;
	rect.h = h_dst;

	/* Copy the correct portion of `src` onto `dst`. */
	SDL_BlitSurface(src, &rect, dst, NULL);
}

/* This function checks whether the camera view goes beyond the boundaries of
 * a given surface. */
bool camera_collision(SDL_Surface *src, int x_center, int y_center)
{
	int w = src->w;
	int h = src->h;
	int x = x_center;
	int y = y_center;

	return (x - w < 0) || (y - h < 0) || (w < x + w) || (h < y + h);
}

void move_camera(struct Vector v)
{
	CAMERA_POSITION_X += v.x;
	CAMERA_POSITION_Y += v.y;
}

/* This function acts as a link between the abstract game controller and the
 * camera position. If a button is pressed, then the camera is moved
 * accordingly. */
void camera_movement_interface(double magnitude)
{
	if (controller_status_changed())
		round_camera_position();

	struct Vector v = {0, 0};
	if (is_button_pressed(BUTTON_UP))
		v = add(v, VEC_N);
	if (is_button_pressed(BUTTON_DOWN))
		v = add(v, VEC_S);
	if (is_button_pressed(BUTTON_LEFT))
		v = add(v, VEC_W);
	if (is_button_pressed(BUTTON_RIGHT))
		v = add(v, VEC_E);

	v = scale(normalize(v), magnitude);
	if (multiple_directional_buttons_pressed())
		v = scale(v, 1 / sqrt(2));

	move_camera(v);
}

/* This function rounds the camera's coordinates. */
void round_camera_position()
{
	CAMERA_POSITION_X = round(CAMERA_POSITION_X);
	CAMERA_POSITION_Y = round(CAMERA_POSITION_Y);
}

/* This function forces the fractional parts of the camera coordinates to be
 * equal. We do this in the hopes of eliminating the jittery motion that occurs
 * when moving diagonally. */
void equalize_camera_position_fractional_parts()
{
	/* First take the modulus base 1. */
	double frac_x = fmod(CAMERA_POSITION_X, 1);
	double frac_y = fmod(CAMERA_POSITION_Y, 1);

	/* Now, let the new fractional part be the average of these. */
	double frac = (frac_x + frac_y) / 2;

	/* Modify the camera coordinates. */
	CAMERA_POSITION_X = floor(CAMERA_POSITION_X) + frac;
	CAMERA_POSITION_Y = floor(CAMERA_POSITION_Y) + frac;
}

/* This function is an attempt to reduce the jitteriness of the motion. */
int get_camera_position_x()
{
	int x;
	if (is_button_pressed(BUTTON_RIGHT))
		x = (int) floor(CAMERA_POSITION_X);
	else if (is_button_pressed(BUTTON_LEFT))
		x = (int) ceil(CAMERA_POSITION_X);
	else
		x = (int) round(CAMERA_POSITION_X);
	return x;
}

/* This function is an attempt to reduce the jitteriness of the motion. */
int get_camera_position_y()
{
	int y;
	if (is_button_pressed(BUTTON_DOWN))
		y = (int) floor(CAMERA_POSITION_Y);
	else if (is_button_pressed(BUTTON_UP))
		y = (int) ceil(CAMERA_POSITION_Y);
	else
		y = (int) round(CAMERA_POSITION_Y);
	return y;
}
