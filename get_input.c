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
	char *resultbuf;
	ssize_t characters;

	characters = getline(linebuffer, buffersize, stdin);
	if (characters == -1)
	{
		free(*linebuffer);
		return (NULL);
	}
	resultbuf = *linebuffer;
	if (resultbuf[characters - 1] == '\n')
	{
		resultbuf[characters - 1] = '\0';
	}
	return (resultbuf);
}
