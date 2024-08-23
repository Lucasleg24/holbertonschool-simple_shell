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
	char **commands = NULL;
	size_t len = 0;
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

		if (process_command(commands, envp, line) == -1)
		{
			free_continue(commands);
			break;
		}

		free_continue(commands);
		free(line);
		line = NULL;
	}
	free(line);
}
