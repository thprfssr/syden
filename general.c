#include <stdio.h>
#include <stdlib.h>

#include "general.h"

char* read_file(char *filename)
{
	char *buffer = NULL;
	long length = 0;
	FILE *f = fopen(filename, "rb");

	if (f) {
		fseek(f, 0, SEEK_END);
		length = ftell(f);
		fseek(f, 0, SEEK_SET);
		buffer = malloc(length);
		if (buffer) {
			fread(buffer, 1, length, f);
		}
		fclose(f);
	}

	if (buffer)
	{
		printf(buffer);
	}
}
