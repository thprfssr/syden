#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
