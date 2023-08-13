#include "shell.h"

/**
 * _puts - function to print srings to stdout
 * @str: string that is printed
 * Return: returns the no characters to be printed
 */

int _puts(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (write(STDOUT_FILENO, &str[i], 1) < 0)
			return (EOF);
	return (i);
}
