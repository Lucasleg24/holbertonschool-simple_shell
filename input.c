#include "shell.h"

/**
 * input - Stores user input
 *
 * @text: The user input
 *
 * Return: The address where the user input is stored
 */

char *input(const char *text)
{
	char *buffer = NULL;
	size_t len = 0;

	if (isatty(0))
	{
		printf("%s ", text);
		fflush(stdout);
	}

	if (getline(&buffer, &len, stdin) == -1)
	{
		free(buffer);
		free_history();
		exit(EXIT_FAILURE);
	}

	return (buffer);
}
