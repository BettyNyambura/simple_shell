#include "simple_shell.h"
/**
 * main - Prompter and command excecutor
 * @ac: Counts Arguments
 * @av: Vector Arguments
 *
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t buffersize = 0;
	ssize_t nread;
	int interactive = isatty(STDIN_FILENO);

	signal(SIGINT, signalHandler);

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, "#simple_shell$ ", 15);

		nread = getline(&buffer, &buffersize, stdin);
		if (nread == -1)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (buffer[nread - 1] == '\n')
			buffer[nread - 1] = '\0';

		shell_executor(buffer);
	}

	free(buffer);
	return (0);
}
