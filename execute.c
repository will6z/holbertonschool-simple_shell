#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "execute.h"

void execute_command(char **args)
{
	pid_t pid;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		execv(args[0], args);
		exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
}
