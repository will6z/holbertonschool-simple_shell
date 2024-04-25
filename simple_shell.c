#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void read_command(char *buffer) 
{
	printf("shell> ");
	fgets(buffer, BUFFER_SIZE, stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
}

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

	while (1)
	{
		read_command(command);
		execute_command(command);
	}
	return (0);
}
