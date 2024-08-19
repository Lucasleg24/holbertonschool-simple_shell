#include "shell.h"

/**
 * buildPath - Build the path
 *
 * @envp: The environment variables
 *
 * Return: The path or NULL
 */

char *buildPath(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
	}

	return (NULL);
}
