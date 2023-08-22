#include "shell.h"
void def_fprintf(FILE *stream, const char *format, ...);
/**
 * def_fprintf - user defined function for fprintf
 * @stream: pointer to the stream
 * @format: pointer to formatted string
 */

void def_fprintf(FILE *stream, const char *format, ...)
{
	char *buffer;
	int buffer_size;
	int result;

	va_list args;

	va_start(args, format);

	/* Allocate memory for the buffer dynamically*/
	buffer = NULL;
	buffer_size = def_vsnprintf(NULL, 0, format, args) + 1;
	result = def_vsnprintf(buffer, buffer_size, format, args);

	if (buffer_size <= 0)
	{
		def_fputs("Error: Failed to determine buffer size\n", stream);
		va_end(args);
		return;
	}

	buffer = (char *)malloc(buffer_size);

	if (buffer == NULL)
	{
		def_fputs("Error: Memory allocation failed\n", stream);
		va_end(args);
		return;
	}

	if (result < 0)
	{
		def_fputs("Error: Formatted string too long\n", stream);
	} else
	{
		/* Write the formatted string to the stream*/
		def_fputs(buffer, stream);
	}

	/* Free the dynamically allocated buffer and clean up*/
	free(buffer);
	va_end(args);
}
