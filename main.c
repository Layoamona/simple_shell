#include "shell.h"

/**
 * main - entry point of my shell program
 * Return: returns 0 on success
 */
int main(void)
{
	size_t bufferSize = 0;
	ssize_t bytesRead;

	char *line;
	char **tokens;

	while ((bytesRead = getline(&line, &bufferSize, stdin)) != -1)
	{
		/*Ignore the line if it starts with a comment character*/
		if (line[0] == '#')
			continue;

		tokens = split_line(line);

		if (tokens[0] != NULL)
		{
			/* Check for the exit built-in command */
			if (my_strcmp(tokens[0], "exit") == 0)
			{
				if (tokens != NULL)
					free(tokens);
				break;
			}

			/* Check for the env built-in command */
			if (my_strcmp(tokens[0], "env") == 0)
			{
				print_env();
				continue;
			}
			_execme(tokens);
			free(tokens);
		}

	}
	if (line != NULL)
		free(line);
	return (0);
}
