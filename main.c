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
	char *line;
	char **args;

	(void)argc;
	(void)argv;
	signal(SIGINT, sigint);

	while (1)
	{
		line = input("$");
		if (line == NULL)
		{
			shell_exit(line, args);
			break;
		}

		args = parse(line, " \n");
		if (args == NULL)
		{
			perror("parse");
			free(line);
			continue;
		}

		if (args[0] != NULL)
			process_command(args, envp, line);

		free_continue(args);
		free(line);
	}

	shell_exit(line, args);
	return (0);
}
