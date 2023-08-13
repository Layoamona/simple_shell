#include "shell.h"
/**
 * read_line - function that reads users input from input stream
 * Return: returns the line of user input.
 */

char *read_line(void)
{
	char *line = NULL;
	size_t buflen = 0;

	getline(&line, &buflen, stdin);
	return (line);
}
