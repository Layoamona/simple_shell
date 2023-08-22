#include "shell.h"

/**
 * def_current_dir - user defined function to print cwd
 */

void def_current_dir(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("Current directory: %s\n", cwd);
	} else
	{
		perror("getcwd");
	}
}
