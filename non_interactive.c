#include "shell.h"

/**
 * non_interactive_mode - Execute the shell in non-interactive mode
 *
 * @envp: The environment variables
 *
 * Return: Nothing
 */

void non_interactive_mode(char **envp)
{
	char *line;
	char **args;
		/*, **commands;*/
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	while (read != -1)
	{
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = parse(line, " \n");
		if (args == NULL)
		{
			perror("parse");
		 	free(line);
			return;
		}

		if (args[0] != NULL)
			process_command(args, envp, line);

		free_continue(args);

		/*
		for (i = 0; commands[i] != NULL; i++)
		{
			args = parse(commands[i], " \t\n");
			if (args == NULL || args[0] == NULL)
			{
				free_continue(args);
				continue;
			}
		}
		

		process_command(args, envp, commands[i]);
		free_continue(args);
		*/
	}

	/*free_continue(commands);*/
	shell_exit(line, args);
}
