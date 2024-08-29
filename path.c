#include "simple_shell.h"

/**
* find_path - finds the path
* Return: !path, NULL else path
*/
char *find_path(void)
{
	int a = 0;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strCmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && a < 5)
			{
				path++;
				a++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
