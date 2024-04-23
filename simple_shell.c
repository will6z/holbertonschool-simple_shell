#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>

#define BUFFER_SIZE 1024
/**
 *main - main function
 *
 *
 *
 *Return: always 0
 */
int main(void)
{
char buffer[BUFFER_SIZE];
char *args[BUFFER_SIZE / 2 + 1];
ssize_t bytes_read;
pid_t pid;

while (1)
{
printf("#cisfun$ ");

bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (bytes_read == 0)
{
printf("\n");
break;
}
else if (bytes_read == -1)
{
perror("read");
exit(EXIT_FAILURE);
}
buffer[bytes_read - 1] = '\0';

if (strcmp(buffer, "exit") == 0)
break;

args[0] = buffer;
args[1] = NULL;

pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}
return (0);
}
