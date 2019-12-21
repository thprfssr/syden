#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* This function takes a large surface `src`, and draws it onto `dst`. However,
 * it only draws as much of `src` as fits in `dst`. The coordinates passed to
 * this function simply correspond to the point within `src` at which you wish
 * the view to be centered. */
void camera_view(SDL_Surface *src, SDL_Surface *dst, int x_center, int y_center);
