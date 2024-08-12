#include "shell.h"

/**
 *
 */

int main(void)
{

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	while (1);
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
		args = parse(line);

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
		free(args);
	}
	free(line);
	return (0);
}
