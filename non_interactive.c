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
	int process, i;
	char *temp_command[2];

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

			temp_command[0] = commands[i];
			temp_command[1] = NULL;
			if (temp_command != NULL && temp_command[0] != NULL)
			{
				for (i = 0; commands[i] != NULL; i++)
					process = process_command(temp_command, envp, line);
				if (process == -1)
					break;
			}

			free(commands[i]);
		}
		free_continue(commands);
		free(line);
	}
}

