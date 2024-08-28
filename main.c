#include "simple_shell.h"
/**
 * main - Prompter and command excecutor
 * @ac: Counts Arguments
 * @av: Vector Arguments
 *
 * Return: 0
 */
int main(int ac, char **av __attribute__((unused)))
{
	char *buffer = NULL, *resultbuf;
	size_t buffersize = 120;
	int a;

	if (ac != 1)
	{
		perror("Usage");
		exit(EXIT_FAILURE);
	}
	buffer = malloc(buffersize);
	if (buffer == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, signalHandler);

	a = isatty(0);
	while (1)
	{
		if (a)
		{
			write(1, "#simple_shell$ ", _strlen("#simple_shell$ "));
			fflush(stdout);
		}
		resultbuf = readInput(&buffer, &buffersize);
		if (resultbuf == NULL)
		{
			write(1, "\n", 1);
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		shell_executor(resultbuf);
	}
	free(buffer);
	return (0);
}
