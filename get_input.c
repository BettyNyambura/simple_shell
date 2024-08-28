#include "simple_shell.h"
/**
 * readInput - Read line from stdin
 * @linebuffer: Buffer to write to
 * @buffersize: Size of buffer
 *
 * Return: Written buffer
 */
char *readInput(char **linebuffer, size_t *buffersize)
{
	ssize_t characters;

	characters = getline(linebuffer, buffersize, stdin);
	if (characters == -1)
	{
		return (NULL);
	}
	if ((*linebuffer)[characters - 1] == '\n')
	{
		(*linebuffer)[characters - 1] = '\0';
	}
	return (*linebuffer);
}
