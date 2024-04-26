#include "shell.h"
/**
 *main - main function of the program
 *
 *
 *Return: 0 on success
 *
*/
int main(void)
{
char *token, *command = NULL;
int status = 0;
int whitespace_check = 1;

while (1)
{
while (whitespace_check == 1)
{
command = get_user_input();
whitespace_check = whitespace(command);

if (whitespace_check == 1 || command == NULL)
{
free(command);
}
}
token = strtok(command, '\n');

if (token != NULL && command != NULL)
{
if (strcmp(token, "exit") == 0)
{
free(command);
exit(EXIT_SUCCESS);
}
else
{
status = execute_shell_command(command);
}
token = strtok(NULL, "\n");
}
free(command);
whitespace_check = 1;
}
return (status);
}
/**
 *get_user_input - reads a command
 *
 *
 *Return: a pointer to the buffer where command is stored
 *
*/
char *get_user_input()
{
char *command = NULL;
size_t length = 0, buffer_size = 0;
ssize_t bytes_read;

if (isatty(STDIN_FILENO))
{
display_shell_prompt();
}
bytes_read = getline(&command, &buffer_size, stdin);
if(bytes_read == -1)
{
if (isatty(STDIN_FILENO))
{
perror("getline");
return (NULL);
}
free(command);
exit(EXIT_SUCCESS);
}
length = strlen(command);

if (length > 0 && command[length - 1] == '\n')
{
command[length - 1] = '\0';
}
return (command);
}
/**
 *whitespace - checks for whitespaces
 *@command: the command to use for checking
 *
 *Return: 1 if whitespace is present, 0 otherwise
*/
int whitespace(char *command)
{
int index;

for (index = 0; command[index] != '\0'; index++)
{
if (command[index] != ' ')
{
if (command[index] == '\0')
{
return (1);
}
else
{
return (0);
}
}
}
return (1);
}
