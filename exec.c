#include "shell.h"

/**
 * execute - Execute a command
 * @command: The command to execute (no arguments)
 *
 * Return: 1 to continue the loop, 0 to exit
 */

int execute(char *command)
{
	pid_t pid;
	int status;
	char *args[] = {command, NULL};

	pid = fork();
	if (pid == 0)
	{
	if (execve(command, args, environ) == -1)
	{
	perror("Error");
	}
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
	perror("Fork failed");
	}
	else
	{
	waitpid(pid, &status, 0);
	}

	return (1);
}
