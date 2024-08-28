#include "simple_shell.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable or NULL if not found
 */

char *_getenv(char *name)
{
	char **env = environ;
	int len = _strlen(name);

	while (*env != NULL)
	{
	if (strNcmp(*env, name, len) == 0 && (*env)[len] == '=')
	{
	return (*env + len + 1);
	}
	env++;
	}
	return (NULL);
}
