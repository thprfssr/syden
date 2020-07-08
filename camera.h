#ifndef CAMERA_H
#define CAMERA_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "vector.h"


#define CAMERA_DEADZONE_X 20
#define CAMERA_DEADZONE_Y 20
#define CAMERA_JAILZONE_X 100
#define CAMERA_JAILZONE_Y 60
#define CAMERA_MIN_SPEED 0.25
#define CAMERA_MAX_SPEED 1.5

extern double CAMERA_POSITION_X;
extern double CAMERA_POSITION_Y;

void camera_view(SDL_Surface *src, SDL_Surface *dst, int x_center, int y_center);
bool camera_collision(SDL_Surface *src, int x_center, int y_center);
void move_camera(struct Vector v);
void camera_movement_interface(double magnitude);
void round_camera_position();
void equalize_camera_position_fractional_parts();
int get_camera_position_x();
int get_camera_position_y();
struct Vector get_camera_center();

#endif
