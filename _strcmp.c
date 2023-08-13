#include "shell.h"
/**
 * my_strcmp - function to compare strings
 *@str1: first string
 *@str2: second string
 *Return: Compared strings
 */
int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
