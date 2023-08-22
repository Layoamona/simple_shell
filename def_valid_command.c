#include "shell.h"

/**
 * def_valid_command - Validate a command against a list of allowed commands.
 *
 * This function checks if a given command is in the list of allowed commands.
 *
 * @command: Pointer to the command to be validated.
 *
 * Return: return 1 if the command is valid, 0 if the command is not valid.
 */

int def_valid_command(const char *command)
{
	int i = 0;
	const char *allowed_commands[] = {
		"ls",
		"cat",
		"mkdir",
		"rmdir",
		/* Add more allowed commands as needed */
		NULL /* End of the list*/
	};

	while (allowed_commands[i] != NULL)
	{
		if (strcmp(command, allowed_commands[i]) == 0)
		{
			return (1); /* Command is valid*/
		}
		i++;
	}
	return (0); /* Command is not valid*/
}
