#include "simple_shell.h"
/**
 * _strlen - Gets string length
 * @str: String to get length
 *
 * Return: Length
 */
int _strlen(char *str)
{
	if (*str == '\0')
	{
		return (0);
	}
	return (1 + _strlen(str + 1));
}
/**
 * _strCmp - Compares two strings
 * @str1: First string
 * @str2: second string
 *
 * Return: 0 on success -1 otherwise
 */
int _strCmp(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
	if (*str1 == '\0' || *str2 == '\0')
	{
		break;
	}
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);
	}
	return (-1);
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
	int a, len;
	char *dup;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	a = 0;

	while (a < len)
	{
		dup[a] = str[a];
		a++;
	}
	dup[a] = '\0';
	return (dup);
}
/**
 * strCat -Concatenates string
 * @str1: string to be appended
 * @str2: destination string
 *
 * Return: str2
 */
char *strCat(char *str2, char *str1)
{
	int a, b;

	a = 0;

	while (str2[a] != '\0')
	{
		a++;
	}
	b = 0;

	while (str1[b] != '\0')
	{
		str2[a] = str1[b];
		a++;
		b++;
	}
	str2[a] = '\0';
	return (str2);
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
	int a, length;

	length = _strlen(src);
	for (a = 0; a < length && *src != '\0'; a++)
	{
	dest[a] = src[a];
	}
	dest[a] = '\0';
	return (dest);
}
