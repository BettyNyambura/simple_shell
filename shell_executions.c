#include "simple_shell.h"
/**
 *strNcmp - compares two strings
 *@str1: string one
 *@str2: string two
 *@n: number of characters
 *
 *Return: 0 on success
 */
int strNcmp(char *str1, char *str2, size_t n)
{
	size_t a;

	for (a = 0; a < n && str1[a] != '\0' && str2[a] != '\0'; a++)
	{
		if (str1[a] != str2[a])
		return (str1[a] - str2[a]);
	}
	return (0);
}

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

	if (args[b] == NULL)
		return;
	while (args[b] != NULL && b <= 99)
	{
		b++;
		args[b] = strtok(NULL, " \n");
	}
	args[b] = NULL;
}

/**
 * execute_command - executes command
 * @path: path
 * @args: arguments
 * Return: void
*/

void execute_command(char *path, char **args)
{
	int x;

	if (fork() != 0)
	{
		wait(NULL);
	}
	else
	{
		x = execve(path, args, environ);
		if (x == -1)
		{
			perror("./shell");
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

	struct stat st;

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
 * _getenv - Get environment variables
 * @name: Name of variable
 *
 * Return: Value of the variable
 */

char *_getenv(char *name)
{
	char *retval = NULL;
	char **env;
	int len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strNcmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			retval = *env + len + 1;
			break;
		}
	}
	return (retval);
}
/**
 * pathFinder - Gets the path
 * @command: Command to get its full path
 *
 * Return: 0
 */
char *pathFinder(char *command)
{
	char *path, *path_dup, *token, *file_link, *file_path = NULL;
	int cmd_len = _strlen(command), dir_len;
	struct stat buffer;

	if (stat(command, &buffer) == 0)
		return (command);
	path = _getenv("PATH");
	if (path)
	{
		path_dup = strDup(path);
		token = strtok(path_dup, ":");
		while (token != NULL)
		{
			dir_len = _strlen(token);
			file_link = malloc(cmd_len + dir_len + 2);
			if (file_link == NULL)
				return (NULL);
			strCpy(file_link, token);
			strCat(file_link, "/");
			strCat(file_link, command);
			strCat(file_link, "\0");
			if (stat(file_link, &buffer) == 0)
			{
				file_path = file_link;
				break;
			}
			else
			{
				free(file_link);
				token = strtok(NULL, ":");
			}
		}
		free(path_dup);
	}
	if (file_path)
	{
		return (file_path);
	}
	return (NULL);
}
