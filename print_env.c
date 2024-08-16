#include "shell.h"

/**
 * print_env - Function that print the environnement variable
 *
 * @env: environnement variable
 *
 * Return: Nothing
 */

void print_env(char **env)
{
	int i, len = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		len = strlen(env[i]);

		if (write(1, env[i], len))
		{
			perror("write");
			return;
		}

		write(1, "\n", 1);
	}
}
