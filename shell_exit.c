#include "shell.h"

/**
 * shell_exit - Function for exiting the shell
 *
 * @line: For free the line
 * @args: For free args
 *
 * Return: Nothing
 */

void shell_exit(char *line, char **args)
{
	free_history();

	if (line != NULL)
		free(line);

	if (args != NULL)
		free_continue(args);

	exit(EXIT_SUCCESS);
}
