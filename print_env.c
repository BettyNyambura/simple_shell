#include "simple_shell.h"

/**
* print_env - prints the environment string to stdout
*
* Return: 0
*/
void print_env(void)
{
	int a = 0;
	char **env = environ;

	while (env[a])
	{
		write(STDOUT_FILENO, (const void *)env[a], _strlen(env[a]));
		write(STDOUT_FILENO, "\n", 1);
		a++;
	}
}
