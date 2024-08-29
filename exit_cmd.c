#include "simple_shell.h"

/**
* exit_cmd - handles the exit command
* @command: tokenized command
* @input: input read from stdin
*
* Return: no return
*/
void exit_cmd(char **command, char *input)
{
	free(input);
	free_buffers(command);
	exit(0);
}
