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
	signal(SIGINT, sigint);

	while (1)
	{
		line = input("$");
		if (line == NULL)
			break;
		args = parse(line, " \n");
		if (args == NULL)
		{
			perror("parse");
			free(line);
			continue;
		}
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
				shell_exit(line, args);
			else if (strcmp(args[0], "cd") == 0)
				change_dir(args[1]);
			else if (strcmp(args[0], "env") == 0)
				print_env(envp);
			else if (strcmp(args[0], "history") == 0)
				print_history(NULL);
			else
			{
				print_history(line);
				execute(args, envp);
			}
		}
		free_continue(args);
		free(line);
	}
	shell_exit(line, args);
	return (0);
}
