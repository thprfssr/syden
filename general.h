#ifndef GENERAL_H
#define GENERAL_H

#include <stdlib.h>

char* read_file(char *filename);
int count_lines(char *string);
int count_first_line_entries(char *string);
char** read_lines(char *string);
char** read_csv_entries(char *string);

#endif
