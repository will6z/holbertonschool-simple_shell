#include <stdio.h>
#include <string.h>
#include "tokenize.h"

void tokenize_command(char *cmd, char **args) 
{
	char *token = strtok(cmd, " ");
	int i = 0;
	while (token && i < MAX_ARGS) 
	{
	args[i++] = token;
	token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
