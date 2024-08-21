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
	int in_quote = 0;

	if (buffer == NULL || str == NULL || strlen(buffer) == 0 || buffer[0] == '\n')
		return (NULL);

	for (j = 0; buffer[j]; j++)
	{
		if (buffer[j] == *str && !in_quote)
			tokenlen++;
		else if (buffer[j] == '"')
			in_quote = !in_quote;
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
		free_continue(commands);
		return (NULL);
	}

	for (i = 0; token != NULL; i++)
	{
		if (token[0] == '"' && token[strlen(token) - 1] == '"')
		{
			token[strlen(token) - 1] = '\0';
			token++;
		}
		commands[i] = strdup(token);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate commands[i]");
			free_continue(commands);
			return (NULL);
		}
		token = strtok(NULL, str);
	}
	commands[i] = NULL;

	return (commands);
}
