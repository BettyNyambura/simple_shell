#include "simple_shell.h"
/**
 *checker- checks for built in function
 *@cmd: tokenized input
 *@buffer: line from getline function
 *Return: 1 excuted 0 !executed
 */
int checker(char **cmd, char *buffer)
{
	if (handle_builtin(cmd, buffer))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
