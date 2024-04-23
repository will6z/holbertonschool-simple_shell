#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>

#define PROMPT "#cisfun$ "
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
char *token;
int i = 0;

while (1)
{
int j;
for (j = 0; PROMPT[j] != '\0'; j++)
{
	_putchar(PROMPT[j]);
}
bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (bytes_read == 0)
{
_putchar('\n');
break;
}
else if (bytes_read == -1)
{
perror("read");
exit(EXIT_FAILURE);
}
buffer[bytes_read - 1] = '\0';

token = strtok(buffer, " ");
i = 0;
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;

if (execve(args[0], args, NULL) == -1)
{
perror(args[0]);
}
}
return (0);
}
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
