#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"

/* Read the contents of a file into  a string. */
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


/* Count the number of lines in a string. */
int count_lines(char *string)
{
	char delim = '\n';
	char count = 0;
	for (int i = 0; i < strlen(string); i++)
		if (string[i] == delim)
			count++;
	/* The number of lines is just the number of newlines, plus one. */
	return 1 + count;
}
