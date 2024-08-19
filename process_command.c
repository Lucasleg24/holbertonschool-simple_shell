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

void process_command(char **args, char **envp, char *line)
{
	if (strcmp(args[0], "exit") == 0)
		shell_exit(line, args);
	else if (strcmp(args[0], "cd") == 0)
	{
		print_history(line);
		change_dir(args[1]);
	} else if (strcmp(args[0], "env") == 0)
	{
		print_history(line);
		print_env(envp);
	} else if (strcmp(args[0], "history") == 0)
	{
		print_history(line);
		print_history(NULL);
	} else
	{
		print_history(line);
		execute(args, envp);
	}
}
