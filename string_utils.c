#include "simple_shell.h"

/**
 * strNcmp - compares two strings
 * @str1: string one
 * @str2: string two
 * @n: number of characters
 *
 * Return: 0 if the strings are equal
 */

int strNcmp(char *str1, char *str2, size_t n)
{
	size_t a;

	for (a = 0; a < n && str1[a] != '\0' && str2[a] != '\0'; a++)
	{
	if (str1[a] != str2[a])
	return (str1[a] - str2[a]);
	}
	return (0);
}
