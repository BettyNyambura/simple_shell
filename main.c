#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *command;
	int status = 1;

	while (status)
	{
	printf("($) "); // Display the shell prompt
	command = get_input(&buffer, &bufsize); // Get input from user

	if (command == NULL) // If Ctrl+D is pressed or getline fails
        {
            printf("\n");
            free(buffer);
            exit(EXIT_SUCCESS);
        }

        if (_strlen(command) > 0) // If command is not empty
        {
            status = execute(command); // Execute the command
        }
    }

    free(buffer);
    return (0);
}
