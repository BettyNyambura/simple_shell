#include "simple_shell.h"

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
		return (strDup(command));
	path = _getenv("PATH");
	if (path)
	{
	path_dup = strDup(path);
	if (!path_dup)
		return (NULL);

	token = strtok(path_dup, ":");
	while (token != NULL)
	{
		dir_len = _strlen(token);
		file_link = malloc(cmd_len + dir_len + 2);
		if (file_link == NULL)
		{
			free(path_dup);
			return (NULL);
		}
		strCpy(file_link, token);
		strCat(file_link, "/");
		strCat(file_link, command);
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
	return (file_path);
}
