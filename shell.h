#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100

void display_shell_prompt(void);
char *get_user_input(void);
int has_whitespace(char *command);
int execute_shell_command(char *command);
int main(void);

#endif
