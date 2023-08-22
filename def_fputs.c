#include "shell.h"

/**
 * def_fputs - user defined function for fputs
 * @str: pointer to the string
 * @stream: pointer to the stream
 * Return: returns written variable
 */
int def_fputs(const char *str, FILE *stream)
{
	int written = 0;

	if (str == NULL || stream == NULL)
	{
		return (EOF);
	}

	while (*str != '\0')
	{
		int result = fputc(*str, stream);

		if (result == EOF)
		{
			return (EOF);
		}

		str++;
		written++;
	}

	return (written);
}
