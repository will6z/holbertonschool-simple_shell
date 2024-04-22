#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"
#include "tokenize.h"
#include "execute.h"
#include <constants.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10

int main(void)
{
	char *path = get_path();
	char *dirs[MAX_ARGS + 1];
	tokenize_path(path, dirs);

	char cmd[MAX_CMD_LEN];
	while (1)
	{
		printf(":) ");
		if(!fgets(cmd, MAX_CMD_LEN, stdin))
		{
			break;
		}
		cmd[strcspn(cmd, "\n")] = '\0';

		char *args[MAX_ARGS + 1];
		tokenize_command(cmd, args);

		execute_command(args);
	}
	return (0);
}
