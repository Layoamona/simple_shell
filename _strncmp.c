#include "shell.h"
/**
 * _strncmp - compares two strings up to n bytes
 *
 * @s1: given string
 * @s2: given string
 * @n: number of bytes to be compared
 *
 * Return: 0 if true, 1 when false
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;
	if (s1 == NULL || s2 == NULL)
		return (1);
	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}

/**
 * _strdup - duplicates given string
 *
 * @str: given string
 *
 * Return: string duplicate
 */
char *_strdup(char *str)
{
	int i, len = 0;
	char *dup = NULL;
	len = _strlen(str);
	dup = malloc(sizeof(char *) * len);
	if (dup == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
