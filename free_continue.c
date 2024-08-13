#include "shell.h"

void free_continue(char **command)
{
	size_t i;

	if (command == NULL)
		return;

	for (i = 0; command[i] != NULL; i++)
	{
		free(command[i]);
	}

	free(command);
}
