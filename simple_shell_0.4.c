#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h> 

#define PROMPT "#cisfun$ "
#define BUFFER_SIZE 1024

/**
 * main - Main function
 *
 * Return: Always 0
 */
int main(void)
{
	char *token;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	while (1)
	{
		printf("%s", PROMPT);

		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		else if (bytes_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		buffer[bytes_read - 1] = '\0';

		token = strtok(buffer, " ");
		if (token != NULL && strcmp(token, "exit") == 0)
		{
			printf("Exiting shell...\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
		pid_t pid = fork();
		if (pid == -1)
		{
		perror("fork");
		exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(token, &token) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		}
		else
		{
		int status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			exit(EXIT_FAILURE);
                }
            }
        }
    }

    return (0);
}
