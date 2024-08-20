#include "shell.h"

/**
 * process_command - Process and execute the input command
 *
 * @args: An array of arguments
 * @envp: The environment variables
 * @line: The input line containing the command
 *
 * Return: Nothing
 */

int process_command(char **args, char **envp, char *line)
{

	if (strcmp(args[0], "exit") == 0)
	{
		if (isatty(0))
			shell_exit(line, args);
		else
			return (-1);
	}
	else if (strcmp(args[0], "cd") == 0)
		change_dir(args[1]);
	else if (strcmp(args[0], "env") == 0)
		print_env(envp);
	else if (strcmp(args[0], "history") == 0)
		print_history(NULL);
	else
		execute(args, envp);

	return (0);
}
