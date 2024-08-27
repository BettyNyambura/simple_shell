#include "simple_shell.h"
/**
 * signalHandler - Handles signals
 * @signalnum: signal number
 */
void signalHandler(int signalnum __attribute__((unused)))
{
	write(1, "\n#simple_shell$ ", _strlen("\n#simple_shell$ "));
}
