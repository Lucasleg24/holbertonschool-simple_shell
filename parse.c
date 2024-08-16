#include "shell.h"

/**
 * parse - change in token the string
 * @buffer: buffer with the string
 * @str: delimitor for create token
 * Return: return a pointer in pointer
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
	commands = malloc((tokenlen + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Impossible d'allouer le buffer");
		return (NULL);
	}

	token = strtok(buffer, str);
	for (i = 0; token != NULL; i++)
	{
		commands[i] = malloc(strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Impossible d'allouer le buffer");
			free_continue(commands);
			return (NULL);
		}
		strcpy(commands[i], token);
		token = strtok(NULL, str);
	}
	commands[i] = NULL;

	return (commands);
}
