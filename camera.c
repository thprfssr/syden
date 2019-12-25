#include <math.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "camera.h"
#include "controls.h"
#include "general.h"

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

void move_camera(int direction, double magnitude)
{
	switch(direction) {
		case (NORTH):
			CAMERA_POSITION_Y -= magnitude;
			break;
		case (SOUTH):
			CAMERA_POSITION_Y += magnitude;
			break;
		case (EAST):
			CAMERA_POSITION_X += magnitude;
			break;
		case (WEST):
			CAMERA_POSITION_X -= magnitude;
			break;
		case (NORTH | EAST):
			CAMERA_POSITION_X += magnitude / sqrt(2);
			CAMERA_POSITION_Y -= magnitude / sqrt(2);
			break;
		case (NORTH | WEST):
			CAMERA_POSITION_X -= magnitude / sqrt(2);
			CAMERA_POSITION_Y -= magnitude / sqrt(2);
			break;
		case (SOUTH | EAST):
			CAMERA_POSITION_X += magnitude / sqrt(2);
			CAMERA_POSITION_Y += magnitude / sqrt(2);
			break;
		case (SOUTH | WEST):
			CAMERA_POSITION_X -= magnitude / sqrt(2);
			CAMERA_POSITION_Y += magnitude / sqrt(2);
			break;
		case (NORTH | SOUTH | EAST):
			CAMERA_POSITION_X += magnitude / sqrt(2);
			break;
		case (NORTH | SOUTH | WEST):
			CAMERA_POSITION_X -= magnitude / sqrt(2);
			break;
		case (EAST | WEST | NORTH):
			CAMERA_POSITION_Y -= magnitude / sqrt(2);
			break;
		case (EAST | WEST | SOUTH):
			CAMERA_POSITION_Y += magnitude / sqrt(2);
			break;
		default:
			CAMERA_POSITION_X = round(CAMERA_POSITION_X);
			CAMERA_POSITION_Y = round(CAMERA_POSITION_Y);
			break;
	}
}

/* This function acts as a link between the abstract game controller and the
 * camera position. If a button is pressed, then the camera is moved
 * accordingly. */
void camera_movement_interface(double magnitude)
{
	if (is_button_pressed(BUTTON_UP))
		move_camera(NORTH, magnitude);
	if (is_button_pressed(BUTTON_DOWN))
		move_camera(SOUTH, magnitude);
	if (is_button_pressed(BUTTON_LEFT))
		move_camera(WEST, magnitude);
	if (is_button_pressed(BUTTON_RIGHT))
		move_camera(EAST, magnitude);
}
