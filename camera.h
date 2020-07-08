#ifndef CAMERA_H
#define CAMERA_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "vector.h"

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

#endif
