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

	if (command[0][0] == '/')
		actual_command = command[0];
	else
		actual_command = get_location(command[0], envp);

	if (actual_command == NULL)
	{
		perror(command[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Shell: fork error");
		if (actual_command != command[0])
			free(actual_command);
		return;
	}
	else if (pid == 0)
	{
		if (execve(actual_command, command, envp) == -1)
			perror("Shell");
		free(actual_command);
		exit(EXIT_FAILURE);
	} else
		wait(&status);

	if (actual_command != command[0])
		free(actual_command);
}
