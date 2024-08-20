#include "shell.h"

/**
 * sigint - Signal handler for SIGINT (Ctrl+C)
 *
 * @sig: The signal number
 *
 * Return: Nothing
 */

void sigint(int sig)
{
	(void)sig;
	printf("\n");
}
