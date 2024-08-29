#include "simple_shell.h"
/**
* main - reads, execute then print output loop
* @ac: argument count
* @av: argument vector
* @envp: environment vector
*
* Return: 0
*/

int main(int ac, char **av, char *envp[])
{
	char *input = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t inputsize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);

	while (1)
	{
		free_buffers(command);
		free_buffers(paths);
		free(pathcommand);
		prompt_user();
		inputsize = getline(&input, &bufsize, stdin);
		if (inputsize < 0)
			break;
		info.ln_count++;
		if (input[inputsize - 1] == '\n')
			input[inputsize - 1] = '\0';
		command = tokenizer(input);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (checker(command, input))
			continue;
		path = find_path();
		paths = tokenizer(path);
		pathcommand = test_path(paths, command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			execution(pathcommand, command);
	}
	if (inputsize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(input);
	return (0);
}
