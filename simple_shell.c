#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int run_command(char *command) {
	if (system(command) == -1) {
	printf("Error: Command '%s' not found\n", command);
	return -1;
    }
	return 0;
}

void replace_spaces_with_tabs(char *str) {
	int i;
	for (i = 0; str[i] != '\0'; ++i) {
		if (str[i] == ' ') {
			str[i] = '\t';
        }
    }
}

int main() {
	char command[MAX_COMMAND_LENGTH];
	printf("Who Let You In My Shell?!\n");
    
	while (1) {
	printf("(ง'̀-'́)ง ");
	if (fgets);
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
		printf("\nGet Out My Shell!!\n");
		break;
	}
	command[strcspn(command, "\n")] = '\0';

	if (strlen(command) == 0) {
		continue;
	}

	replace_spaces_with_tabs(command);

	if (run_command(command) == -1) {
	continue;
	}
	}

	return 0;
}

