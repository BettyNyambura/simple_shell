#include "simple_shell.h"

/**
* prompt_user - prints $ when ready to take inputt if in interactive mode
*
* Return: no return
*/
void prompt_user(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
