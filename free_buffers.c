#include "simple_shell.h"

/**
* free_buffers - frees buffers
* @buffer: buffer to be freed
*
* Return: nothing
*/
void free_buffers(char **buffer)
{
	int a = 0;

	if (!buffer || buffer == NULL)
		return;
	while (buffer[a])
	{
		free(buffer[a]);
		a++;
	}
	free(buffer);
}
