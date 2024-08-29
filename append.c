#include "simple_shell.h"

/**
* append_path - adds path to command
* @path: path of command
* @command: user entered command
*
* Return: buffer containing command with path on success
* NULL on failure
*/
char *append_path(char *path, char *command)
{
	char *buffer;
	size_t i = 0, j = 0;

	if (command == 0)
		command = "";

	if (path == 0)
		path = "";

	buffer = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!buffer)
		return (NULL);

	while (path[i])
	{
		buffer[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		buffer[i] = '/';
		i++;
	}
	while (command[j])
	{
		buffer[i + j] = command[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}
