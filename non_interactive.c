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
	char *line = NULL;
	char **args = NULL, **commands = NULL;
	size_t len = 0, i;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1)
	{

		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		commands = parse(line, " \n");
		if (commands == NULL)
		{
			perror("parse commands");
			continue;
		}

		for (i = 0; commands[i] != NULL; i++)
		{
			args = parse(commands[i], " \t\n");
			if (args == NULL)
			{
				perror("parse args");
				free_continue(commands);
				continue;
			}

			if (args[0] != NULL)
				process_command(args, envp, commands[i]);

			free_continue(args);
		}
		free_continue(commands);
	}
	if (line)
		free(line);
}
