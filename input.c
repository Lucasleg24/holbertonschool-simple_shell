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
	ssize_t read;

	if (isatty(0))
	{
		printf("%s ", text);
		fflush(stdout);
	}

	read = getline(&buffer, &len, stdin);

	if (read == -1)
	{
		perror("banane");
		free(buffer);
		free_history();
		exit(EXIT_FAILURE);
	}

	return (buffer);
}
