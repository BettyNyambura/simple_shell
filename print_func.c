#include "simple_shell.h"

/**
* _putchar - writes c to stdout
* @c: The character to print
*
* Return: success 1 else -1
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_str - prints a string
* @str: string to be printed
*
* Return: number of characters printed
*/
int print_str(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}

	return (a);
}
