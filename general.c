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


/* Count the number of lines in a string. It is assumed that there are no empty
 * lines. */
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

/* Count the number of entries in the first line of a CSV-formatted string. It
 * is assumed that no entry contains any commas. */
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

/* Read the lines in a string into an array. It is assumed that whoever calls
 * this function already knows the number of lines that the returned array will
 * have. Moreover, there should not be any empty lines. */
char** read_lines(char *string)
{
	/* Copy the string, because strtok alters the string passed to it. */
	int n = strlen(string);
	char *copy = malloc(n * sizeof(char));
	strcpy(copy, string);

	/* Allocate memory for the array into which we will read the lines. */
	char **entries = malloc(n * sizeof(char));

	/* Read the lines. */
	int i = 0;
	char *line = strtok(copy, "\n");
	while (line != NULL) {
		entries[i] = line;

		i++;
		line = strtok(NULL, "\n");
	}

	return entries;
}
