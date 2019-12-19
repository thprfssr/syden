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
		return buffer;
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

/* Count the number of entries in the first line of a CSV-formatted string. */
int count_first_line_entries(char *string)
{
	char line_delim = '\n';
	char entry_delim = ',';
	int count = 0;
	for (int i = 0; i < strlen(string) && string[i] != line_delim; i++)
		if (string[i] == entry_delim)
			count++;
	/* The number of entries is just the number of commas, plus one. */
	return 1 + count;
}
