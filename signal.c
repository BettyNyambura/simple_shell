#include "simple_shell.h"

/**
 * signalHandler - Handles signals
 * @signalnum: signal number
 */

void signalHandler(int signalnum __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n#simple_shell$ ", 16);
}
