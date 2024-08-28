#include "simple_shell.h"

/**
 * parse_arguments - parses arguments
 * @buffer: String containing commands
 * @args: arguments
 * Return: void
 */

void parse_arguments(char *buffer, char **args)
{
	int b = 0;

	args[b] = strtok(buffer, " \n");

	while (args[b] != NULL && b <= 99)
	{
		b++;
		args[b] = strtok(NULL, " \n");
	}
	args[b] = NULL;
}
