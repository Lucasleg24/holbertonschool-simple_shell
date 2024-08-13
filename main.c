#include "shell.h"

/**
 *
 */

char **parse(char *buffer, const char *str)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL || str == NULL)
		return NULL;

	bufsize = strlen(buffer);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Impossible d'allouer le buffer");
		free(buffer);
		return NULL;
	}
	
	token = strtok(buffer, str);
	for (i = 0;token != NULL; i++)
	{
		commands[i] = malloc(strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Impossible d'allouer le buffer");
			free(commands);
			return NULL;
		}
		strcpy(commands[i], token);
		token = strtok(NULL, str);
	}
	commands[i] = NULL;
	
	return commands;
}

/**
 *
 */

int main(void)
{

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	/*char **args;*/

	while (1)
	{
		printf("$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (feof(stdin))
			{
				free(line);
				exit(0);
			}
			perror("getline");
			free(line);
			exit(1);
		}
		/*args = parse(line);

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(line);
				free(args);
				exit(0);
			}
			execute(args);
		}
		free(args);*/
	}
	free(line);
	return (0);
}
