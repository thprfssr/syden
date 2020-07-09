#ifndef GENERAL_H
#define GENERAL_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define NORTH	(1 << 0)
#define SOUTH	(1 << 1)
#define EAST	(1 << 2)
#define WEST	(1 << 3)

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	#define RMASK 0xff000000
	#define GMASK 0x00ff0000
	#define BMASK 0x0000ff00
	#define AMASK 0x000000ff
#else
	#define RMASK 0x000000ff
	#define GMASK 0x0000ff00
	#define BMASK 0x00ff0000
	#define AMASK 0xff000000
#endif


extern int TIME;

char* read_file(char *filename);
int count_lines(char *string);
int count_first_line_entries(char *string);
char** read_lines(char *string);
char** read_csv_entries(char *string);
SDL_Surface* load_resource(char *filename);

#endif
