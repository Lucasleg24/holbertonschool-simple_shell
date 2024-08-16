#include "shell.h"

/**
 * print_history - Display or add order history
 *
 * @command: The command to add, or NULL to display the history
 *
 * Return: Nothing
 */

void print_history(const char *command)
{
	int HISTORY_SIZE = 100
	static char *history[HISTORY_SIZE];
	static int history_count;
	int i;

	if (command == NULL)
	{
		for (i = 0; i < history_count; i++)
			printf("%d  %s", i + 1, history[i]);
	} else
	{
		if (history_count < HISTORY_SIZE)
		{
			history[history_count] = strdup(command);
			if (history[history_count] == NULL)
			{
				perror("strdup");
				return;
			}
			history_count++;
		} else
		{
			free(history[0]);
			for (i = 1; i < HISTORY_SIZE; i++)
			{
				history[i - 1] = history[i];
			}
			history[HISTORY_SIZE - 1] = strdup(command);

			if (history[HISTORY_SIZE - 1] == NULL)
			{
				perror("strdup");
				return;
			}
		}
	}
}

/**
 * free_history - Free the memoty allocated for the hystory
 *
 * Return: Nothing
 */

void free_history(void)
{
	static char *history[HISTORY_SIZE];
	static int history_count;
	int i;

	for (i = 0; i < history_count; i++)
	{
		free(history[i]);
		history[i] = NULL;
	}

	history_count = 0;
}
