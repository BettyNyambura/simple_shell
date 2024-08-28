#include "simple_shell.h"

/**
 * _strlen - Gets string length
 * @str: String to get length
 *
 * Return: Length
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 *_strCmp - compares two strings
 *@str1: string one
 *@str2: string two
 *
 *Return: 0 on success
 */

int _strCmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 *strDup - Dublicates string
 *@str: string to be duplicated
 *
 * Return: Duplicate
 *
 */

char *strDup(char *str)
{
	char *dup;
	int len = _strlen(str);
	int i;

	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';

	return (dup);
}

/**
 *strCpy - Copies string
 * @src: initial string
 * @dest: destination of string
 *
 * Return: Destination
 */

char *strCpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';

	return (dest);
}

/**
* strCat -Concatenates string
* @src: string to be appended
* @dest: destination string
*
* Return: str2
*/

char *strCat(char *dest, char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';

	return (dest);
}
