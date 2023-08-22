#include "shell.h"

/**
 * def_vsnprintf - user defined function for vsnprintf
 * @buffer: size of the stream
 * @buf_size: size of the buf
 * @format: pointer to the string
 * @args: argument
 * Return: returns the result:
 */
int def_vsnprintf(char *buffer, size_t buf_size,
		const char *format, va_list args)
{
	int result;

	if (buffer == NULL || buf_size == 0)
	{
		return (-1);
	}

	result = vsnprintf(buffer, buf_size, format, args);

	if (result < 0 || (size_t)result >= buf_size)
	{
		result = -1;
	}

	return (result);
}
