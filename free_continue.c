#include "shell.h"

void free_continue(char **command)
{
	if (command == NULL)
		return;

	for (size_t i = 0; command[i] != NULL; i++)
	{
		free(command[i]);
	}

	free(command);
}
