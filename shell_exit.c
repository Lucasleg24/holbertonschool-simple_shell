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
        free(line);
        free_continue(args);
        exit(0);
}
