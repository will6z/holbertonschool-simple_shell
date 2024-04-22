#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"
#include <constants.h>

char *get_path() 
{
	char *path = getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		exit (EXIT_FAILURE);
	}
	return (path);
}

void tokenize_path(char *path, char **dirs) 
{
	for (int i = 0; i < MAX_ARGS + 1; i++)
	{
		dirs[i] = strtok(i == 0 ? path : NULL, ":");
	}
}
