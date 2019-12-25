#ifndef CAMERA_H
#define CAMERA_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

double CAMERA_POSITION_X;
double CAMERA_POSITION_Y;

void camera_view(SDL_Surface *src, SDL_Surface *dst, int x_center, int y_center);
bool camera_collision(SDL_Surface *src, int x_center, int y_center);

#endif
