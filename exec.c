#include "simple_shell.h"

/**
 * execution - executes input commands from users
 *@cmd_p: command path
 *@args:vector array of pointers to commands
 * Return: 0
 */
void execution(char *cmd_p, char **args)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cmd_p);
	if (child_pid == 0)
	{
		execve(cmd_p, args, env);
		perror(cmd_p);
		free(cmd_p);
		free_buffers(args);
		exit(98);
	}
	else
		wait(&status);
}
