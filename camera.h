#ifndef CAMERA_H
#define CAMERA_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

double CAMERA_POSITION_X;
double CAMERA_POSITION_Y;

void camera_view(SDL_Surface *src, SDL_Surface *dst, int x_center, int y_center);
bool camera_collision(SDL_Surface *src, int x_center, int y_center);
void move_camera(int direction, double magnitude);
void camera_movement_interface(double magnitude);
void round_camera_position();
void equalize_camera_position_fractional_parts();

#endif
