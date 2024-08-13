#include "shell.h"

/**
 *
 */

char **parse(char *buffer, const char *str)
{
	char *token = NULL, **commands = NULL;
	int i = 0, j, tokenlen;

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
		free(buffer);
		return (NULL);
	}

	token = strtok(buffer, str);
	for (i = 0; token != NULL; i++)
	{
		commands[i] = malloc(strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Impossible d'allouer le buffer");
			free(commands);
			return (NULL);
		}
		strcpy(commands[i], token);
		token = strtok(NULL, str);
	}
	commands[i] = NULL;

	return (commands);
}

/**
 *
 */

int main(int argc, char **argv, char **envp)
{
	char *line;
	char **args;

	(void)argc;
	(void)argv;

	/* La boucle while sert a ne pas sortir aprés du shell aprés un execut*/
	while (1)
	{

		line = input("$");
		if (line == NULL)
		{
			printf("\n");
			break;
		}

		args = parse(line, " \n");

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(line);
				free(args);
				exit(0);
			}
			execute(args, envp);
		}

		free(args);
		free(line);
	}

	return (0);
}

/**
 *
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
