#include "shell.h"

/**
 * _execme - function that executes the program using an array of token
 * @args: Tokens list to be read and executed.
 */
void _execme(char **args)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == 0)
	{
		/* Specify the full path to the program executable */
		char *program = "/bin/ls";

		/* Use execve instead of execvp */
		execve(program, args, environ);

		/* If execve fails, print an error message */
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
