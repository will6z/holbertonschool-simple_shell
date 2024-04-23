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
<<<<<<< HEAD
char *token;
int i = 0;

while (1)
{
write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);
=======
pid_t pid;

while (1)
{
printf("#cisfun$ ");
>>>>>>> aby_branch

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

<<<<<<< HEAD
token = strtok(buffer, " ");
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;

perror(args[0]);
exit(EXIT_FAILURE);
}
=======
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
>>>>>>> aby_branch
{
return (0);
}
<<<<<<< HEAD

int _putchar(char c)
{
return (write(STDOUT_FILENO, &c, 1));
}
=======
>>>>>>> aby_branch
