#include "simple_shell.h"

/**
 * shell_executor - shell exec
 * @buffer: string with commands
 *
 * Return: void
*/

void shell_executor(char *buffer)
{
	char *args[100];
	char *path;
	struct stat st;

	parse_arguments(buffer, args);

	if (args[0] == NULL)
		return;

	if (_strCmp(args[0], "exit") == 0)
	{
		free(buffer);
		exit(0);
	}

	path = pathFinder(args[0]);
	if (path == NULL)
	{
		perror("./shell");
		return;
	}

	if (stat(path, &st) == 0)
	{
		execute_command(path, args);
	}
	else
	{
		perror("./shell");
	}

	if (isatty(0))
		free(path);
}
/**
 * execute_command - shell exec
 * @path: commands
 * @args: arguments
 *
 * Return: void
*/


void execute_command(char *path, char **args)
{
	int status;

	if (fork() != 0)
	{
		wait(&status);
	}
	else
	{
		execve(path, args, environ);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
}
