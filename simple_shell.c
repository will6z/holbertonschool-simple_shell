#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

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
char *args[2];
ssize_t bytes_read;

while (1)
{
write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);

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

args[0] = buffer;
args[1] = NULL;

if (execve(args[0], args, NULL) == -1)
{
perror(buffer);
}
}
return (0);
}
