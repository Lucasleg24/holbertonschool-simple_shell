#include "shell.h"

#define HISTORY_SIZE 100
static char *history[HISTORY_SIZE];
static int history_count;

/**
 * print_history - Display or add order history
 *
 * @command: The command to add, or NULL to display the history
 *
 * Return: Nothing
 */

void print_history(const char *command)
{
	int i;
	size_t len;

	if (command == NULL)
	{
		for (i = 0; i < history_count; i++)
			printf("%d  %s\n", i + 1, history[i]);
	} else
	{
		if (history_count >= HISTORY_SIZE)
		{
			free(history[0]);

			for (i = 1; i < HISTORY_SIZE; i++)
				history[i - 1] = history[i];

			history_count--;
		}

		history[history_count] = strdup(command);
		if (history[history_count] == NULL)
		{
			free_history();
			perror("strdup");
			return;
		}

		len = strlen(history[history_count]);
		if (len > 0 && history[history_count][len - 1] == '\n')
			history[history_count][len - 1] = '\0';

		history_count++;
	}
}

/**
 * free_history - Free the memory allocated for the hystory
 *
 * Return: Nothing
 */

void free_history(void)
{
	int i;

	for (i = 0; i < history_count; i++)
	{
		if (history[i] != NULL)
		{
			free(history[i]);
			history[i] = NULL;
		}
	}

	history_count = 0;
}
