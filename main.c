#include "shell.h"

int def_valid_command(const char *command);
/**
 * main - entry point of my shell program
 * Return: returns 0 on success
 */
int main(void)
{
	size_t bufferSize = 0;
	ssize_t bytesRead;

	char *line = NULL;
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
				free(line);
				return 0;
			}

			/* Check for other allowed commands */
			if (def_valid_command(tokens[0]))
			{
				/* Execute the command */
				_execme(tokens);
			} else
			{
				/* Display an error message for invalid command */
				def_fprintf(stderr, "Invalid command: %s\n", tokens[0]);
			}
			free(tokens);
		}

	}
	if (line != NULL)
		free(line);
	return 1;
}

