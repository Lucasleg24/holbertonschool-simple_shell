#include "shell.h"

extern int exit_status;

/**
 * execute - Executes the command in a child process
 *
 * @command: The command
 * @envp: The environment variables
 *
 * Return: Nothing
 */

void execute(char **command, char **envp)
{
	char *actual_command = NULL;
	pid_t pid;
	int status = 0;

	if (command[0][0] == '/')
		actual_command = command[0];
	else
		actual_command = get_location(command[0], envp);

	if (actual_command == NULL)
	{
		perror("./hsh");
		return;
	}

	pid = fork();

	check_pid(actual_command, command, status, pid, envp);
}

/**
 * check_pid - function for return value exit
 * actual_command: the command actual
 * @command: The command
 * status: value of status
 * pid: value of process
 * @envp: The environment variables
 *
 * Return:
 */

void check_pid( char *actual_command, char **command,int status, pid_t pid, char **envp)
{

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
		{
			perror("Shell");
			free(actual_command);
			free_history();
			exit(EXIT_FAILURE);
		} else
			waitpid(pid, &status, 0);
	} else
	{
		wait(&status);

		if (WIFEXITED(status) == 1)
			exit_value = WEXITSTATUS(status);
	}

	if (actual_command != command[0])
		free(actual_command);

	return;
}
