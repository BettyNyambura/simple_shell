#include "simple_shell.h"
/**
 * signalHandler - Handles signal
 * *@sn: the signal number
 *Return: nothing
 */

void handle_signal(int sn)
{
	(void)sn;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
