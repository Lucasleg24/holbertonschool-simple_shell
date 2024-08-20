#include "shell.h"

/**
 * parse - Change the string into token
 *
 * @buffer: The buffer
 * @str: The delimiter
 *
 * Return: The tokenized command
 */

char **parse(char *buffer, const char *str)
{
	char *token = NULL, **commands = NULL;
	int i, j, tokenlen = 0;

	if (buffer == NULL || str == NULL)
		return (NULL);

	for (j = 0; buffer[j]; j++)
	{
		if (buffer[j] == *str)
			tokenlen++;
	}
	commands = malloc((tokenlen + 2) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		return (NULL);
	}

	token = strtok(buffer, str);

	if (token == NULL)
	{
		free(commands);
		return (NULL);
	}
	for (i = 0; token != NULL; i++)
	{
		commands[i] = malloc(strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_continue(commands);
			return (NULL);
		}
		strcpy(commands[i], token);
		token = strtok(NULL, str);
	}
	commands[i] = NULL;

	return (commands);
}
