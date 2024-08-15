#include "shell.h"

/**
 * buildPath - build the path
 * @envp: environnement variable
 * @path: NULL value for check th true size
 * Return: return the result in string
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
