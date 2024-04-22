#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10
{
char *getpath();
void tokenize_command(char *cmd, char **args);
void execute_command(char **args, char **dirs);
void tokenize_path(char *path);

int main(void)
{
	char *path = get_path();
	char *dirs[MAX_ARGS + 1];

	tokenize_path(path, dirs);

	char cmd[MAX_CMD_LEN];

	while (1)
	{
		printf(":) ");
		if (!fgets(cmd, MAX_CMD_LEN, stdin))
		{
			break;
		}
		cmd[strcspn(cmd, "\n")] = '\0';

		char *args[MAX_ARGS + 1];

		tokenize_command(cmd, args);

		execute_command(args, dirs);
	}
	return (0);

}
	char *get_path = getenv("PATH");

	if (!path)
	{
	fprintf(stderr, "Error: PATH environment variable not set\n");
	exit(EXIT_FAILURE);
	}
	return (path);
}
	void tokenize_command(char *cmd, char **args)
{
	char *token = strtok(cmd, " ");
	int i = 0;

	while (token && i < MAX_ARGS)
	{
	args[i++] = token;
	token = strtok(NULL, " ");
	}
}
	void execute_command(char **args)
{
	if (access(args[0], X_OK) == -1)
	{
	printf("Error: Command '%s' not found\n", args[0]);
	return;
	}
	pid_t pid = fork();
		if (pid == -1)
		{
	perror("fork");
		}
	else if (pid == 0)
	{
	execv(args[0], args);
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
}
