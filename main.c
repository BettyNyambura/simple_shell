#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char *command;
	int status = 1;

	while (status)
	{
	printf("($) ");
	command = get_input(&buffer, &bufsize);

	if (command == NULL)
	{
	printf("\n");
	free(buffer);
	exit(EXIT_SUCCESS);
	}

	if (_strlen(command) > 0)
	{
	status = execute(command);
	}
	}

	free(buffer);
	return (0);
}
