#include "shell.h"

/**
 * buildPath - Build the path
 *
 * @envp: Environnement variable
 *
 * Return: The result in string
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
