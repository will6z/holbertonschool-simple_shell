#include "shell.h"

/**
 *print_message - prints a message to the standard output
 *@message: the message to print
 *
 *Return: none
*/
void print_message(char *message)
{
	if (message != NULL)
	{
		while (*message)
		{
			_putchar(*message);
			message++;
		}
		_putchar('\n');
	}
}

/**
 *main - entry point of program
 *
 *Return: always 0
 *
*/
int main(void)
{
	char *message = "Hello, Betty!";

	print_message(message);

	return (0);
}
