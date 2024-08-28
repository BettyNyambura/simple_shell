#include "simple_shell.h"

/**
 * execute_command - executes command
 * @path: path
 * @args: arguments
 * Return: void
*/

void execute_command(char *path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}

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

	if (stat(path, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
	{
		execute_command(path, args);
	}
	else
	{
		perror("./shell");
	}

	if (isatty(fileno(stdin)))
		free(path);
}
