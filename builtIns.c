#include "simple_shell.h"

/**
* handle_builtin - handles built in functions
* @command: tokenized commands
* @input: input read from stdin
*
* Return: 1 success,otherwise 0
*/
int handle_builtin(char **command, char *input)
{
	struct builtin builtin = {"env", "exit"};

	if (_strncmp(*command, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strncmp(*command, builtin.exit) == 0)
	{
		exit_cmd(command, input);
		return (1);
	}
	return (0);
}
