#include "shell.h"

/**
 * main - function main for start the programme
 * @argc: number of arguments
 * @argv: list of arguments
 * @envp: environnement variable
 * Return: return a integer
 */

int main(int argc, char **argv, char **envp)
{

	char *line;
	char **args;

	(void)argc;
	(void)argv;

	while (1)
	{
		line = input("$");
		if (line == NULL)
		{
			printf("\n");
			break;
		}

		args = parse(line, " \n");

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(line);
				free_continue(args);
				exit(0);
			}
			else if (strcmp(args[0], "cd") == 0)
				change_dir(args[1]);
			else
				execute(args, envp);
		}
		free_continue(args);
		free(line);
	}

	return (0);
}
