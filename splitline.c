#include "shell.h"

/**
 * split_line - function that splits a single line of user input into tokens
 * which will be used for execution of commands.
 * @line: a single line of user input from the input stream
 * Return: Returns tokens which will be used to execute a program
 */

char **split_line(char *line)
{
	int length = 0;
	int capacity = 16;
	char **tokens = malloc(capacity * sizeof(char *));

	char *delimiters = " \t\r\n";
	char *token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		if (length >= capacity)
		{
			capacity = (int)(capacity * 1.5);
			tokens = realloc(tokens, capacity * sizeof(char *));
		}

		token = strtok(NULL, delimiters);
	}

	tokens[length] = NULL;
	return (tokens);
}
