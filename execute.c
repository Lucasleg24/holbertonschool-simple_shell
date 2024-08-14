#include "shell.h"

/**
 * execute - execute the child process
 * @command: token arguments
 * @envp: environnement variable
 * Return: return void
 */

void execute(char **command, char **envp)
{
	char *actual_command = NULL;
	pid_t pid;
	int status;

	actual_command = get_location(command[0], envp);

	if (actual_command == NULL)
	{
		perror(command[0]);
		free_continue(command);
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
		perror("Shell: fork error");
	else if (pid == 0)
	{
		if (execve(actual_command, command, envp) == -1)
			perror("Shell");
		exit(EXIT_FAILURE);
	} else
		wait(&status);

	free(actual_command);
}
