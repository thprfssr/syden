#include <math.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "camera.h"
#include "config.h"
#include "controls.h"
#include "general.h"
#include "vector.h"

struct Camera CAMERA = {{0, 0}, {0, 0}};

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
/*
void move_camera(struct Vector v)
{
	CAMERA_POSITION_X += v.x;
	CAMERA_POSITION_Y += v.y;
}
*/

/* The displacement vector in the argument would be the location of the player
 * relative to the center of the camera. The purpose of this function is to
 * center the camera on the player (or to wherever the displacement vector
 * points). */
struct Camera move_camera(struct Camera camera, struct Vector displacement)
{
	double v_M = CAMERA_MAX_SPEED;
	double v_m = CAMERA_MIN_SPEED;
	double x_D = CAMERA_DEADZONE_X;
	double x_J = CAMERA_JAILZONE_X;
	double y_D = CAMERA_DEADZONE_Y;
	double y_J = CAMERA_JAILZONE_Y;

	/* We wanna move either in the cardinal directions or in the diagonal
	 * directions in order to avoid jitteriness in the motion of the
	 * camera. */
	struct Vector direction = {signum(displacement.x), signum(displacement.y)};
	double speed = 0;

	/* If a component of the displacement vector is within the deadzone,
	 * then we don't move the camera in that direction. */
	if (abs(displacement.x) < x_D)
		direction.x = 0;
	if (abs(displacement.y) < y_D)
		direction.y = 0;

	/* If either of the components of the camera are outside the jailzone,
	 * we wanna move at maximum speed. */
	if (abs(displacement.x) > x_J || abs(displacement.y) > y_J)
		speed = CAMERA_MAX_SPEED;

	/* Otherwise, we move at a linear interpolation between the maximum
	 * speed and the minimum speed. */
	double v_x = 0;
	double v_y = 0;
	if (x_D < abs(displacement.x) < x_J) {
		double a = (v_M - v_m) / (x_J - x_D);
		v_x = a * abs(displacement.x) + v_m;
	}
	if (y_D < abs(displacement.y) < y_J) {
		double a = (v_M - v_m) / (y_J - y_D);
		v_y = a * abs(displacement.y) + v_m;
	}

	/* Our total speed will be the maximum of these two. */
	speed = (v_x <= v_y) ? v_y : v_x;

	struct Vector velocity = ZERO;
	velocity = normalize(direction);
	velocity = scale(velocity, speed);

	/* If the camera movement direction is different from previously, then
	 * we round the coordinates in order to reduce jitteriness. */
	if (!equal(camera.direction, direction)) {
		//round_camera_position();
		camera.position = round_vector(camera.position);
	}
	camera.direction = direction;
	camera.position = add(camera.position, velocity);

	return camera;
}

/* This function acts as a link between the abstract game controller and the
 * camera position. If a button is pressed, then the camera is moved
 * accordingly. */
/*
void camera_movement_interface(double magnitude)
{
	if (controller_status_changed())
		round_camera_position();

	struct Vector v = generate_vector();
	v = scale(v, magnitude);

	move_camera(v);
}
*/

/* This function rounds the camera's coordinates. */
/*
void round_camera_position()
{
	CAMERA_POSITION_X = round(CAMERA_POSITION_X);
	CAMERA_POSITION_Y = round(CAMERA_POSITION_Y);
}
*/

/* This function forces the fractional parts of the camera coordinates to be
 * equal. We do this in the hopes of eliminating the jittery motion that occurs
 * when moving diagonally. */
/*
void equalize_camera_position_fractional_parts()
{
	/* First take the modulus base 1. */
/*
	double frac_x = fmod(CAMERA_POSITION_X, 1);
	double frac_y = fmod(CAMERA_POSITION_Y, 1);

	/* Now, let the new fractional part be the average of these. */
/*
	double frac = (frac_x + frac_y) / 2;

	/* Modify the camera coordinates. */
/*
	CAMERA_POSITION_X = floor(CAMERA_POSITION_X) + frac;
	CAMERA_POSITION_Y = floor(CAMERA_POSITION_Y) + frac;
}
*/

/* This function is an attempt to reduce the jitteriness of the motion. */
/*
int get_camera_position_x()
{
	int x;
	if (is_button_pressed(BUTTON_RIGHT))
		x = (int) floor(CAMERA_POSITION_X);
	else if (is_button_pressed(BUTTON_LEFT))
		x = (int) ceil(CAMERA_POSITION_X);
	else
		x = (int) round(CAMERA_POSITION_X);
	//return x;
	return (int) round(CAMERA_POSITION_X);
}
*/

/* This function is an attempt to reduce the jitteriness of the motion. */
/*
int get_camera_position_y()
{
	int y;
	if (is_button_pressed(BUTTON_DOWN))
		y = (int) floor(CAMERA_POSITION_Y);
	else if (is_button_pressed(BUTTON_UP))
		y = (int) ceil(CAMERA_POSITION_Y);
	else
		y = (int) round(CAMERA_POSITION_Y);
	//return y;
	return (int) round(CAMERA_POSITION_Y);
}
*/

struct Vector get_camera_center(struct Camera camera)
{
	/* The coordinates stored for the camera already point to the center
	 * of the camera. */
	struct Vector v = camera.position;
	return v;
}
