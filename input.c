#include "shell.h"

/**
 * input - copy the standard input
 * @text: string with the line
 * Return: return the string copy
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
		exit(EXIT_FAILURE);

	return (buffer);
}
