#include "shell.h"

/**
 * _exec - function that executes the program using an array of token
 * @args: Tokens list to be read and executed.
 */

void _exec(char **args)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("error");
		exit(1);
	}
	else if (child_pid > 0)
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("error");
	}
}
