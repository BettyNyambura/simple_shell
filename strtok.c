#include "simple_shell.h"

/**
* tokenizer - creates tokens from given input
* @input: to be tokenized
*
* Return: array of strings
*/
char **tokenizer(char *input)
{
	char *buffer = NULL, *buf_p = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;

	buffer = strDup(input);
	if (!buffer)
		return (NULL);
	buf_p = buffer;

	while (*buf_p)
	{
		if (_strchr(delim, *buf_p) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (_strchr(delim, *buf_p) == NULL && flag == 1)
			flag = 0;
		buf_p++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buffer, delim);
	while (token)
	{
		tokens[index] = strDup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = '\0';
	free(buffer);
	return (tokens);
}
