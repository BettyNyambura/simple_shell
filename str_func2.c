#include "simple_shell.h"
/**
* _strCmp - compares two strings to a bytes
* @str1: compared to str2
* @str2: compared to str1
* @a: number of bytes
*
* Return: difference between str1 and str2
*/
int _strCmp(const char *str1, const char *str2, int a)
{
	int i;

	for (i = 0; str1[i] && str2[i] && i < a; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
/**
* _strchr - locates a character in a string
* @s: string to be checked
* @c: character to be located
*
* Return: returns pointer to first occurence of character
* or NULL if character not found
*/
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
