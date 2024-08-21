#include "shell.h"

/**
 * main - Main function of the program
 *
 * @argc: Number of arguments
 * @argv: List of arguments
 * @envp: Environnement variable
 *
 * Return: An integer
 */

int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	char **args = NULL;

	(void)argv;
	(void)argc;
	signal(SIGINT, sigint);
	if (!isatty(0))
		non_interactive_mode(envp);
	else
	{
		while (1)
		{
			line = input("$");
			if (line == NULL)
				break;

			if (strlen(line) == 0)
			{
				free(line);
				continue;
			}

			args = parse(line, " \n");
			if (args == NULL || args[0] == NULL)
			{
				free(line);
				free_continue(args);
				continue;
			}
			if (args != NULL && args[0] != NULL)
				process_command(args, envp, line);

			free_continue(args);
			free(line);
		}
	}
	shell_exit(line, args);
	return (0);
}
