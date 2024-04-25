#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void execute_command(char *command)
{
	char *args[BUFFER_SIZE];
	char *token = strtok(command, " ");
	int i = 0;
	while (token != NULL)
	{
	args[i++] = token;
	token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		extern char **environ;
		char **env = environ;
		while (env)
		{
			printf("%s\n", env++);
		}
		return;
	}

	pid_t pid = fork();
	if (pid < 0)
	{
	perror("fork");
	}
	else if (pid == 0)
	{
	if (execvp(args[0], args) == -1)
	{
	perror("execvp");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	wait(NULL);
	}
}
int main(void)
{
	char command[BUFFER_SIZE];

	fgets(command, BUFFER_SIZE, stdin);

	command[strcspn(command, "\n")] = '\0';

	execute_command(command);

	return (0);
}
